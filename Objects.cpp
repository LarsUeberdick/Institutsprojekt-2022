#include "Objects.h"
#include <vector>

//Methods
const std::vector<float>& Objects::GetCoordinates(){
	return Coordinates;
}

const std::vector<float>& Objects::GetOrientation()
{
	return Orientation;
}

//Constructor
Objects::Objects(QObject* parent) 
	: QObject(parent){}

Objects::Objects(QObject* parent, std::vector<float>& coordinates, std::vector<float>& orientation = (0, 90))
	: QObject(parent){
	for (auto i = 0; i < c.size(); i++) {
		Coordinates[i] = coordinates[i];
	}

	for (auto i = 0; i < a.size(); i++) {
		Orientation[i] = orientation[i];
	}
}

Objects::~Objects(){}
};


