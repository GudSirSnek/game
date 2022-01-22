#include "maths.hpp"
#include <math.h>


float PE_Distance( const pe_vec2 a, const pe_vec2 b )
{
  return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}

float CrossProduct( const pe_vec2 a, const pe_vec2 b )
{
  return a.x * b.y - a.y * b.x;
}

pe_vec2 CrossProduct( const pe_vec2 a,  float s)
{
  pe_vec2 res;
  res.x = s*a.y;
  res.y = -s*a.x;
  return res;
}


pe_vec2 CrossProduct( float s, const pe_vec2 a )
{
  pe_vec2 res;
  res.x = -s*a.y;
  res.y = s*a.x;
  return res;
}