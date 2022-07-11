#version 330 core
//niedrigste Version die man benutzen kann

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_texCoord;
layout(location = 2) in vec4 a_color;

out vec4 v_color;
out vec2 v_texCoord;
uniform mat4 u_modelViewProj; //Matrix als uniform reinbringen

void main()
{
	gl_Position = u_modelViewProj * vec4(a_position, 1.0f); //Mit matrix multiplizieren um "Bewegung" zu erzeugen
	v_color = a_color;
	v_texCoord = a_texCoord;
}
