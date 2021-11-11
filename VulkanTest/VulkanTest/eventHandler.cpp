#include "eventHandler.h"

vec3 cameraPosition = vec3(5.0f, 0.0f, 0.0f);
vec3 cameraDirection = vec3(1.0f, 0.0f, 0.0f);

float mouseXpos = 0;
float mouseYpos = 0;

const vec3 worldUp = vec3(0.0f, 0.f, 1.0f);

void handleEvents(GLFWwindow* window){
	updateCameraDirection(window);
	updateCameraPosition(window);
}

void updateCameraDirection(GLFWwindow* window) {
	GLdouble xPos, yPos;
	glfwGetCursorPos(window, &xPos, &yPos);

	int mousePressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

	if (mousePressed == GLFW_PRESS) {
		float deltaX = (mouseXpos - xPos);
		float deltaY = (mouseYpos - yPos);

		float rotation_speed = 0.001f;
		mat4 yaw = rotate(mat4(1.0f), rotation_speed * deltaX, worldUp);
		mat4 pitch = rotate(mat4(1.0f), rotation_speed * -deltaY, normalize(cross(cameraDirection, worldUp)));
		cameraDirection = normalize(vec3(pitch * yaw * vec4(cameraDirection, 0.0f)));
	}
	mouseXpos = xPos;
	mouseYpos = yPos;
}

void updateCameraPosition(GLFWwindow* window) {
	 
	int state;
	float cameraSpeed = 0.005f;
	vec3 cameraRight = cross(cameraDirection, worldUp);


	// W
	state = glfwGetKey(window, GLFW_KEY_W);
	if (state == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * cameraDirection;
	}

	// A
	state = glfwGetKey(window, GLFW_KEY_A);
	if (state == GLFW_PRESS) {
		cameraPosition += cameraSpeed * cameraRight;
	}

	// S
	state = glfwGetKey(window, GLFW_KEY_S);
	if (state == GLFW_PRESS) {
		cameraPosition += cameraSpeed * cameraDirection;
	}

	// D
	state = glfwGetKey(window, GLFW_KEY_D);
	if (state == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * cameraRight;
	}

	// Q
	state = glfwGetKey(window, GLFW_KEY_Q);
	if (state == GLFW_PRESS) {
		cameraPosition -= cameraSpeed * worldUp;
	}

	// E
	state = glfwGetKey(window, GLFW_KEY_E);
	if (state == GLFW_PRESS) {
		cameraPosition += cameraSpeed * worldUp;
	}
}
