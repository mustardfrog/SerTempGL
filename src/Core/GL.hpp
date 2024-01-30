#pragma once

#include <GLFW/glfw3.h>

namespace GL {
GLFWwindow *GetWindowPtr();
void CreateWindow();
void Init();
void CleanUp();
} // namespace GL
