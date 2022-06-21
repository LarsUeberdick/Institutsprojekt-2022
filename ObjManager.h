#pragma once

#include <QObject>
#include "Objects.h"

class ObjManager : public QObject
{
	Q_OBJECT

public:
	ObjManager(QObject *parent);
	~ObjManager();
};
