#pragma once

#include <QObject>

class Objects : public QObject
{
	Q_OBJECT

public:
	Objects(QObject *parent);
	~Objects();
};
