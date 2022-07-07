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

public:
	void AddObj(Objects* object);
	void RemoveObj(Objects* object);

	ObjManager(QObject *parent);
	~ObjManager();
};

#endif