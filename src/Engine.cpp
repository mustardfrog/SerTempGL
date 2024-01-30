#include "Engine.hpp"
#include "Core/GL.hpp"
#include <GL/gl.h>
#include <GLFW/glfw3.h>

void Engine::Init() { GL::Init(); }

void Engine::Run() {

  Engine::Init();

  while (!glfwWindowShouldClose(GL::GetWindowPtr())) {

    glClearColor(0.9f, 0.3f, 0.3f, 0.3f);
    glClear(GL_COLOR_BUFFER_BIT);

    if (glfwGetKey(GL::GetWindowPtr(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      glfwSetWindowShouldClose(GL::GetWindowPtr(), true);
    }

    glfwSwapBuffers(GL::GetWindowPtr());
    glfwPollEvents();
  }
}

void Engine::CleanUp() { GL::CleanUp(); }
