#include "object.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

void Init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
};

void Disk::Render(){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer,&box);
};