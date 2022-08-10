#include "WindowManager.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
   glViewport(0, 0, width, height);
}

WindowManager::WindowManager(unsigned int widthIn, unsigned int heightIn, const std::string &nameIn)
   : width(widthIn),
     height(heightIn),
     name(nameIn)
{
   // -------------------------------
   // ---- Window Initialization ----
   // -------------------------------
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
   if (window == NULL)
   {
      std::cout << "Failed to create GLFW window!" << std::endl;
      glfwTerminate();
   }
   glfwMakeContextCurrent(window);

   if (glewInit() != GLEW_OK)
   {
      std::cout << "Error initializing GLEW!" << std::endl;
   }

   glViewport(0, 0, 800, 600);
   glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
   glClearColor(0.2f, 0.32f, 0.3f, 1.0f);
}

WindowManager::~WindowManager()
{
   glfwTerminate();
}

void WindowManager::startRender()
{
   glClear(GL_COLOR_BUFFER_BIT);
   escapeCallback();
}

void WindowManager::stopRender()
{
   glfwSwapBuffers(window);
   glfwPollEvents();
}

void WindowManager::escapeCallback()
{
   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
   {
      glfwSetWindowShouldClose(window, true);

   }
}
