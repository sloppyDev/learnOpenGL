#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <string>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct WindowManager
{
   WindowManager(unsigned int width=800, unsigned int height=600, const std::string &name="Hello!");
   ~WindowManager();

   void startRender();
   void stopRender();
   void escapeCallback();

   GLFWwindow *window;
   uint32_t width, height;
   const std::string name;
};
#endif
