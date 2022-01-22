#include <engine.hpp>
#include <stdio.h>

Game *game = nullptr;



///////////////////////////////////////////////////////////////////////////////
// Setup function that runs once at the beginning of our program
///////////////////////////////////////////////////////////////////////////////
void setup(void) {
    game = new Game();
    
}

///////////////////////////////////////////////////////////////////////////////
// Main function
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* args[]) {

    

    
    setup();
    game->init("game", 480, 480);
    while(game->isRunning()){
        //poll events
        game->handleEvents();
        //update
        game->update();

        
        //rendering
    }
    game->clean();
    return 0;
}
