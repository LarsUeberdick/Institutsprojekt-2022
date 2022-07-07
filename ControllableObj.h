#ifndef CONTROLLABLEOBJ_H
#define CONTROLLABLEOBJ_H

#include "Objects.h"
#include <vector>

class ControllableObj : public Objects
{
	Q_OBJECT

	std::vector<int> velocity(3);
	std::vector<int> force(3);

public:
	//Methods
	void SetCoordinates(const std::vector<int>& c);
	//void SetAngles(const std::vector<int>& a);
	void SetVelocity(const std::vector<int>& v);
	std::vector<int>& GetVelocity();

	void SetForce(const std::vector<int>& f);
	std::vector<int> GetForce();


	//Constructors
	//Only for text cases; should not be in final itteration
	ControllableObj(QObject* parent);
	ControllableObj(QObject* parent, std::vector<int> c);
	~ControllableObj();
};

#endif