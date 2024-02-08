#pragma once

class Mesh {
public:
  unsigned int _VAO = 0, _VBO = 0, _EBO = 0;

  Mesh();
  ~Mesh();
  void Draw();
void Triangle();
};
