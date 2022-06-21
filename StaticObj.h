#pragma once

#include "Objects.h"

class StaticObj : public Objects
{
	Q_OBJECT

public:
	StaticObj(QObject *parent);
	~StaticObj();
};
