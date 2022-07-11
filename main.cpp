#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#define GLEW_STATIC //Glew bescheid sagen dass wir statisch linken wollen 
#include <GL/glew.h>
#define SDL_MAIN_HANDLED //SDL bescheid sagen dass wir eine eigene main funktion haben
#include <SDL.h>
#include "defines.h"
#include "vertex_buffer.h"
#include "index_buffer.h"
#include "shader.h"
#include "floating_camera.h"

#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//Link SDL2 und glew:
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")


int main()
{
	//Fenster erzeugen
	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);//double buffering
	SDL_GL_SetSwapInterval(-1); // 0/1 Vsync; -1 adaptive sync/ free sync wenn monitor es kann


	window = SDL_CreateWindow("Institutsprojekt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1200, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window); //Context wird für openGL Anfragen benötigt


	glewInit(); 

	//Punkte erstellen
	Vertex verticesCar[] = {
		Vertex{-0.5f, -0.5f,0.0f,
			0.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 1.0f},
		Vertex{-0.5f, 0.5f,0.0f,
			0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 1.0f},
		Vertex{0.5f, -0.5f,0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},
		Vertex{0.5f, 0.5f,0.0f,
			1.0f, 1.0f,
			0.0f, 1.0f, 1.0f, 1.0f},
		Vertex{-0.5f, -0.5f,1.5f,
			0.0f, 0.0f,
			1.0f, 0.0f, 1.0f, 1.0f},
		Vertex{-0.5f, 0.5f,1.4f,
			0.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},
		Vertex{0.5f, -0.5f,1.5f,
			0.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 1.0f},
		Vertex{0.5f, 0.5f,1.4f,
			0.0f, 0.0f,
			1.0f, 0.0f, 1.0f, 1.0f},

		Vertex{-0.5f, 0.1f,0.0f,
			0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 1.0f},
		Vertex{0.5f, 0.1f,0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},
		Vertex{-0.45f, 0.1f, -0.2f,
			0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 1.0f},
		Vertex{0.45f, 0.1f, -0.2f,
			1.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},

		Vertex{0.4f, 0.0f, -0.8f,
			1.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},
		Vertex{-0.4f, 0.0f, -0.8f,
			1.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},
		Vertex{-0.4f,-0.45f, -0.8f,
			1.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},
		Vertex{0.4f, -0.45f, -0.8f,
			1.0f, 0.0f,
			1.0f, 1.0f, 0.0f, 1.0f},


	};
	unsigned int numVertices = 35;
	unsigned int numVerticesCar = 16;

	Vertex verticesStreet[]
	{
		//Strasse
		Vertex{-1.0f, -1.0f, -15.0f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{1.0f, -1.0f, -15.0f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{1.0f,-1.0f, 5.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{-1.0f, -1.0f, 5.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{1.0f, -1.0f, 3.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{9.0f, -1.0f, 5.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{9.0f, -1.0f, 3.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{9.0f, -1.0f, -2.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{11.0f, -1.0f, -2.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{11.0f, -1.0f, -4.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{-6.0f, -1.0f, -4.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{-6.0f, -1.0f, -2.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{-4.0f, -1.0f, -2.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{-6.0f, -1.0f, 11.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{-4.0f, -1.0f, 11.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f},
		Vertex{-6.0f,-1.0f, 9.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f },
		Vertex{ 9.0f,-1.0f, 9.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f },
		Vertex{ 9.0f, -1.0f, 11.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f },
		Vertex{ 11.0f, -1.0f, 11.5f,
			0.0f, 0.0f,
			0.1f, 0.1f, 0.1f, 1.0f },
	};
	unsigned int numVerticesStreet = 19;

	//Indizes zur besseren Definition
	uint32 indicesStreet[] = {

		16,19,17,
		17,19,18,
		18,21,22,
		22,20,18,
		33,34,24,
		24,23,33,
		27,24,25,
		25,26,27,
		28,27,29,
		28,29,30,
		30,33,32,
		32,31,30,
	};
	uint32 numIndicesStreet = 36;

	uint32 indicesCar[] = {
		//Fahrzeug (Auf reihenfolge achten)
		10,11,12,
		10,12,13,
		1,0,5,
		5,0,4,
		2,3,7,
		7,6,2,
		5,4,6,
		5,6,7,
		2,4,0,
		2,6,4,
		3,9,11,
		1,10,8,
		1,11,10,
		1,3,11,
		13,12,15,
		15,14,13,
		2,15,12,
		2,12,11,
		2,11,9,
		14,0,13,
		0,10,13,
		0,8,10,
		0,14,15,
		15,2,0,
		3,1,5,
		5,7,3,
	};

	uint32 numIndicesCar = 78;

	IndexBuffer indexBufferCar(indicesCar, numIndicesCar, sizeof(indicesCar[0]));
	VertexBuffer vertexBufferCar(verticesCar, numVerticesCar);

	
	VertexBuffer vertexBufferStreet(verticesStreet, numVerticesStreet);
	IndexBuffer indexBufferStreet(indicesStreet, numIndicesStreet, sizeof(indicesStreet[0]));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Shader laden und binden
	Shader shader1("basic.vs", "basic.fs");
	shader1.bind();
	//Shader shader2("basic.vs", "basic.fs");
	//shader2.bind();
	
	//Counter
	uint64 perfCounterFrequency = SDL_GetPerformanceFrequency();
	uint64 lastCounter = SDL_GetPerformanceCounter();
	float32 delta = 0.0f;

	//Einführung uniform (farbänderung mehrerer Vertices)
	int colorUniformLocation = glGetUniformLocation(shader1.getShaderId(), "u_color");
	if (!colorUniformLocation != -1) {
		glUniform4f(colorUniformLocation, 1.0f, 0.0f, 1.0f, 1.0f);
	}
	//Uniform für textur
	int textureUniformLocation = glGetUniformLocation(shader1.getShaderId(), "u_texture");
	if (!textureUniformLocation != -1) {
		glUniform1i(textureUniformLocation, 0); //texturslot 0
	}



	glm::mat4 model = glm::mat4(1.0f); 

	//Camera
	FloatingCamera camera(90.0f, 800.0f, 600.0f); //(grad, Fenstergrösse bzw verhältnis)
	camera.translate(glm::vec3(0.0f, 3.0f, 10.0f)); //Bewegen der Kamera nach hinten
	camera.update(); //View-proj matrix aktualisieren



	//Projektionen
	bool ortho = false;
	glm::mat4 orthoProjection = glm::ortho(-2.0f, 2.0f, -2.0f, 2.0f, -10.0f, 100.0f); //(Groesse -2 bis 2 breite und höhe; near- & farplane) Stecken vermeiden
	glm::mat4 perspective = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);//(field of view,Aspectratio,Near- Farplane)ä
	glm::mat4 projection = perspective;
	
	glEnable(GL_CULL_FACE);

	glm::mat4 modelViewProj = camera.getViewProj() * model;
	int modelViewProjMatrixLocation = glGetUniformLocation(shader1.getShaderId(), "u_modelViewProj");
	//int modelViewProjMatrixLocation2 = glGetUniformLocation(shader2.getShaderId(), "u_modelViewProj");

	bool buttonW = false;
	bool buttonA = false;
	bool buttonS = false;
	bool buttonD = false;
	bool buttonShift = false;
	bool buttonSpace = false;
	float cameraSpeed = 6.0f;

	glm::vec3 direction = glm::vec3(0, 0, -1);

	float time = 0.0f;
	bool close = false;
	SDL_SetRelativeMouseMode(SDL_TRUE); // maus soll sich relativ bewegen

	while (!close) 
	{
		//schliessen des fensters beendet die while schleife
		//Events vom Betriebssystem abfragen
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				close = true;
			}
			else if (event.type == SDL_KEYDOWN) //Abfrage ob eine taste gedrückt wird
			{
				//Setzt den wert einer taste auf wahr
				switch (event.key.keysym.sym)
				{
				case SDLK_w:
					buttonW = true;
					break;
				case SDLK_a:
					buttonA = true;
					break;
				case SDLK_s:
					buttonS = true;
					break;
				case SDLK_d:
					buttonD = true;
					break;
				case SDLK_SPACE:
					buttonSpace = true;
					break;
				case SDLK_LSHIFT:
					buttonShift = true;
					break;
				case SDLK_ESCAPE:
					SDL_SetRelativeMouseMode(SDL_FALSE);
					break;
				}
			}
			//Tasten müssen zurückgesetzt werden beinm loslassen
			else if (event.type == SDL_KEYUP)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_w:
					buttonW = false;
					break;
				case SDLK_a:
					buttonA = false;
					break;
				case SDLK_s:
					buttonS = false;
					break;
				case SDLK_d:
					buttonD = false;
					break;
				case SDLK_SPACE:
					buttonSpace = false;
					break;
				case SDLK_LSHIFT:
					buttonShift = false;
					break;
				}
			}
			else if (event.type == SDL_MOUSEMOTION) 
			{
				if(SDL_GetRelativeMouseMode())//Bei escape soll sich die camera nicht bewegen können
				camera.rotate(event.motion.xrel, event.motion.yrel);
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT) {
					SDL_SetRelativeMouseMode(SDL_TRUE);
				}
			}
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Buffer schwarz setzen
		glClear(GL_COLOR_BUFFER_BIT); //Buffer löschen und definierte farbe übernehmen
		
		time += delta;
		if (!colorUniformLocation != -1) 
			glUniform4f(colorUniformLocation, sinf(time)*sinf(time), abs(cosf(time)), abs(sinf(time*2)), 1.0f);
		
		//Camera
		//Wenn taste gedrückt ist, ändert sich die Kamera
		if(buttonW){
			//camera.moveFront(delta * cameraSpeed);
			model = glm::translate(model, glm::normalize(camera.getlookAt()* glm::vec3(1,0,1)) * delta * cameraSpeed); //!GANZES MODELL BEWEGT SICH MIT!
		}

		if (buttonA)
		{
			model = glm::rotate(model, 1.5f * delta, glm::vec3(0, 1, 0));
			//camera.rotate(-0.08, 0);
			//camera.moveFront(delta * cameraSpeed / 3);
		}
		if (buttonS) 
		{
			//camera.moveFront(-delta * cameraSpeed);
			model = glm::translate(model, glm::normalize(-camera.getlookAt() * glm::vec3(1, 0, 1)) * delta * cameraSpeed);
		}
			
		if (buttonD) 
		{
			model = glm::rotate(model, -1.5f * delta, glm::vec3(0, 1, 0));
			//camera.rotate(0.08, 0);
			//camera.moveFront(delta * cameraSpeed/3);
		}
			
		if (buttonSpace)
			camera.moveUp(delta * cameraSpeed);
		if (buttonShift)
			camera.moveUp(-delta * cameraSpeed);
		camera.update();

		modelViewProj = camera.getViewProj() * model; //neu berechnen 
		
		//Wire frame modus
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glUniformMatrix4fv(modelViewProjMatrixLocation, 1, GL_FALSE, &modelViewProj[0][0]);
		
		vertexBufferStreet.bind();
		indexBufferStreet.bind();

		//glDrawElements(GL_TRIANGLES, numIndicesStreet, GL_UNSIGNED_INT, 0);

		indexBufferStreet.unbind();
		vertexBufferStreet.unbind();

		vertexBufferCar.bind();
		indexBufferCar.bind();

		//Professionelles Zeichnen mit elements
		glDrawElements(GL_TRIANGLES, numIndicesCar, GL_UNSIGNED_INT, 0); //Unsigned hier sehr wichtig

		indexBufferCar.unbind();
		vertexBufferCar.unbind();

		SDL_GL_SwapWindow(window); //Double Buffering zum Laden und anzeigen

		//Zeitmessung für rechnerunabhängige geschwindigkeit
		uint64 endCounter = SDL_GetPerformanceCounter();
		uint64 counterElapsed = endCounter - lastCounter;
		delta = ((float32)counterElapsed) / (float32)perfCounterFrequency;
		lastCounter = endCounter;
	}

	return 0;
} 