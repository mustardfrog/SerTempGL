#include <glad/glad.h>

#include "GL.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace GL {
GLFWwindow *_window;
inline int _width = 900;
inline int _height = 600;
} // namespace GL

void GL::Init() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GL::CreateWindow();

  glfwMakeContextCurrent(_window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return;
  }
}

void GL::CleanUp() { glfwTerminate(); }

void GL::CreateWindow() {
  _window = glfwCreateWindow(_width, _height, "OpenGL", NULL, NULL);
  if (_window == NULL) {
    std::cerr << "Cannot Create Window" << std::endl;
    glfwTerminate();
  }
}

GLFWwindow *GL::GetWindowPtr() { return _window; }
