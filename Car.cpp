#include "Car.h"
#include <vector>
#include <cmath>


void Car::SetWheelPos(float direction)
{
	if !(direction <= -45 || direction >= 45)
	{
		WheelPos = direction;
	}
}

int Car::GetWheelPos()
{
	return WheelPos;
}

//still needs wheel direction
std::vector<float>& Car::CompCalc()
{	
	std::vector<float> facing(2) = this->GetFacing();
	std::vector<float> components(3);

	components[0] = cos(facing[0]) * sin(facing[1]);	//X-Component
	components[1] = sin(facing[0]) * sin(facing[1]);	//Y-Component
	components[2] = cos(facing[0]);						//Z-Component

	return components;
}

void Car::Accelarate(float strength)
{
	SetForce(GetForce() + strength * CompCalc());
}

void Car::Brake(float strength)
{
	SetForce(GetForce() - strength * CompCalc());
}

void Car::Turn(float direction)
{
	SetWheelPos(GetWheelPos() + direction);
}

void Car::UpdatePosFacing(float dt)
{



}

//Constructor
//Standardconstructor should only be used for testing
Car::Car(QObject* parent) : ControllableObj(parent) {} // = delete;
Car::Car(QObject* parent, std::vector<float> c, std::vector<float> f,
	std::vector<float> fw, std::vector<float> bw) : ControllableObj(parent, c, f) {

	for (auto i = 0; i < c.size(); i++) {
		FrontWheels[i] = fw[i];
	}

	for (auto i = 0; i < a.size(); i++) {
		BackWheels[i] = bw[i];
	}
}

Car::~Car(){};