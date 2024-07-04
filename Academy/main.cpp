#include <iostream>
#include<string>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS  last_name, first_name, age

class Human
{
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

	//			Constructor:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HConstructor:\t" << this << endl;
	}
	//		Methods
	void print()const

	{
		cout << last_name << " " << first_name << " " << age<<" " << endl;
	}
};
#define STUDET_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDET_GIVE_PARAMETERS  speciality,  group,  rating,  attendance
class Student :public Human
{
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
	//Constructors
	Student(HUMAN_TAKE_PARAMETERS,STUDET_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
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
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};
#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS  speciality, experience
class Teacher :public Human
{
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
	//		Constructors
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//		Methods
	void print()const
	{
		Human::print();
			cout << speciality << " " << experience << "years" << endl;
	}
};
#define GRADUATE_TAKE_PARAMETERS 	const std::string& NameGraduateWork, const std::string&  objectResearch
#define GRADUATE_GIVE_PARAMETERS 	 NameGraduateWork,  objectResearch

class Graduate :  public Student 
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
	Graduate(HUMAN_TAKE_PARAMETERS, STUDET_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS)
		: Student(HUMAN_GIVE_PARAMETERS, STUDET_GIVE_PARAMETERS)
	{
			set_NameGraduateWork(NameGraduateWork);
			set_objectResearch(objectResearch);
			cout << "GConstructor:\t" << this << endl;
	}
		~Graduate()
		{
		cout << "GDestructor:\t" << this << endl;
		}
		// 		Metods
	void print() const
	{
			Student::print();

			cout << NameGraduateWork << " " << objectResearch  << endl;
	}
};



void main()
{
	setlocale(LC_ALL, "");
	cout << "HelloAcademy" << endl;
	Human human("Richter", "Jeffrey", 40);
	human.print();
	Student studetn("Pinkman", "Jessie", 20, "Chimstory", "WW_220",95,90);
	studetn.print();
	Teacher teacher("White", "Walter", 50, "Chimistry", 25);
	teacher.print();

	Graduate graduate("Arkhipov", "Denis",25, "automation", "ATPbz-321", 98,95,  " automated system turbine liquefier", "oxygen station");
	graduate.print();


}