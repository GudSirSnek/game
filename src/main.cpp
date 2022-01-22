#include <engine.hpp>
#include <stdio.h>
#include <math.h>
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

///////////////////////////////////////////////////////////////////////////////
// Main function
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* args[]) {

    

    
    setup();

    pe_vec2 line [30];

    for (int i=0; i<30; i++){
        line[i].x = 240+i;
        line[i].y = 240;
    }
    game->init("game", 480, 480);
    while(game->isRunning()){
        //poll events
        game->handleEvents();
        //update
        game->update();
        for (int i=0; i <30; i++){
            rotate(line[i], 0.1024);
        }


        SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 0);
        SDL_RenderClear(game->renderer);
        SDL_SetRenderDrawColor(game->renderer, 255, 0, 0, 255);
        for (int i=0; i <30; i++){
            SDL_RenderDrawPoint(game->renderer,line[i].x, line[i].y);
        }
        SDL_RenderPresent(game->renderer);
        
        
        //rendering
    }
    game->clean();
    return 0;
}
