#include "vec3.h"

vec3::vec3()
{
   x = 0.0f;
   y = 0.0f;
   z = 0.0f;
}

vec3::vec3(float in)
{
   x = in;
   y = in;
   z = in;
}

vec3::vec3(float xin, float yin, float zin)
{
   x = xin;
   y = yin;
   z = zin;
}

void vec3::operator=(const vec3 &vin)
{
   this->x = vin.x;
   this->y = vin.y;
   this->z = vin.z;
}

vec3 vec3::operator+(const vec3 &vin)
{
   float newX = this->x + vin.x;
   float newY = this->y + vin.y;
   float newZ = this->z + vin.z;
   vec3 newV(newX, newY, newZ);

   return newV;
}

vec3 vec3::operator-(const vec3 &vin)
{
   float newX = this->x - vin.x;
   float newY = this->y - vin.y;
   float newZ = this->z - vin.z;
   vec3 newV(newX, newY, newZ);

   return newV;
}

vec3 vec3::operator-()
{
   vec3 newV(-this->x, -this->y, -this->z);
   return newV;
}

float vec3::operator*(const vec3 &vin)
{
   return this->x * vin.x + this->y * vin.y + this->z * vin.z;
}
