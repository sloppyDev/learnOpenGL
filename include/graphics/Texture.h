#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include <GL/glew.h>

struct Texture
{
   Texture(const std::string &pathIn, bool flip = true);
   ~Texture();

   void bind(uint32_t texSlotIn);
   void unbind(uint32_t texSlotIn);

   uint32_t id;
   const std::string& path;
   int32_t height, width, chanNum;
};
#endif
