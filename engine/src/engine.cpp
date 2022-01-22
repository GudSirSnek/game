#include "engine.hpp"
#include <stdio.h>

int last_frame_time = 0;
int imgFlags = IMG_INIT_PNG;
uint32_t w_flags = 0;


Game::Game(){
    Game::window =nullptr;
    Game::renderer = nullptr;
    Game::running = false;
}

Game::~Game(){

}

void Game::init(const char *title, int width, int height){


    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        pe_printError("Failed to Initialize SDL: %s", SDL_GetError());
    }
    else if ((IMG_Init(imgFlags) & imgFlags) != imgFlags){
        pe_printFatalError("Failed to Initialize SDL_img: %s", IMG_GetError());
    }

    pe_printInfo("successfully initialized Engine", NULL);

    Game::createWindow(title, width, height);
    Game::createRenderer();

    Game::running = true;
}

SDL_Window* Game::createWindow(const char *title, int width, int height){
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, w_flags);
    if (!window){
        pe_printFatalError("ERROR INITIALIZING WINDOW.", SDL_GetError());
        return NULL;
    }
    return window;
}

SDL_Renderer* Game::createRenderer(void){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer){
        pe_printFatalError("ERROR INITIALIZING RENDERER.", SDL_GetError());
        return NULL;
    }

    return renderer;
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                Game::running = false;
                break;
            default:
                break;
        }
}
void Game::update(void) {
    // Calculate how much we have to wait until we reach the target frame time
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    // Only delay if we are too fast too update this frame
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        SDL_Delay(time_to_wait);

    // Get a delta time factor converted to seconds to be used to update my objects
    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0;

    // Store the milliseconds of the current frame
    last_frame_time = SDL_GetTicks();
    //printf("\n");
}

void Game::render(){
    SDL_RenderClear(Game::renderer);

    //rendering

    SDL_RenderPresent(Game::renderer);
}

bool Game::isRunning(){
    return Game::running;
}

void Game::clean(void){
    pe_printNeutral("closing renderer, window, SDL", NULL);
    SDL_DestroyRenderer(Game::renderer);
    pe_printNeutral("renderer uninitialized",NULL);
    SDL_DestroyWindow(Game::window);
    pe_printNeutral("window uninitialized",NULL);
    IMG_Quit();
    pe_printNeutral("SDL_IMG uninitialized",NULL);
    SDL_Quit();
    pe_printNeutral("SDL uninitialized",NULL);

    pe_printInfo("Engine successfully uninitialized",NULL);
}