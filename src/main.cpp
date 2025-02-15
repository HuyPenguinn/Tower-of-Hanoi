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
SDL_Texture *pole = NULL;

SDL_Rect rect5 = {20, 410, 260, 50};
SDL_Rect rect4 = {40, 360, 220, 50};
SDL_Rect rect3 = {60, 310, 180, 50};
SDL_Rect rect2 = {80, 260, 140, 50};
SDL_Rect rect1 = {100, 210, 100, 50};

void Init();
void CleanUp();
void BlendRect(SDL_Rect *rct, int r, int g, int b);

int main(int argc,char **argv){
   
    Init();

    bool isRunning = true;
    while(isRunning){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                isRunning = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 180, 220, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, pole, NULL, NULL);

        BlendRect(&rect1, 255, 230, 153);
        BlendRect(&rect2, 255, 215, 128);
        BlendRect(&rect3, 255, 200, 102);
        BlendRect(&rect4, 255, 185, 77);
        BlendRect(&rect5, 255, 170, 51);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    
    CleanUp();

    return 0;
}

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
    pole = IMG_LoadTexture(renderer, (BasePath + "/data/image/background.png").c_str());
    if(pole == NULL){
        std :: cout << "Background could not be created! SDL_Error: " << SDL_GetError() << std :: endl;
    }
}

void CleanUp(){
    SDL_DestroyTexture(pole);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

}

void BlendRect(SDL_Rect *rct, int r, int g, int b){
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, rct);
}