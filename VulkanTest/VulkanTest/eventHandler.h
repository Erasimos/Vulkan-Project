#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

using namespace glm;

extern vec3 cameraPosition;
extern vec3 cameraDirection;

extern float  mouseXpos;
extern float mouseYpos;

void handleEvents(GLFWwindow* window);

void updateCameraDirection(GLFWwindow* window);

void updateCameraPosition(GLFWwindow* window);
