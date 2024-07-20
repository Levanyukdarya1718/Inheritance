
#include<iostream>
#include<fstream>
#include<string>	
#include<string.h>	
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	static const int TYPE_WIDTH = 12;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//				Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	virtual std::ostream& print(std::ostream& os)const
	{
		//os << strchr(typeid(*this).name(), ' ') + 1 << ":\t";	
												
		return os << last_name << " " << first_name << " " << age;
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(TYPE_WIDTH);	
		ofs << std::left;	
		ofs << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";	

		ofs.width(LAST_NAME_WIDTH);
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << first_name;
		ofs.width(AGE_WIDTH);
		ofs << age;
		return ofs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student : public Human
{
	const static int SPECIALITY_WIDTH = 25;
	const static int GROUP_WIDTH = 8;
	const static int RATING_WIDTH = 8;
	const static int ATTENDANCE_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//				Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//				Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(GROUP_WIDTH);
		ofs << group;
		ofs.width(RATING_WIDTH);
		ofs << rating;
		ofs.width(ATTENDANCE_WIDTH);
		ofs << attendance;
		return ofs;
	}

};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience
class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 5;
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	//					Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//					Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << " " << speciality << " " << experience << " years";
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;
		return ofs;
	}

};
#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject
class Graduate :public Student
{
	std::string NameGraduateWork;
	std::string objectResearch;
public:
		const std::string& get_NameGraduateWork()const
		{
			return NameGraduateWork;
		}
		const std::string& get_objectResearch()const
		{
			return objectResearch;
		}
		void set_NameGraduateWork(const std::string& NameGraduateWork)
		{
			this->NameGraduateWork = NameGraduateWork;
		}
		void set_objectResearch(const std::string& objectResearch)
		{
			this->objectResearch = objectResearch;
		}
		// 		Constructor 
		Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
			: Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
		{
			set_NameGraduateWork(NameGraduateWork);
			set_objectResearch(objectResearch);
			cout << "GConstructor:\t" << this << endl;
		}
		Graduate(const Student& student, const std::string& NameGraduateWork, const std::string objectResearch) :
			Student(student)
		{
	
			set_NameGraduateWork(NameGraduateWork);
			set_objectResearch(objectResearch);
			cout << "GConstructor:\t" << this << endl;
		}
		~Graduate()
		{
			cout << "GDestructor:\t" << this << endl;
		}

	//					Methods:
	
	
	std::ostream& print(std::ostream& os)const override
	{
		return Student::print(os) << NameGraduateWork << " " << objectResearch;
	}
};
void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		if(group[i]) cout << *group[i] << endl;
		cout << delimiter << endl;
	}
	cout << "Количество человек в группе" << n << endl;
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
		fout << delimiter << endl;
	}
	fout.close();
	std::string cmd = "notepad" + filename;
	system(cmd.c_str()); //Функция system(const char*) выполняет любую доступную команду операционной системы
							//Метод c_str() djpdhfoftn С-ыекштп(NULL Terminated Line), обвернутый в объект класса std::string

}
Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human:") human = new Human(" ", "", 0);
	if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
	if(type=="Student:")human = new Student("","",0,"")
}
Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		
		n = 0;
		while (!fin.eof())
		{
			std::string buffer;
			
			std::getline(fin, buffer);	
			
			if (
				buffer.find("Human:") == std::string::npos &&
				buffer.find("Student:") == std::string::npos &&
				buffer.find("Teacher:") == std::string::npos &&
				buffer.find("Graduate:") == std::string::npos
				)continue;
			n++;
		}
		cout << "Количество записей в файле: " << n << endl;

		group = new Human * [n] {};

		
		cout << "Позиция курсора на чтение: "  << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Позиция курсора на чтение: "  << fin.tellg() << endl;

		for (int i = 0; !fin.eof(); i++)
		{
			std::string type;
			fin >> type;
			group[i]=HumanFactory
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	return group;
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}

//#define INHERITANCE
//#define SAVE_CHECK
#define LOAD_CHECK

void main()
{
	setlocale(LC_ALL, "");
	cout << "HelloAcademy" << endl;

#ifdef INHERITANCE
	cout << delimiter << endl;
	Human human("Richter", "Jeffrey", 40);
	human.print();
	cout << delimiter << endl;

	Student student("Pinkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90);
	student.print();
	cout << delimiter << endl;

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();
	cout << delimiter << endl;

	Graduate graduate("Arkhipov", "Denis", 25, "automation", "ATPbz-321", 98, 95, " automated system turbine liquefier", "oxygen station");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERITANCE

#ifdef SAVE_CHECK
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Arkhipov", "Denis", 25, "automation", "ATPbz-321", 98, 95, " automated system turbine liquefier", "oxygen station"),
		new Student("Vercetti", "Tommy", 30, "Theft", "Vice", 97, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20)
	};
	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	Clear(group, sizeof(group) / sizeof(group[0]));
#endif // SAVE_CHECK

	int n = 0;
	Human** group = Load("group.txt", n);
	Print(group, n);
	Clear(group, n);


}