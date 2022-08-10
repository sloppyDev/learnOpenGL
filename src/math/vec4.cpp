#include "vec4.h"
#include <iostream>

vec4::vec4()
{
   x = 0.0f;
   y = 0.0f;
   z = 0.0f;
   w = 1.0f;
}

vec4::vec4(float in)
{
   x = in;
   y = in;
   z = in;
   w = 1.0f;
}

vec4::vec4(float xin, float yin, float zin)
{
   x = xin;
   y = yin;
   z = zin;
   w = 1.0f;
}

vec4::vec4(float xin, float yin, float zin, float win)
{
   x = xin;
   y = yin;
   z = zin;
   w = win;
}

void vec4::operator=(const vec4 &vin)
{
   x = vin.x;
   y = vin.y;
   z = vin.z;
   w = vin.w;
}

vec4 vec4::operator+(const vec4 &vin)
{
   float newX = x + vin.x;
   float newY = y + vin.y;
   float newZ = z + vin.z;
   vec4 newV(newX, newY, newZ);

   return newV;
}

vec4 vec4::operator-(const vec4 &vin)
{
   float newX = x - vin.x;
   float newY = y - vin.y;
   float newZ = z - vin.z;
   vec4 newV(newX, newY, newZ);

   return newV;
}

vec4 vec4::operator-()
{
   vec4 newV(-x, -y, -z);
   return newV;
}

float vec4::operator*(const vec4 &vin)
{
   return x * vin.x + y * vin.y + z * vin.z + w * vin.w;
}

float &vec4::operator[](int i)
{
   switch (i)
   {
      case 0:
         return x;
         break;
      case 1:
         return y;
         break;
      case 2:
         return z;
         break;
      case 3:
         return w;
         break;
      default:
         return x;
   }
}

void vec4::print()
{
   std::cout << "[ " << x << ", " << y << ", " << z << ", " << w << " ]" << std::endl << std::endl;
}
