#include "Car.h"
#include <vector>
#include <cmath>


void Car::SetWheelAngle(float direction)
{
	if !(direction <= -45 || direction >= 45)
	{
		WheelAngle = direction;
	}
}

const float Car::GetWheelAngle()
{
	return WheelAngle;
}

const float Car::GetWheelBase()
{
	return WheelBase;
}

void Car::Accelarate(const float strength)
{
	SetBreakForce = strength;
}

void Car::Brake(const float strength)
{
	SetAccForce = strength;
}

void Car::Turn(const float direction)
{
	WheelAngle = WheelAngle + direction;
}

void Car::Update(const float dt)
{
	float distance = GetVelocity() * dt;

	//edge case
	if (WheelAngle <= 5 && WheelAngle >= -5)
	{
		SetCoordinates(GetCoordinates() + distance);
		return;
	}

	//general case
	/*
		Handle the problem like it was in 2D; works as long as a, b and c are level
		argument of tan(x) may not approach PI/2 or it could result in obliteration

		a: centerpoint of the front axis
		b: centerpoint of the back axis
		c: point of the objects center
		m: burn point of front and back axis
	*/
	float abL = WheelBase;
	float bmL = abL * tan(PI / 180 * (90-WheelAngle));						
	float cbL = WheelBase/2
	float cmL = sqrt(cbL ^ 2 + bmL ^ 2);

	//Angle in radiant the car drove on the edge of the circle
	float polarAngle = cmL / distance;
	
	//(cos(x) - 1), (sin(x)-0) to get difference before timestep and after
	std::vector<float> polarOffsetVec{ cmL * (cos(polarAngle)-1) , cmL * sin(polarAngle) };
	float polarOffsetL = sqrt(polarVec[0] ^ 2 + polarVec[1] ^ 2);

	/*
		sphere coordinates are translation invariant
		the angle disregarded for the calc of the distance vector can be applied afterwards? 
		radius is given as difference, angle is the previous vehicle orientation
	*/
	std::vector<float> orientation = GetOrientation();
	std::vector<float> sphericalOffsetVec
		{
			polarOffsetL * sin(PI / 180 * orientation[0]) * cos(PI / 180 * orientation[1]),
			polarOffsetL * sin(PI / 180 * orientation[0]) * sin(PI / 180 * orientation[1]),
			polarOffsetL * cos(PI / 180 * orientation[0])
		};

	SetCoordinates(GetCoordinates() + sphericalOffsetVec);
	
	if (WheelAngle < 0) //Right turn
	{
		SetOrientation(orientation[0], orientation[1] - polarAngle);
	}
	else //Left turn
	{
		SetOrientation(orientation[0], orientation[1] + polarAngle);
	}
}

//Constructor
//Standardconstructor should only be used for testing
Car::Car(QObject* parent) : ControllableObj(parent) {} // = delete;
Car::Car(QObject* parent, std::vector<float>& coordinates, std::vector<float>& orientation, const float wheelbase) 
	: ControllableObj(parent, coordinates, orientation) {

	FrontWheels[0] = wheelbase / 2 * sin(PI / 180 * orientation[0]) * cos(PI / 180 * orientation[1]);
	FrontWheels[1] = wheelbase / 2 * sin(PI / 180 * orientation[0]) * sin(PI / 180 * orientation[1]);
	FrontWheels[1] = wheelbase / 2 * cos(PI / 180 * orientation[0])

	BackWheels[0] = -wheelbase / 2 * sin(PI / 180 * orientation[0]) * cos(PI / 180 * orientation[1]);
	BackWheels[1] = -wheelbase / 2 * sin(PI / 180 * orientation[0]) * sin(PI / 180 * orientation[1]);
	BackWheels[1] = -wheelbase / 2 * cos(PI / 180 * orientation[0])
}

Car::~Car(){};