#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>
#include <vector>

class Objects : public QObject
{
	Q_OBJECT

protected:
	//ControllableObj should have access to protected but it appears like it does not
	//ControllableObj SetCoordinates and SetOrientation �berarbeiten
	std::vector<float> Coordinates(3);
	std::vector<float> Orientation(2); //theta, phi
	//collider; definiert r�umliche Ausdehnung, Liste, da Elemente konvex sein m�ssen

public:
	//Methods
	const std::vector<float>& GetCoordinates();
	const std::vector<float>& GetOrientation();

	//Constructor
	//Only for test cases; should not be in final itteration
	Objects(QObject*);
	Objects(QObject* parent, std::vector<float>& coordinates, std::vector<float>& orientation);
	~Objects();
};

#endif