#include "define.h"

void InitSDL(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow("Tower of Hanoi", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Disks = IMG_LoadTexture(renderer, (BasePath + "/data/image/disks.png").c_str());
    Background = IMG_LoadTexture(renderer, (BasePath + "/data/image/background.png").c_str());
    ColoredPole = IMG_LoadTexture(renderer, (BasePath + "/data/image/poles.png").c_str());
    WinTexture = IMG_LoadTexture(renderer, (BasePath + "/data/image/win.png").c_str());
    SDL_ShowCursor(SDL_DISABLE);
}

void InitPoles(){
    pol1.num = {5, 4, 3, 2, 1};
    pol2.num = {};
    pol3.num = {};
    pol1.disks = {rect5, rect4, rect3, rect2, rect1};
    pol2.disks = {};
    pol3.disks = {};
}

void CleanUp(){
    SDL_DestroyTexture(Background);
    SDL_DestroyTexture(Disks);
    SDL_DestroyTexture(ColoredPole);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Restart(){
    rect1 = {100, 210, 100, 50};
    rect2 = {80, 260, 140, 50};
    rect3 = {60, 310, 180, 50};
    rect4 = {40, 360, 220, 50};
    rect5 = {20, 410, 260, 50};
    InitPoles();
    MoveCount = 0;
    isHolding = 0;
    CurrentDisk = 0;
    ValidDrop = true;
}

void Quit(){
    IMG_Quit();
    SDL_Quit();
}

SDL_Rect* SrcRect(int n){
    switch(n){
        case 1:
            return &Disk1;
        case 2:
            return &Disk2;
        case 3:
            return &Disk3;
        case 4:
            return &Disk4;
        case 5:
            return &Disk5;
        default:
            return NULL;
    }
}