#include "Objects.h"
#include <vector>

//Methods
const std::vector<float>& Objects::GetCoordinates(){
	return coordinates;
}

//Constructor
Objects::Objects(QObject* parent) 
	: QObject(parent){}

Objects::Objects(QObject* parent, std::vector<float>& c)
	: QObject(parent){
	for (auto i = 0; i < c.size(); i++) {
		coordinates[i] = c[i];
	}

	//for (auto i = 0; i < a.size(); i++) {
	//	angles[i] = a[i];
	//}
}

Objects::~Objects(){}
};


