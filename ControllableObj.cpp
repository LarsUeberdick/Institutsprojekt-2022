#include "ControllableObj.h"

//Methods
void ControllableObj::SetCoordinates(std::vector<int>& c) {
	for (auto i = 0; i < c.size(); i++) {
		coordinates[i] = c[i];
	}
}

void ControllableObj::SetVelocity(const std::vector<int>& v) {
	for (auto i = 0; i < v.size(); i++) {
		velocity[i] = v[i];
	}
}

std::vector<int>& ControllableObj::GetVelocity() {
	return velocity;
}

void ControllableObj::SetForce(const std::vector<int>& f)
{
	for (auto i = 0, i < f.size(), i++) {
		force[i] = f[i];
	}
}

std::vector<int> ControllableObj::GetForce()
{
	return force;
}
	
//Constructor
ControllableObj::ControllableObj(QObject *parent) : Objects(parent){}

ControllableObj::ControllableObj(QObject* parent, std::vector<int> c)
	:Objects(*parent, c)
{
}
	
ControllableObj::~ControllableObj(){}
};



