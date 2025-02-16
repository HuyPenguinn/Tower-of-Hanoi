#include "define.h"
#include <iostream>
#include <vector>


void Init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std :: cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std :: endl;
    }
    window = SDL_CreateWindow("Tower of Hanoi", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL){
        std :: cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std :: endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL){
        std :: cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std :: endl;
    }
    std::string BasePath = SDL_GetBasePath();
    Background = IMG_LoadTexture(renderer, (BasePath + "/data/image/background.png").c_str());
    if(Background == NULL){
        std :: cout << "Background could not be created! SDL_Error: " << SDL_GetError() << std :: endl;
    }
}

void CleanUp(){
    SDL_DestroyTexture(Background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

}

void BlendRect(SDL_Rect *rct, int r, int g, int b){
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, rct);
}