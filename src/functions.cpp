#include "define.h"

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

    Disks = IMG_LoadTexture(renderer, (BasePath + "/data/image/Disks.png").c_str());
    Background = IMG_LoadTexture(renderer, (BasePath + "/data/image/background.png").c_str());
    ColoredPole = IMG_LoadTexture(renderer, (BasePath + "/data/image/poles.png").c_str());

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
            cerr << "Error: SrcRect() : n = " << n << endl;
            return NULL;
    }
}