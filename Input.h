#pragma once

#include <QObject>

class Input : public QObject
{
	Q_OBJECT

public:
	Input(QObject *parent);
	~Input();
};
