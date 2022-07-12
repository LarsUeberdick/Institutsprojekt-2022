#include "ControllableObj.h"

//Methods

//missing access rights
void ControllableObj::SetCoordinates(std::vector<float>& c) 
{
	for (auto i = 0; i < c.size(); i++) {
		Coordinates[i] = c[i];
	}
}

//missing access rights
void ControllableObj::SetOrientation(const std::vector<float>& o)
{
	for (auto i = 0; i < c.size(); i++) {
		Orientation[i] = o[i];
	}
}

void ControllableObj::SetVelocity(const std::vector<float>& v) 
{
	for (auto i = 0; i < v.size(); i++) {
		Velocity[i] = v[i];
	}
}

const std::vector<int>& ControllableObj::GetVelocity() 
{
	return Velocity;
}

void ControllableObj::SetForce(const std::vector<float>& f)
{
	for (auto i = 0, i < f.size(), i++) 
	{
		Force[i] = f[i];
	}
}

const std::vector<float>& ControllableObj::GetForce()
{
	std::vector<float> netForce{ 0, 0, 0 };
	if (BreakForce >= Force + AccForce)
	{
		return netForce;
	}
	else
	{
		netForce = Force + AccForce + BreakForce;
		return netForce;
	}
}

void ControllableObj::SetAccForce(float accForce)
{
	AccForce = accForce;
}

/*const float ControllableObj::GetAccForce()
{
	return AccForce;
}
*/

void ControllableObj::SetBreakForce(float breakForce)
{
	BreakForce = breakForce;
}

/*const float ControllableObj::GetBreakForce()
{
	return BreakForce;
}
*/

const float ControllableObj::GetMass()
{
	return Mass;
}
	
//Constructor
//Standardconstructor should only be used for testing
ControllableObj::ControllableObj(QObject *parent) : Objects(parent){} //= delete;

ControllableObj::ControllableObj(QObject *parent, std::vector<float>& coordinates, std::vector<float>& orientation)
	:Objects(parent, coordinates, orientation)
{
}
	
ControllableObj::~ControllableObj(){}



