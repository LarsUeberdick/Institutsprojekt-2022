#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>
#include <vector>

class Objects : public QObject
{
	Q_OBJECT

	std::vector<float> coordinates(3);
	//std::vector<float> angles(3);	

public:
	//Methods
	const std::vector<float>& GetCoordinates();
	//const std::vector<float>& GetAngles();

	//Constructor
	//Only for text cases; should not be in final itteration
	Objects(QObject*);

	Objects(QObject*, std::vector<float> c) //, std::vector<float> a
	~Objects();
};

#endif