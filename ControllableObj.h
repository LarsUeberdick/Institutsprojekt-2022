#pragma once

#include "Objects.h"

class ControllableObj : public Objects
{
	Q_OBJECT

public:
	ControllableObj(QObject *parent);
	~ControllableObj();
};
