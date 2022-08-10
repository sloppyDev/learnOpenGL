#ifndef MAT4_H
#define MAT4_H

#include "vec4.h"

#define PI 3.14159265359f

struct vec3;

struct mat4
{
   mat4();
   mat4(const float &in);
   mat4(const float &in1, const float &in2, const float &in3);
   mat4(const vec4 &c1in, const vec4 &c2in, const vec4 &c3in, const vec4 &c4in);

   void operator=(const mat4 &min);
   mat4 operator*(const mat4 &vin);
   vec4 operator*(const vec4 &vin);

   vec4 getRow(const unsigned int &rowNum);
   void print();

   vec4 c1, c2, c3, c4;
};

struct tran4 : mat4
{
   tran4(const vec3 &trans);
};

struct rot4 : mat4
{
   rot4(const vec3 &angs);
};

struct scale4 : mat4
{
   scale4(const vec3 &scales);
};
#endif
