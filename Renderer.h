#pragma once

#include <QObject>

class Renderer : public QObject
{
	Q_OBJECT

public:
	Renderer(QObject *parent);
	~Renderer();
};
