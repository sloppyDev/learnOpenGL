#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/glew.h>

struct Shader
{
   Shader(const std::string &pathIn);
   ~Shader();

   void bind();
   void unbind();

   void compileShaders(const char* vSource, const char* fSource);

   void setBool(const std::string &name, bool value) const;
   void setInt(const std::string &name, int value) const;
   void setFloat(const std::string &name, float value) const;

   uint32_t id;
};
#endif
