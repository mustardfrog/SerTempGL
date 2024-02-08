#include "Renderer.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

struct Shaders {
  Shader triangle;
} _shader;

struct ShapeMesh {
  Mesh triMesh;
} _mesh;

void Renderer::Init() {
  _shader.triangle.LoadShader("res/shaders/tri.vert", "res/shaders/tri.frag");
  _mesh.triMesh.Triangle();
}

void Renderer::Render() {
  _shader.triangle.Bind();
  _mesh.triMesh.Draw();
}

void Renderer::Clear() {
  glClearColor(0.0f, 0.3f, 0.3f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
