#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>
#include <vector>

class Objects : public QObject
{
	Q_OBJECT

	std::vector<float> Coordinates(3);
	std::vector<float> Facing(2); //theta, phi
	//collider; definiert räumliche Ausdehnung, Liste, da Elemente konvex sein müssen

public:
	//Methods
	const std::vector<float>& GetCoordinates();
	const std::vector<float>& GetFacing();

	//Constructor
	//Only for test cases; should not be in final itteration
	Objects(QObject*);
	Objects(QObject* parent, std::vector<float> c, std::vector<float> f);
	~Objects();
};

#endif