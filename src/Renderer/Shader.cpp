#include "Shader.hpp"
#include <fstream>
#include <iostream>
#include <string>

void Shader::LoadShader(std::string vs, std::string fs) {
  std::string vSource = Shader::ReadFromFile(vs);
  std::string fSource = Shader::ReadFromFile(fs);

  const char *vShaderCode = vSource.c_str();
  const char *fShaderCode = fSource.c_str();

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vShaderCode, NULL);
  glCompileShader(vertexShader);
  CheckCompileError(vertexShader, "VERTEX");

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
  glCompileShader(fragmentShader);
  CheckCompileError(fragmentShader, "FRAGMENT");

  unsigned int program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);

  if (CheckCompileError(program, "PROGRAM")) {
    if (_ID != -1) {
      glDeleteProgram(program);
    } else {
      _ID = program;
    }
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

std::string Shader::ReadFromFile(std::string filename) {
  std::ifstream file(filename);
  std::string line;
  std::string str;

  while (std::getline(file, line)) {
    str += line + '\n';
  }

  return str;
}

void Shader::Bind() {
  glUseProgram(_ID);
}

int Shader::CheckCompileError(unsigned int shader, std::string type) {
  int succes;
  char infoLog[1024];

  if (type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &succes);
    if (!succes) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER COMPILING FAILED:: " << type << std::endl;
      std::cout << "INFO LOG: >> " << infoLog << std::endl;
      std::cout << "Success Status:  " << succes << std::endl;
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &succes);
    if (!succes) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "SHADER LINKING FAILED:: " << type << std::endl;
      std::cout << "INFO LOG: >> " << infoLog << std::endl;
      std::cout << "Success Status:  " << succes << std::endl;
    }
  }

  return succes;
}
