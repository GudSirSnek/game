#pragma once
#define pi 3.14159265358979

#define pe_deg_to_rad(deg) deg*(pi/180)
#define pe_rad_to_deg(rad) rad *(180/pi)
#define pe_square(e) e*e
#define pe_1dDist(c1, c2) c2 - c1



typedef struct{
    float x, y;
    float magnitude;

    void calcMag();

}pe_vec2;


float PE_Distance(const pe_vec2 a, const pe_vec2 b);

float CrossProduct(const pe_vec2 a, const pe_vec2 b);

pe_vec2 CrossProduct(const pe_vec2 a, float s);

pe_vec2 CrossProduct(float s, const pe_vec2 a);