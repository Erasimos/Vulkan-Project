#include "eventHandler.h"

vec3 cameraPosition = vec3(5.0f, 0.0f, 0.0f);
vec3 cameraDirection = vec3(1.0f, 0.0f, 0.0f);

float mouseXpos = 0;
float mouseYpos = 0;

const float cameraSpeed = 5.0f;
const float cameraRotationSpeed = 0.5f;
const vec3 worldUp = vec3(0.0f, 0.f, 1.0f);

void handleEvents(GLFWwindow* window, float deltaTime){
	updateCameraDirection(window, deltaTime);
	updateCameraPosition(window, deltaTime);
}

void updateCameraDirection(GLFWwindow* window, float deltaTime) {
	GLdouble xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);

	int mousePressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

	if (mousePressed == GLFW_PRESS) {
		float deltaX = (mouseXpos - xPos);
		float deltaY = (mouseYpos - yPos);

		mat4 yaw = rotate(mat4(1.0f), cameraRotationSpeed * deltaX * deltaTime, worldUp);
		mat4 pitch = rotate(mat4(1.0f), cameraRotationSpeed * -deltaY * deltaTime, normalize(cross(cameraDirection, worldUp)));
		cameraDirection = normalize(vec3(pitch * yaw * vec4(cameraDirection, 0.0f)));
	}
	mouseXpos = xPos;
	mouseYpos = yPos;
}

void updateCameraPosition(GLFWwindow* window, float deltaTime) {
	 
	int state;
	vec3 cameraRight = cross(cameraDirection, worldUp);


	// W
	state = glfwGetKey(window, GLFW_KEY_W);
	if (state == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * cameraDirection * deltaTime;
	}

	// A
	state = glfwGetKey(window, GLFW_KEY_A);
	if (state == GLFW_PRESS) {
		cameraPosition += cameraSpeed * cameraRight * deltaTime;
	}

	// S
	state = glfwGetKey(window, GLFW_KEY_S);
	if (state == GLFW_PRESS) {
		cameraPosition += cameraSpeed * cameraDirection * deltaTime;
	}

	// D
	state = glfwGetKey(window, GLFW_KEY_D);
	if (state == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * cameraRight * deltaTime;
	}

	// Q
	state = glfwGetKey(window, GLFW_KEY_Q);
	if (state == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * worldUp * deltaTime;
	}

	// E
	state = glfwGetKey(window, GLFW_KEY_E);
	if (state == GLFW_PRESS) {
		cameraPosition += cameraSpeed * worldUp * deltaTime;
	}
}
