#pragma once
#include "camera.h"

class FPSCamera : public Camera
{
public:
	FPSCamera(float fov, float width, float height): Camera(fov, width, height)
	{
		//initialisierung
		up = glm::vec3(0.0f, 1.0f, 0.0f);
		yaw = -90.0f;
		pitch = 0.0f;
		rotate(0.0f, 0.0f);
		update();
	}
	void rotate(float xRel, float yRel)//Wv bewegt sich die maus
	{
		yaw += xRel/5;
		pitch -= yRel/5;
		//grenzen für kamera
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
		glm::vec3 front;
		/* Für bewegende Kamera wieder aktivieren:
		front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		front.y = sin(glm::radians(pitch)) - 1;
		front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		*/
		front.x = 0;
		front.y =  - 0.4;
		front.z = -1;
		lookAt = glm::normalize(front);
		update();
	}
	void update() override {
		view = glm::lookAt(position, position + lookAt, up);
		viewProj = projection * view;
	}
	void moveFront(float amount) {
		translate(glm::normalize(glm::vec3(1.0f,0.0f,1.0f)* lookAt) * amount); //durch vektor nur auf einer höhe bewegen
		update();
	}
	void moveSideways(float amount) {
		translate(glm::normalize(glm::cross(lookAt, up)) * amount);
		update();
	}
	glm::vec3 getlookAt() {
		return lookAt;
	}
protected:
	float yaw;//roty
	float pitch; //rotx
	//roll -unübersichtlich
	glm::vec3 lookAt;
	glm::vec3 up;
	const float mouseSensitivity = 0.1f;
};

