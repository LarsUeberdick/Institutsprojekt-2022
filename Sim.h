#pragma once

#include <QObject>

class Sim : public QObject
{
	Q_OBJECT

public:
	Sim(QObject *parent);
	~Sim();
};
