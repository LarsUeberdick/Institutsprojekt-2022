#pragma once

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ui_Game.h"
#include "Input.h"
#include "ObjManager.h"
#include "Sim.h"
#include "Renderer.h"

class Game : public QWidget
{
	Q_OBJECT

public:
	Game(QWidget *parent = Q_NULLPTR);
	~Game();

private:
	Ui::Game ui;
};
