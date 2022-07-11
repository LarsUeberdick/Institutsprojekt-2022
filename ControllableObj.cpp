#include "ControllableObj.h"

//Methods
void ControllableObj::SetCoordinates(std::vector<float>& c) {
	for (auto i = 0; i < c.size(); i++) {
		Coordinates[i] = c[i];
	}
}

void ControllableObj::SetVelocity(const std::vector<float>& v) {
	for (auto i = 0; i < v.size(); i++) {
		Velocity[i] = v[i];
	}
}

std::vector<int>& ControllableObj::GetVelocity() {
	return Velocity;
}

void ControllableObj::SetForce(const std::vector<float>& f)
{
	for (auto i = 0, i < f.size(), i++) 
	{
		Force[i] = f[i];
	}
}

std::vector<float> ControllableObj::GetForce()
{
	return Force;
}

const float ControllableObj::GetMass()
{
	return Mass;
}
	
//Constructor
//Standardconstructor should only be used for testing
ControllableObj::ControllableObj(QObject *parent) : Objects(parent){} //= delete;

ControllableObj::ControllableObj(QObject *parent, std::vector<float> c, std::vector<float> f)
	:Objects(parent, c, f)
{
}
	
ControllableObj::~ControllableObj(){}



