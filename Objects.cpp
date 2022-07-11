#include "Objects.h"
#include <vector>

//Methods
const std::vector<float>& Objects::GetCoordinates(){
	return Coordinates;
}

const std::vector<float>& Objects::GetFacing()
{
	return Facing;
}

//Constructor
Objects::Objects(QObject* parent) 
	: QObject(parent){}

Objects::Objects(QObject* parent, std::vector<float> c, std::vector<float> f)
	: QObject(parent){
	for (auto i = 0; i < c.size(); i++) {
		Coordinates[i] = c[i];
	}

	for (auto i = 0; i < a.size(); i++) {
		Facing[i] = f[i];
	}
}

Objects::~Objects(){}
};


