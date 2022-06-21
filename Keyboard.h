#pragma once

#include "Input.h"

class Keyboard : public Input
{
	Q_OBJECT

public:
	Keyboard(QObject *parent);
	~Keyboard();
};
