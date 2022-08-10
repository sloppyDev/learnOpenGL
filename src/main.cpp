#include <iostream>
#include <cmath>
#include "WindowManager.h"
#include "Shader.h"
#include "Texture.h"

#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

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
   Texture texture("res/textures/container.jpg", true);

   // -----------------
   // ---- Shaders ----
   // -----------------
   Shader shader("res/shaders/shader.glsl");

   // --------------------
   // ---- Math Tests ----
   // --------------------
   vec4 testVec;
   mat4 testMat;
   rot4 testRot(vec3(90.0f, 0.0f, 0.0f));
   scale4 testScale(vec3(1.0f, 2.0f, 3.0f));
   tran4 testTrans(vec3(4.0f, 3.0f, 2.0f));

   testVec.print();
   testMat.print();
   testRot.print();
   testScale.print();
   testTrans.print();

   (testTrans*testScale).print();


   // -------------------
   // ---- Main Loop ----
   // -------------------
   while (!glfwWindowShouldClose(wm.window))
   {
      wm.startRender();

      // Render
      shader.bind();
      texture.bind(0);
      glBindVertexArray(vao);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
      glBindVertexArray(0);

      wm.stopRender();
   }

   return 0;
}
