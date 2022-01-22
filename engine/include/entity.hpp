#include "maths.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity{

    pe_vec2 Position;
    pe_vec2 Velocity;
    pe_vec2 acceleration;
    SDL_Texture* Text;

    public:
        Entity();

        pe_vec2 getpos();
        void setpos(pe_vec2);
        pe_vec2 getvel();
        void setvel(pe_vec2);
        pe_vec2 getacc();
        void setacc(pe_vec2);

        void update();

        ~Entity();
};