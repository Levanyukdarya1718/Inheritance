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
		CONSOLE_RED = 0xcc,//������� 'C' -���� ����, ������� 'C' -���� ������
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
		//����� ����������� ������� (�Pure virtual function)
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
			cout << "������� ������:" << get_area() << endl;
			cout << "�������� ������:" << get_perimeter() << endl;
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
			cout << "����� �������:" << get_side() << endl;
			Shape::info();
		}
	};*/
	class Rectangle : public Shape
	{
		double width;//������ ��������������
		double height;//������ ��������������
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
			// 1) �������� ���� �������
			//HWND hwnd = GetConsoleWindow();//�������� GetConsoleWindow �������� ���� �������
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			//2) ��� ���� ����� ��������, ����� �������� ���������� (Device Context),
			//������� ���� � ������� ����. �������� ���������� ����� �������� ��� ������ ������� GetDC()
			HDC hdc = GetDC(hwnd); //�������� �������� ����� �������
			//�������� ���������� - ��� ��, �� ��� �� ����� ��������.

			//3) ������ ��� ����� ��, ��� �� ����� ��������
			HPEN hPen = CreatePen(PS_SOLID, 5, color); //hPen -������ ������ ������
			//SP_SOID -�������� �����
			//5-������� ����� 5 ���������
			HBRUSH hBrash = CreateSolidBrush(color); //hBrush -������ ������� ������ 
			//4) �������� ���, � �� ��� ����� ��������:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrash);
			//5) ������ ������:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);//::Global Scope(���������� ����������� ����)
			//6) hdc, hPen � hBrush -�������� ������� � ����� ���� ��� �� ��� �������������� ������������ ����������
			DeleteObject(hBrash);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);


		}
		void info() const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������ ��������������:" << get_width() << endl;
			cout << "������ ��������������:" << get_height() << endl;
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

			// ������� �������: 
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
	class Triangle :public Shape
	{
	public:

		Triangle(SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) {}
		~Triangle() {}
		virtual double get_height()const = 0;
		void info()const override
		{
			cout << "������ ������������: " << get_height() << endl;
			Shape::info();
		}
	};
	class EquilateralTriangle : public Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		void set_side(double side)
		{
			this->side = filter_size(side);
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const override
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area() const override
		{
			return side * get_height() / 2;
		}
		double get_perimeter()const override
		{
			return 3 * side;

		}
		void draw()const override
		{
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};
			::Polygon(hdc, vertices, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "����� �������:" << get_side() << endl;
			Triangle::info();
		}

	};
	class IsoscelesTriangle : public Triangle
	{
		double base;
		double side;
	public:
		IsoscelesTriangle(double base, double side, SHAPE_TAKE_PARAMETERS)
			:Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_base(base);
			set_side(side);
		}
		void set_base(double base)
		{
			this->base = filter_size(base);

		}
		void set_side(double side)
		{
			this->side = filter_size(side);
			if (this->side <= base / 2)this->base * 3 / 5;

		}
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;

		}
		double get_height() const override
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));

		}
		double get_area()const override
		{
			return base * get_height() / 2;

		}
		double get_perimeter() const override
		{
			return base + side * 2;
		}
		void draw()const override
		{
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{start_x, start_y + side},
				{start_x + base, start_y + side},
				{start_x + base / 2, start_y + side - get_height()}
			};
			::Polygon(hdc, vertices, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "��������� ������������:"<<get_base() << endl;
			cout << "������� ������������:" << get_side();
			Triangle::info();
		}
	};
	class RightTriangle :public Triangle
	{
		double side_base;
		double side_height;
	public:
		RightTriangle(double side_base, double side_height, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side_base(side_base);
			set_side_height(side_height);
		}
		~RightTriangle() {}
		double get_side_base()const
		{
			return side_base;
		}
		double get_side_height()const
		{
			return side_height;
		}
		void set_side_base(double side_base)
		{
			this->side_base = filter_size(side_base);
		}
		void set_side_height(double side2)
		{
			this->side_height = filter_size(side_height);
		}
		double get_side()const
		{
			return sqrt(side_base * side_base + side_height * side_height);
		}
		double get_height()const override
		{
			return side_height;
		}
		double get_area()const override
		{
			return side_base * side_height / 2;
		}
		double get_perimeter()const override
		{
			return side_base + side_height + get_side();
		}
		void draw()const override
		{
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT vertex[] =
			{
				{start_x, start_y},
				{start_x, start_y + get_height()},
				{start_x + side_base, start_y + get_height()}
			};

			::Polygon(hdc, vertex, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������� 1:	 " << side_base << endl;
			cout << "������� 2:	 " << side_height << endl;
			cout << "����������: " << get_side() << endl;
			Triangle::info();
		}
	};
}
void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_RED);
	Geometry::Square square(50, 100, 100, 5, Geometry::Color::RED);
	/*cout << "����� �������:" << square.get_side() << endl;
	cout << "������� ��������:" << square.get_area() << endl;
	cout << "�������� ��������:" << square.get_perimeter() << endl;
	square.draw();*/
	square.info();
	Geometry::Rectangle rect(500, 300, 200, 100, 10, Geometry::Color::BLUE);
	rect.info();
	//Geometry::Circle disk(10, 500, 100, 5, Geometry::Color::YELLOW);
	//disk.info();
	Geometry::EquilateralTriangle e_triengle(150, 300, 100, 1, Geometry::Color::GREEN);
	e_triengle.info();
	Geometry::IsoscelesTriangle iso_triangle(200, 100, 500, 200, 20, Geometry::Color::GREEN);
	iso_triangle.info();
	//cout << "���������� �����: " << disk.get_count() << endl;
	Geometry::RightTriangle r_triangle(150, 80, 900, 100, 5, Geometry::Color::GREEN);
	r_triangle.info();
}