#ifndef OBJMANAGER_H
#define OBJMANAGER_H

#include <QObject>
#include <vector>
#include "Objects.h"
#include "ControllableObj.h"

class ObjManager : public QObject
{
	Q_OBJECT
	std::vector<Objects*> ObjList;
	std::vector<float> gravity {0, -9.81, 0}

public:
	void AddObj(Objects* object);
	void RemoveObj(Objects* object);

	void Step(float dt);

	ObjManager(QObject *parent);
	~ObjManager();
};

#endif