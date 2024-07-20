#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;



//#define WRETE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRETE_TO_FILE


	cout << "Hello Files" << endl;
	std::ofstream fout;			//1)Создаем поток 
	fout.open("File.txt",std::ios_base::app);	    //2)Открываем поток
								//При открытии потока мы указываем 
								//какой именно файл мы будем писать
	//std ::ios_base::app (append) - дописывать в конец файла
	fout << "Hello Files" << endl;//3)Пишем поток 
	fout << "Привет" << endl;
	fout.close();				 //4)Закрываем поток
								//Потоки обязательно нужно закрывать если не закрывать поотоки это может
								//привести к непредвиденным последствиям
								//(Behaviour  is undefined
	system("notepad File.txt"); #endif // DEBUG
#endif // WRETE_TO_FILE
		std::ifstream fin("File.txt"); //1)Создание и открытие потока можно совместить 
	if (fin.is_open()) //2)при чтении обязательно нуцжно проверять, открылся поток или нет.
	{
		//TODO: read from file
		//3)Чтение из файла
		while (!fin.eof())//Пока не конец файла (End of file) читаем поток
		{
			const int SIZE = 402883;
			char buffer[SIZE]{};
			/*fin >> buffer;*/
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close(); //4) Поток есть смысл закрывать поток в том случае если оне открыт
		
	}
	else
	{
	std::cerr << "Error file not found" << endl;
	}

}