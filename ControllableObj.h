#ifndef CONTROLLABLEOBJ_H
#define CONTROLLABLEOBJ_H

#include "Objects.h"
#include <vector>

class ControllableObj : public Objects
{
	Q_OBJECT

	std::vector<float> velocity(3);
	std::vector<float> force(3);
	float mass;

public:
	//Methods
	void SetCoordinates(const std::vector<float>& c);
	//void SetAngles(const std::vector<float>& a);
	void SetVelocity(const std::vector<float>& v);
	std::vector<float>& GetVelocity();

	void SetForce(const std::vector<float>& f);
	std::vector<float> GetForce();
	const float GetMass();


	//Constructors
	//Only for test cases; should not be in final itteration
	ControllableObj(QObject* parent);
	ControllableObj(QObject* parent, std::vector<float> c);
	~ControllableObj();
};

#endif