#include <iostream>
#include <cmath>
#include "WindowManager.h"
#include "Shader.h"

int main()
{
   WindowManager wm;

   // ------------------
   // ---- Triangle ----
   // ------------------
   float vertices[] = {
       0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
       0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
      -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f
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

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
   glEnableVertexAttribArray(1);

   // -----------------
   // ---- Shaders ----
   // -----------------
   Shader shader("res/shader.glsl");

   // -------------------
   // ---- Main Loop ----
   // -------------------
   while (!glfwWindowShouldClose(wm.window))
   {
      wm.startRender();

      // Render
      shader.bind();
      glBindVertexArray(vao);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
      glBindVertexArray(0);

      wm.stopRender();
   }

   return 0;
}
