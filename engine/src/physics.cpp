#include "physics.hpp"


pe_vec2 force(float mass, pe_vec2 acc){
    pe_vec2 res;
    res.x = mass*acc.x;
    res.y = mass*acc.y;
    return res;
}