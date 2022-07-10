#include "ControllableObj.h"

//Methods
void ControllableObj::SetCoordinates(std::vector<float>& c) {
	for (auto i = 0; i < c.size(); i++) {
		coordinates[i] = c[i];
	}
}

void ControllableObj::SetVelocity(const std::vector<float>& v) {
	for (auto i = 0; i < v.size(); i++) {
		velocity[i] = v[i];
	}
}

std::vector<int>& ControllableObj::GetVelocity() {
	return velocity;
}

void ControllableObj::SetForce(const std::vector<float>& f)
{
	for (auto i = 0, i < f.size(), i++) {
		force[i] = f[i];
	}
}

std::vector<float> ControllableObj::GetForce()
{
	return force;
}

const float ControllableObj::GetMass()
{
	return mass;
}
	
//Constructor
ControllableObj::ControllableObj(QObject *parent) : Objects(parent){}

ControllableObj::ControllableObj(QObject* parent, std::vector<float> c)
	:Objects(*parent, c)
{
}
	
ControllableObj::~ControllableObj(){}
};



