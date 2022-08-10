#include "mat4.h"
#include "vec3.h"
#include <iostream>
#include <cmath>

mat4::mat4()
{
   c1.x = 1.0f;
   c1.y = 0.0f;
   c1.z = 0.0f;
   c1.w = 0.0f;

   c2.x = 0.0f;
   c2.y = 1.0f;
   c2.z = 0.0f;
   c2.w = 0.0f;

   c3.x = 0.0f;
   c3.y = 0.0f;
   c3.z = 1.0f;
   c3.w = 0.0f;

   c4.x = 0.0f;
   c4.y = 0.0f;
   c4.z = 0.0f;
   c4.w = 1.0f;
}

mat4::mat4(const float &in)
{
   c1.x = in;
   c1.y = 0.0f;
   c1.z = 0.0f;
   c1.w = 0.0f;

   c2.x = 0.0f;
   c2.y = in;
   c2.z = 0.0f;
   c2.w = 0.0f;

   c3.x = 0.0f;
   c3.y = 0.0f;
   c3.z = in;
   c3.w = 0.0f;

   c4.x = 0.0f;
   c4.y = 0.0f;
   c4.z = 0.0f;
   c4.w = 1.0f;
}

mat4::mat4(const float &in1, const float &in2, const float &in3)
{
   c1.x = in1;
   c1.y = 0.0f;
   c1.z = 0.0f;
   c1.w = 0.0f;

   c2.x = 0.0f;
   c2.y = in2;
   c2.z = 0.0f;
   c2.w = 0.0f;

   c3.x = 0.0f;
   c3.y = 0.0f;
   c3.z = in3;
   c3.w = 0.0f;

   c4.x = 0.0f;
   c4.y = 0.0f;
   c4.z = 0.0f;
   c4.w = 1.0f;
}

mat4::mat4(const vec4 &c1in, const vec4 &c2in, const vec4 &c3in, const vec4 &c4in)
{
   c1 = c1in;
   c2 = c2in;
   c3 = c3in;
   c4 = c4in;
}

void mat4::operator=(const mat4 &min)
{
   c1 = min.c1;
   c2 = min.c2;
   c3 = min.c3;
   c4 = min.c4;
}

mat4 mat4::operator*(const mat4 &min)
{
   vec4 v1 = getRow(1);
   vec4 v2 = getRow(2);
   vec4 v3 = getRow(3);
   vec4 v4 = getRow(4);

   vec4 newCols[4];

   vec4 currCol;
   vec4 *currRow;

   for (unsigned int i = 0; i < 4; i++)
   {
      for (unsigned int j = 0; j < 4; j++)
      {
         switch (j)
         {
            case 0:
               currRow = &v1;
               break;
            case 1:
               currRow = &v2;
               break;
            case 2:
               currRow = &v3;
               break;
            case 3:
               currRow = &v4;
               break;
         }
         switch (i)
         {
            case 0:
               currCol = min.c1;
               break;
            case 1:
               currCol = min.c2;
               break;
            case 2:
               currCol = min.c3;
               break;
            case 3:
               currCol = min.c4;
               break;
         }
         newCols[i][j] = currCol**currRow;
      }
   }

   return mat4(newCols[0], newCols[1], newCols[2], newCols[3]);
}

vec4 mat4::operator*(const vec4 &vin)
{
   vec4 v1 = getRow(1);
   vec4 v2 = getRow(2);
   vec4 v3 = getRow(3);

   return vec4(v1*vin, v2*vin, v3*vin);
}

vec4 mat4::getRow(const unsigned int &rowNum)
{
   return vec4(c1[rowNum-1], c2[rowNum-1], c3[rowNum-1], c4[rowNum-1]);
}

void mat4::print()
{
   getRow(1).print();
   getRow(2).print();
   getRow(3).print();
   getRow(4).print();

   std::cout << std::endl;
}

tran4::tran4(const vec3 &trans)
{
   c4.x = trans.x;
   c4.y = trans.y;
   c4.z = trans.z;
}

rot4::rot4(const vec3 &angs)
{
   float phi = angs.x*(PI/180.0f);
   float theta = angs.y*(PI/180.0f);
   float psi = angs.z*(PI/180.0f);

   float sphi = sin(phi);
   float cphi = cos(phi);

   float stheta = sin(theta);
   float ctheta = cos(theta);

   float spsi = sin(psi);
   float cpsi = cos(psi);

   mat4 R1, R2, R3;

   R1.c2.y = cphi;
   R1.c2.z = sphi;
   R1.c3.y = -sphi;
   R1.c3.z = cphi;

   R2.c1.x = ctheta;
   R2.c1.z = -stheta;
   R2.c3.x = stheta;
   R2.c3.z = ctheta;

   R3.c1.x = cpsi;
   R3.c1.y = spsi;
   R3.c2.x = -spsi;
   R3.c2.y = cpsi;

   mat4 tmp = R1*R2*R3;
   c1 = tmp.c1;
   c2 = tmp.c2;
   c3 = tmp.c3;
   c4 = tmp.c4;
}

scale4::scale4(const vec3 &scales)
{
   c1.x = scales.x;
   c2.y = scales.y;
   c3.z = scales.z;
}
