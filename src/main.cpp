#include <iostream>
#include <cmath>
#include "WindowManager.h"
#include "Shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
   WindowManager wm;

   // -------------------
   // ---- Triangles ----
   // -------------------
   float vertices[] = {
       0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
       0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
      -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f
   };
   uint32_t indices[] = {
      0, 1, 3,
      1, 2, 3
   };

   uint32_t vao;
   glGenVertexArrays(1, &vao);

   uint32_t vbo;
   glGenBuffers(1, &vbo);

   uint32_t ebo;
   glGenBuffers(1, &ebo);

   glBindVertexArray(vao);
   glBindBuffer(GL_ARRAY_BUFFER, vbo);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
   glEnableVertexAttribArray(1);
   glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
   glEnableVertexAttribArray(2);

   // -----------------
   // ---- Texture ----
   // -----------------

   uint32_t texture;
   glGenTextures(1, &texture);
   glBindTexture(GL_TEXTURE_2D, texture);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

   int width, height, nrChannels;
   std::string texPath = "res/textures/container.jpg";
   stbi_set_flip_vertically_on_load(true);
   unsigned char* data = stbi_load(texPath.c_str(), &width, &height, &nrChannels, 0);
   if (data)
   {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
   }
   else
   {
      std::cout << "Failed to load texture - " << texPath << " !" << std::endl;
   }
   stbi_image_free(data);
   
   // -----------------
   // ---- Shaders ----
   // -----------------
   Shader shader("res/shaders/shader.glsl");

   // -------------------
   // ---- Main Loop ----
   // -------------------
   while (!glfwWindowShouldClose(wm.window))
   {
      wm.startRender();

      // Render
      shader.bind();
      glBindTexture(GL_TEXTURE_2D, texture);
      glBindVertexArray(vao);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
      glBindVertexArray(0);

      wm.stopRender();
   }

   return 0;
}
