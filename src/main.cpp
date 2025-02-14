#include<bits/stdc++.h>
#include "object.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
int main(int argc,char **argv){
   
    SDL_Window *window = SDL_CreateWindow("Test",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800,600,0
    );
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderDrawLine(renderer,0,0,800,600);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    return 0;
}
