#include "shader.h"
#include <fstream>
#include <iostream>

Shader::Shader(const char* vertexShaderFilename, const char* fragmentShaderFilename)
{
	shaderId = createShader(vertexShaderFilename, fragmentShaderFilename);
}

Shader::~Shader()
{
	glDeleteProgram(shaderId);
}

void Shader::bind()
{
	glUseProgram(shaderId);
}

void Shader::unbind()
{
	glUseProgram(0);
}


GLuint Shader::compile(std::string shaderSource, GLenum type)
{
	GLuint id = glCreateShader(type);
	const char* src = shaderSource.c_str();
	glShaderSource(id, 1, &src, 0);
	glCompileShader(id);
	//Compile errors abfragen
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result != GL_TRUE) {
		int length = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Shader compilation error: " << message << std::endl;
		delete[] message;
		return 0;
	}
	return id;
}

//Datei einlesen
std::string Shader::parse(const char* filename)
{
	FILE* file;
	//file = fopen(filename, "rb"); //Datei öffnen (read binary)
	//Datei nicht vorhanden:
	if (fopen_s(&file, filename, "rb")!=0) {
		std::cout << "File " << filename << " not found" << std::endl;
		return "";
	}

	std::string contents; //dateiinhalt
	fseek(file, 0, SEEK_END); //Dateigrösse ermitteln (geht bis zum Ende der Datei)
	size_t filesize = ftell(file); //ftell sagt wo wir in der datei sind
	rewind(file); // zurück zum Anfang der Datei gehen
	contents.resize(filesize); //Speicher anpassen

	fread(&contents[0], 1, filesize, file);
	fclose(file);

	return contents;
}

GLuint Shader::createShader(const char* vertexShaderFilename, const char* fragmentShaderFilename)
{
	//Code der Shader einlesen und speichern
	std::string vertexShaderSource = parse(vertexShaderFilename);
	std::string fragmentShaderSource = parse(fragmentShaderFilename);

	GLuint program = glCreateProgram();
	GLuint vs = compile(vertexShaderSource, GL_VERTEX_SHADER);
	GLuint fs = compile(fragmentShaderSource, GL_FRAGMENT_SHADER);
	
	//Linken
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);

	return program;
}

	