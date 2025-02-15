#include<bits/stdc++.h>
#include "object.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

std :: vector <int> col1;
std :: vector <int> col2;
std :: vector <int> col3;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
SDL_Texture *texture = NULL;

void Init();
void GameLoop();
void CleanUp();

int main(int argc,char **argv){
   
    
    
    return 0;
}

void Init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Tower of Hanoi", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
}

void CleanUp(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GameLoop(){
    
}