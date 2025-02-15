#include "object.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


void Disk::Render(){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer,&box);
};