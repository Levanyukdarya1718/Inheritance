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
	std::ofstream fout;			//1)������� ����� 
	fout.open("File.txt",std::ios_base::app);	    //2)��������� �����
								//��� �������� ������ �� ��������� 
								//����� ������ ���� �� ����� ������
	//std ::ios_base::app (append) - ���������� � ����� �����
	fout << "Hello Files" << endl;//3)����� ����� 
	fout << "������" << endl;
	fout.close();				 //4)��������� �����
								//������ ����������� ����� ��������� ���� �� ��������� ������� ��� �����
								//�������� � �������������� ������������
								//(Behaviour  is undefined
	system("notepad File.txt"); #endif // DEBUG
#endif // WRETE_TO_FILE
		std::ifstream fin("File.txt"); //1)�������� � �������� ������ ����� ���������� 
	if (fin.is_open()) //2)��� ������ ����������� ������ ���������, �������� ����� ��� ���.
	{
		//TODO: read from file
		//3)������ �� �����
		while (!fin.eof())//���� �� ����� ����� (End of file) ������ �����
		{
			const int SIZE = 402883;
			char buffer[SIZE]{};
			/*fin >> buffer;*/
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close(); //4) ����� ���� ����� ��������� ����� � ��� ������ ���� ��� ������
		
	}
	else
	{
	std::cerr << "Error file not found" << endl;
	}

}