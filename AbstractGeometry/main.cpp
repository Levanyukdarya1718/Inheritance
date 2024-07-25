//AbstractGeometry
#define _USE_MATH_DEFINES
#include<Windows.h>
#include <iostream>
using namespace std;
namespace Geometry
{
	enum Color
	{
		RED = 0x000000FF,
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000,
		YELLOW = 0x0000FFFF,
		CONSOLE_RED = 0xcc,//старшая 'C' -Цвет фона, младшая 'C' -цвет текста
		CONSODE_GREN = 0xAA,
		CONSOLE_BLUE = 0x99,
		CONSOLE_DEFAULT = 0x07
	};
#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int  line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color
	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int  line_width;
		Color color;
		static const int MIN_START_X = 100;
		static const int MIN_START_Y = 50;
		static const int MAX_START_X = 1000;
		static const int MAX_START_Y = 500;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 32;
		static const int MIN_SIZE = 20;
		static const int MAX_SIZE = 800;
		static int count;
	public:
		//Чисто виртуальные функции (ЗPure virtual function)
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		/*Shape(Color color) :color(color) {}*/
		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
			count++;
		}
		virtual ~Shape()
		{
			count--;
		}
		int get_count()const
		{
			return count;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x < 100)start_x = 1000;
			if (start_x > 1000)start_x = 1000;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y < 50)start_y = 50;
			if (start_y > 1000)start_y = 500;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			this->line_width =
				line_width < MIN_LINE_WIDTH ? MIN_LINE_WIDTH :
				line_width> MAX_LINE_WIDTH ? MAX_LINE_WIDTH : line_width;
		}
		int filter_size(int size)const
		{
			return
				size<MIN_SIZE ? MIN_SIZE :
				size>MAX_SIZE ? MAX_SIZE :
				size;
		}
		/*void set_line_width(unsigned int line_width)
		{
			if (line_width < 10)line_width = 10;
			if (line_width > 100)line_width = 100;
			this->line_width = line_width;
		}
		*/
		virtual void info() const

		{
			cout << "Площадь фигуры:" << get_area() << endl;
			cout << "Периметр фигуры:" << get_perimeter() << endl;
			draw();
		}
	};
	int Shape::count = 0;
	/*class Square : public Shape

	{
		double side;
	public:
		Square(double side, Color color) :Shape(color)
		{
			this->side = side;
		}
		~Square() {}
		void set_side(double side)
		{
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter() const override
		{
			return side * 4;
		}
		void draw() const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "*";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны:" << get_side() << endl;
			Shape::info();
		}
	};*/
	class Rectangle : public Shape
	{
		double width;//ширина прямоугольника
		double height;//высота прямоугольника
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}
		void set_width(double width)
		{

			this->width = filter_size(width);
		}
		void set_height(double height)
		{
			this->height = height;
		}
		double get_width()const
		{
			return filter_size(width);
		}
		double get_height()const
		{
			return height;
		}
		double get_area()const override
		{
			return width * height;

		}
		double get_perimeter()const override
		{
			return (width + height) * 2;
		}
		void draw()const override
		{
			//WinGPI-Windows Graphics Device Interface
			// 1) получаем окно консоли
			//HWND hwnd = GetConsoleWindow();//функеция GetConsoleWindow получает окно консоли
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			//2) Для того чтобы рисовать, нужен контекст устройства (Device Context),
			//который есть у каждого окна. Контекст устройства можно получить про помощи функции GetDC()
			HDC hdc = GetDC(hwnd); //получаем контекст откна консоли
			//Контекст устройства - это то, на чем мы будем рисовать.

			//3) теперь нам нужно то, чем мы будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, color); //hPen -рисует контур фигуры
			//SP_SOID -СПЛОШНАЯ ЛИНИЯ
			//5-толщина линии 5 пикскелей
			HBRUSH hBrash = CreateSolidBrush(color); //hBrush -рисует заливку фигуры 
			//4) Выбираем чем, и на чем будем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrash);
			//5) рисуем фигуру:
			::Rectangle(hdc, start_x, start_y,start_x+width, start_y+height);//::Global Scope(глобальное простраство имен)
			//6) hdc, hPen и hBrush -занимают ресурсы и после того как мы ими воспоьзовались ресурсынужно освободить
			DeleteObject(hBrash);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);


		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника:" << get_width() << endl;
			cout << "Высота прямоугольника:" << get_height() << endl;
			Shape::info();
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
	class Circle : public Shape
	{
		double radius;
	public:
		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		~Circle() {}
		void set_radius(double radius)
		{

			this->radius = filter_size(radius);

		}
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return 2 * radius;
		}
		//typename name (parametrs)modifiers
		double get_area()const
		{
			return M_PI * radius * radius;
		}
		double get_perimeter()const override
		{
			return M_PI * get_diameter();
		}
		void draw()const override
		{
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			// Очищаем ресурсы: 
			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Disc radius:  " << get_radius() << endl;
			cout << "Disc diameter:" << get_diameter() << endl;
			Shape::info();
		}
	};

}
void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_RED);
	Geometry::Square square(50, 100, 100, 5, Geometry::Color::RED);
	/*cout << "Длина стороны:" << square.get_side() << endl;
	cout << "Площадь квадрата:" << square.get_area() << endl;
	cout << "Периметр квадрата:" << square.get_perimeter() << endl;
	square.draw();*/
	square.info();
	Geometry::Rectangle rect(500, 300, 200, 100, 10, Geometry::Color::BLUE);
	rect.info();
	Geometry::Circle disk(10, 500, 100, 5, Geometry::Color::YELLOW);
	disk.info();

	cout << "Количество фигур: " << disk.get_count() << endl;
}