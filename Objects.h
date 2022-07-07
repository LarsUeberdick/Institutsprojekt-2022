#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>
#include <vector>

class Objects : public QObject
{
	Q_OBJECT

	std::vector<int> coordinates(3);
	//std::vector<int> angles(3);
	float mass;
	

public:
	//Methods
	const std::vector<int>& GetCoordinates();
	//const std::vector<int>& GetAngles();
	const float GetMass();

	//Constructor
	//Only for text cases; should not be in final itteration
	Objects(QObject*);

	Objects(QObject*, std::vector<int> c) //, std::vector<int> a
	~Objects();
};

#endif