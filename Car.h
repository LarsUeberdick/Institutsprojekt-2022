#ifndef CAR_H
#define CAR_H
#include "ControllableObj.h"
#include <vector>

class Car : public ControllableObj
{
	float WheelPos;						//Pos of adjustable wheels -45 to 45 degree
	std::vector<float> FrontWheels;		//Coordinates relativ to Obj Pos
	std::vector<float> BackWheels;		//Coordinates relativ to Obj Pos
public:

	//Methoden
	void SetWheelPos(const float);
	int GetWheelPos();
	std::vector<float>& CompCalc();
	virtual void Accelarate(const float) override;
	virtual void Brake(const float) override;
	virtual void Turn(float) override;
	virtual void UpdatePosFacing(float) override;

	//Constructor
	//Standardconstructor should only be used for testing
	Car(QObject* parent); // = delete;
	Car(QObject* parent, std::vector<float> c, std::vector<float> f, std::vector<float> fw, std::vector<float> bw);
	~Car();
};


#endif // !CAR
