#ifndef CONTROLLABLEOBJ_H
#define CONTROLLABLEOBJ_H

#include "Objects.h"
#include <vector>

class ControllableObj : public Objects
{
	Q_OBJECT

	std::vector<float> Velocity(3);
	std::vector<float> Force(3);
	float AccForce;
	float BreakForce;
	float Mass;

public:
	//Methods
	void SetVelocity(const std::vector<float>& v);
	const std::vector<float>& GetVelocity();
	void SetForce(const std::vector<float>& f);
	const std::vector<float>& GetForce();
	void SetAccForce(const float accForce);
	//const float GetAccForce();
	void SetBreakForce(const float breakForce);
	//const float GetBreakForce();
	const float GetMass();

	//Virtual overrides
	void SetCoordinates(const std::vector<float>& c);
	void SetOrientation(const std::vector<float>& o);

	//virtual Methods
	virtual void Accelarate(const float strength) const = 0;
	virtual void Brake(const float strength) const = 0;
	virtual void Turn(const float direction) const = 0;
	virtual void Update(const float dt) const = 0;

	//Constructors
	//Standardconstructor should only be used for testing
	ControllableObj(QObject* parent); // = delete;
	ControllableObj(QObject* parent, std::vector<float>& coordinates, std::vector<float>& orientation);
	~ControllableObj();
};

#endif