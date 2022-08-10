#ifndef VEC4_H
#define VEC4_H

#pragma pack(1)

struct vec4
{
   vec4();
   vec4(float in);
   vec4(float xin, float yin, float zin);
   vec4(float xin, float yin, float zin, float win);

   void operator=(const vec4 &vin);
   vec4 operator+(const vec4 &vin);
   vec4 operator-(const vec4 &vin);
   vec4 operator-();
   float operator*(const vec4 &vin);
   float &operator[](int i);

   void print();

   float x, y, z, w;
};
#endif
