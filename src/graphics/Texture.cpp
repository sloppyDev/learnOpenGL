#include "Texture.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string &pathIn, bool flip)
   : path(pathIn)
{
   glGenTextures(1, &id);
   glBindTexture(GL_TEXTURE_2D, id);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   stbi_set_flip_vertically_on_load(flip);
   unsigned char* data = stbi_load(path.c_str(), &width, &height, &chanNum, 0);
   if (data)
   {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
   }
   else
   {
      std::cout << "Failed to load texture - " << path << " !" << std::endl;
   }
   stbi_image_free(data);
}

Texture::~Texture()
{}

void Texture::bind(uint32_t texSlotIn)
{
   glActiveTexture(texSlotIn);
   glBindTexture(GL_TEXTURE_2D, id);
}
void Texture::unbind(uint32_t texSlotIn)
{
   glActiveTexture(texSlotIn);
   glBindTexture(GL_TEXTURE_2D, 0);
}
