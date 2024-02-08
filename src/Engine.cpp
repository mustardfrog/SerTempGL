#include "Engine.hpp"
#include "Core/GL.hpp"
#include "Renderer/Renderer.hpp"
#include <GL/gl.h>
#include <GLFW/glfw3.h>

void Engine::Init() {
  GL::Init();
  Renderer::Init();
}

void Engine::Run() {

  Engine::Init();

  while (!glfwWindowShouldClose(GL::GetWindowPtr())) {

    Renderer::Clear();

    GL::ProcessInput(GL::GetWindowPtr());

    Renderer::Render();

    GL::Swap(GL::GetWindowPtr());
  }

  Engine::CleanUp();
}

void Engine::CleanUp() { GL::CleanUp(); }
