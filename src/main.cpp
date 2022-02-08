#include "engine.hpp"
#include <stdio.h>
#include <math.h>
#include "physics.hpp"
Game *game = nullptr;



///////////////////////////////////////////////////////////////////////////////
// Setup function that runs once at the beginning of our program
///////////////////////////////////////////////////////////////////////////////
void setup(void) {
    game = new Game();
    
}

void rotate(pe_vec2 &a, float theta){
    float x = cos(theta)*a.x +(-1*sin(theta))*a.y +(1-cos(theta))*240 +sin(theta)*240;

    float y = sin(theta)*a.x +cos(theta)*a.y +(-1*sin(theta))*240 + (1-cos(theta))*240;

    a.x = x;
    a.y = y;
}


void pe_drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int scalex, int scaley){
       const int diameter = (radius * 2);

       int x = (radius - 1);
       int y = 0;
       int tx = 1;
       int ty = 1;
       int error = (tx - diameter);

       while (x >= y) {
	
	  //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	  /*  Each of the following renders an octant of the circle */
	  SDL_RenderDrawPoint(renderer, scalex*(centerX + x), scaley*(centerY - y));
	  SDL_RenderDrawPoint(renderer, scalex*(centerX + x), scaley*(centerY + y));
	  SDL_RenderDrawPoint(renderer, scalex*(centerX - x), scaley*(centerY - y));
	  SDL_RenderDrawPoint(renderer, scalex*(centerX - x), scaley*(centerY + y));
	  SDL_RenderDrawPoint(renderer, scalex*(centerX + y), scaley*(centerY - x));
	  SDL_RenderDrawPoint(renderer, scalex*(centerX + y), scaley*(centerY + x));
	  SDL_RenderDrawPoint(renderer, scalex*(centerX - y), scaley*(centerY - x));
	  SDL_RenderDrawPoint(renderer, scalex*(centerX - y), scaley*(centerY + x));

	  if (error <= 0) {
	     ++y;
	     error += ty;
	     ty += 2;
	  }

	  if (error > 0) {
	     --x;
	     tx += 2;
	     error += (tx - diameter);
	  }
    }
}

///////////////////////////////////////////////////////////////////////////////
// Main function
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* args[]) {

    

    
    setup();
    /*
    AABB a1;
    a1.min.x = 200;
    a1.min.y = 200;
    a1.max.x = 250;
    a1.max.y = 250;

    AABB b1;
    b1.min.x = 200;
    b1.min.y = 400;
    b1.max.x = 250;
    b1.max.y = 450;

    circle c1;
    c1.radius = 20;
    c1.position.x = 240;
    c1.position.y = 240;

    circle c2;
    c2.radius = 20;
    c2.position.x = 240;
    c2.position.y = 440;
    */

    game->init("game", 480, 480, 1, 1);
    while(game->isRunning()){

        //poll events
        game->handleEvents();
        //update
        game->update();
        /*
        c1.position.y += 1; 
        c2.position.y -= 1;

        */




       
        
        SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
        SDL_RenderClear(game->renderer);

        /*
        if (CirclevsCircle(c1, c2)){
            SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
        }
        else{
            SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
        }


        pe_drawCircle(game->renderer, c1.position.x, c1.position.y, 20, game->getScalex(), game->getScaley());
        pe_drawCircle(game->renderer, c2.position.x, c2.position.y, 20, game->getScalex(), game->getScaley());
        
        */
        SDL_RenderPresent(game->renderer);
        
        
        //rendering
    }
    game->clean();
    return 0;
}
