#pragma once

#include <glad/glad.h>
#include <string>

class Shader {
public:
  int _ID = -1;
  void LoadShader(std::string vs, std::string fs);
  std::string ReadFromFile(std::string filename);
  void Bind();
  int CheckCompileError(unsigned int shader, std::string type);
};
