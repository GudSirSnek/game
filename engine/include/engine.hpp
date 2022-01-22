#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "util.hpp"
#include "maths.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FALSE 0
#define TRUE 1

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)


class Game
{
    SDL_Window* window;
    bool running;

    public:
        SDL_Renderer* renderer;


        Game();

        void init(const char *title, int width, int height);

        SDL_Window* createWindow(const char *title, int width, int height);
        SDL_Renderer* createRenderer(void);

        void handleEvents();
        void update();

        void render();

        bool isRunning();

        void clean(void);

        void clearScreen(int r, int g, int b, int a);
        void startRender(void);
        void endRender(void);

        ~Game();

};
