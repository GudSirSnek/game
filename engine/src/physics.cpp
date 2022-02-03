#include "physics.hpp"
#include <stdio.h>

bool AABBvsAABB(const AABB &a, const AABB &b){

    // Exit with no intersection if found separated along an axis
    if(a.max.x < b.min.x or a.min.x > b.max.x) 
        return false;
    if(a.max.y < b.min.y or a.min.y > b.max.y) 
        return false;

  // No separating axis found, therefor there is at least one overlapping axis
    return true;
}

bool CirclevsCircle(const circle &a, const circle &b)
{

    float r = a.radius + b.radius;
    r *= r;
    return r > (a.position.x - b.position.x)*(a.position.x - b.position.x) + 
                (a.position.y - b.position.y)*(a.position.y - b.position.y);
}


pe_vec2 force(float mass, pe_vec2 acc){
    pe_vec2 res;
    res.x = mass*acc.x;
    res.y = mass*acc.y;
    return res;
}