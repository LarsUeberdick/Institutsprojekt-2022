#pragma once
#include <GL/glew.h>
#include "defines.h"

struct VertexBuffer {
	VertexBuffer(void* data, uint32 numVertices) {
		//vao speichert Buffer und Layout
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		//buffer
		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vertex), data, GL_STATIC_DRAW);
		//Layout
		//Positionsattribut
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(struct Vertex,x)); //Index, Dimension der Punkte, Typ, Normalenkoord, stride (= distanz zum nächsten Objekt), offset zum 1. Element
		//Textirattribut
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(struct Vertex, u));
		//Farbattribut
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(struct Vertex, r));

		glBindVertexArray(0);
	}
	virtual ~VertexBuffer() {
		glDeleteBuffers(1, &bufferId);

	}

	void bind() {
		glBindVertexArray(vao);
		/*Durch vao können folgende Zeilen weggelassen werden (Im Konstruktor schon in vao definiert)
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		*/
	}

	void unbind() {
		glBindVertexArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

private:
	GLuint bufferId;
	GLuint vao;
};