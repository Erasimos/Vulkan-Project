#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

using namespace glm;

extern vec3 cameraPosition;
extern vec3 cameraDirection;

extern float  mouseXpos;
extern float mouseYpos;

extern const float cameraSpeed;
extern const float cameraRotationSpeed;

extern const vec3 worldUp;

void handleEvents(GLFWwindow* window, float deltaTime);

void updateCameraDirection(GLFWwindow* window, float deltaTime);

void updateCameraPosition(GLFWwindow* window, float deltaTime);
