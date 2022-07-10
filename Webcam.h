#pragma once

#include "Input.h"

class Webcam : public Input
{
	Q_OBJECT

public:
	Webcam(QObject *parent);
	~Webcam();
};
