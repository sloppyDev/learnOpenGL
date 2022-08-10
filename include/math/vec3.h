#ifndef VEC3_H
#define VEC3_H

#pragma pack(1)

struct vec3
{
   vec3();
   vec3(float in);
   vec3(float xin, float yin, float zin);

   void operator=(const vec3 &vin);
   vec3 operator+(const vec3 &vin);
   vec3 operator-(const vec3 &vin);
   vec3 operator-();
   float operator*(const vec3 &vin);

   float x, y, z;
};
#endif
