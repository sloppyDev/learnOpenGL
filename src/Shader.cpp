#include "Shader.h"

#include <fstream>
#include <iostream>

Shader::Shader(const std::string &pathIn)
{
   std::string vSource;
   std::string fSource;

   std::string line;

   std::ifstream inFile(pathIn);
   if (!inFile.is_open())
   {
      std::cout << "Couldn't open file: " << pathIn << std::endl;
   }

   enum READ_STATE{
      NONE,
      VERT,
      FRAG,
   };

   READ_STATE readState = NONE;
   
   while (getline(inFile, line))
   {
      if (readState == NONE)
      {
         if (line.find("#Vertex") != std::string::npos)
         {
            readState = VERT;
         }
         else if (line.find("#Fragment") != std::string::npos)
         {
            readState = FRAG;
         }
      }
      else if (readState == VERT)
      {
         if (line.find("#Fragment") != std::string::npos)
         {
            readState = FRAG;
         }
         else
         {
            vSource += line + "\n";
         }
      }
      else if (readState == FRAG)
      {
         if (line.find("#Vertex") != std::string::npos)
         {
            readState = VERT;
         }
         else
         {
            fSource += line + "\n";
         }
      }
   }
   inFile.close();

   compileShaders(vSource.c_str(), fSource.c_str());
}
Shader::~Shader()
{}

void Shader::bind()
{
   glUseProgram(id);
}
void Shader::unbind()
{
   glUseProgram(0);
}

void Shader::compileShaders(const char* vSource, const char* fSource)
{
   unsigned int vId, fId;
   int success;
   char infoLog[512];

   // Vertex Shader
   vId = glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vId, 1, &vSource, NULL);
   glCompileShader(vId);
   glGetShaderiv(vId, GL_COMPILE_STATUS, &success);
   if (!success)
   {
      glGetShaderInfoLog(vId, 512, NULL, infoLog);
      std::cout << "Error compiling vertex shader!\n" << infoLog << std::endl;
   }
   // Fragment Shader
   fId = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fId, 1, &fSource, NULL);
   glCompileShader(fId);
   glGetShaderiv(fId, GL_COMPILE_STATUS, &success);
   if (!success)
   {
      glGetShaderInfoLog(fId, 512, NULL, infoLog);
      std::cout << "Error compiling fragment shader!\n" << infoLog << std::endl;
   }

   // Linking Program
   id = glCreateProgram();
   glAttachShader(id, vId);
   glAttachShader(id, fId);
   glLinkProgram(id);
   glGetProgramiv(id, GL_LINK_STATUS, &success);
   if (!success)
   {
      glGetProgramInfoLog(id, 512, NULL, infoLog);
      std::cout << "Error linking shader program!\n" << infoLog << std::endl;
   }

   glDeleteShader(vId);
   glDeleteShader(fId);
}

void Shader::setBool(const std::string &name, bool value) const
{}
void Shader::setInt(const std::string &name, int value) const
{}
void Shader::setFloat(const std::string &name, float value) const
{}
