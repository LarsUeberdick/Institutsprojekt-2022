#ifndef CONTROLLABLEOBJ_H
#define CONTROLLABLEOBJ_H

#include "Objects.h"
#include <vector>

class ControllableObj : public Objects
{
	Q_OBJECT

	std::vector<float> Velocity(3);
	std::vector<float> Force(3);
	float Mass;

public:
	//Methods
	void SetCoordinates(const std::vector<float>& c);
	void SetVelocity(const std::vector<float>& v);
	std::vector<float>& GetVelocity();

	void SetForce(const std::vector<float>& f);
	std::vector<float> GetForce();
	const float GetMass();

	virtual void Accelarate(float) const = 0;
	virtual void Brake() const = 0;
	virtual void Turn(float) const = 0;
	virtual void UpdatePosFacing(float) const = 0;

	//Constructors
	//Standardconstructor should only be used for testing
	ControllableObj(QObject* parent); // = delete;
	ControllableObj(QObject* parent, std::vector<float> c, std::vector<float> f);
	~ControllableObj();
};

#endif