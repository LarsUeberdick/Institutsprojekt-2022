#include "ObjManager.h"


void ObjManager::AddObj(Objects* object)
{
	ObjList.push_back(object);
}

void ObjManager::RemoveObj(Objects* object)
{
	if (!object) return;
	auto i = std::find(ObjList.begin(), ObjList.end(), object);
	if (i == ObjList.end()) return;
	//Dekonstruktor aufrufen?
	ObjList.erase(i);
}

void ObjManager::Step(float dt)
{
	for (ControllableObj* cObj : ObjList) {
		cObj->SetForce(cObj->GetForce() + cObj->GetMass() * gravity);

		cObj->SetVelocity(cObj->GetVelocity() + cObj->GetForce() / cObj->GetMass() * dt);

		cObj->UpdatePosFacing(dt);

		//Need new function UpdateForce
		//cObj->SetForce(std::vector<float>(0, 0, 0));
	}
}

ObjManager::ObjManager(QObject *parent)
	: QObject(parent)
{
}

ObjManager::~ObjManager()
{
}
