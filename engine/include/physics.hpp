#include "maths.hpp"



typedef struct{
    pe_vec2 min;
    pe_vec2 max;
}AABB;

typedef struct {
    float radius;
    pe_vec2 position;
}circle;


//Collision detections

bool AABBvsAABB(const AABB &a, const AABB &b);

bool CirclevsCircle(const circle &a, const circle &b);

pe_vec2 force(float mass, pe_vec2 acc);