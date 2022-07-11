#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>
#include <vector>

class Objects : public QObject
{
	Q_OBJECT

	std::vector<float> Coordinates(3);
	std::vector<float> Facing(2); //theta, phi
	//collider; definiert r�umliche Ausdehnung, Liste, da Elemente konvex sein m�ssen

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