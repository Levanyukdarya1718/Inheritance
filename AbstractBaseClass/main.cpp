#include <iostream>
using namespace std;
class Vehicle
{
public:
	virtual void move() = 0;

};
class  GroundVehicle : public Vehicle {};
class Bike : public GroundVehicle {
	void move()override
	{
		cout<<"Harley Davidson едет на двух колесах"<<
	}
};
void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;
	//GroundVehicle gv;
	Bike harley_davidson;
	harley_davidson.move();
}