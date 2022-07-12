#ifndef CAR_H
#define CAR_H
#include "ControllableObj.h"
#include <vector>

class Car : public ControllableObj
{
	float WheelAngle;					//Pos of adjustable wheels -45 to 45 degree
	float WheelBase;
	const float PI{ 3,1415 };

public:
	//Methoden
	//redundant to Turn?
	void SetWheelAngle(const float);
	
	const float GetWheelAngle();
	const float GetWheelBase();

	//override Methoden		
	virtual void Accelarate(const float strength) override;
	virtual void Brake(const float strength) override;
	virtual void Turn(const float direction) override;
	virtual void Update(const float) override;

	//Constructor
	//Standardconstructor should only be used for testing
	Car(QObject* parent); // = delete;
	Car(QObject* parent, std::vector<float>& coordinates, std::vector<float>& orientation, const float wheelbase);
	~Car();
};


#endif // !CAR
