#include "Mesh.hpp"
#include <glad/glad.h>
#include <glm/glm.hpp>

Mesh::Mesh() {}
Mesh::~Mesh() {}

void Mesh::Triangle() {

  float vertices[] = {
      0.0f,  0.5f,  0.0f, //
      0.5f,  -0.5f, 0.0f, //
      -0.5f, -0.5f, 0.0f  //
  };

  glGenVertexArrays(1, &_VAO);
  glBindVertexArray(_VAO);

  glGenBuffers(1, &_VBO);
  glBindBuffer(GL_ARRAY_BUFFER, _VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

}

void Mesh::Draw() {
  glBindVertexArray(_VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}
