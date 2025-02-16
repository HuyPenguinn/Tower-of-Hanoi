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
    if(Background == NULL){
        std :: cout << "Background could not be created! SDL_Error: " << SDL_GetError() << std :: endl;
    }

    pol1.num = {5, 4, 3, 2, 1};
    pol2.num = {};
    pol3.num = {};
    pol1.disks = {rect5, rect4, rect3, rect2, rect1};
    pol2.disks = {};
    pol3.disks = {};
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

void DrawDisk(int n){
    switch(n){
        case 1:
            SDL_RenderCopy(renderer, Disks, &Disk1, &rect1);
            break;
        case 2:
            SDL_RenderCopy(renderer, Disks, &Disk2, &rect2);
            break;
        case 3:
            SDL_RenderCopy(renderer, Disks, &Disk3, &rect3);
            break;
        case 4:
            SDL_RenderCopy(renderer, Disks, &Disk4, &rect4);
            break;
        case 5:
            SDL_RenderCopy(renderer, Disks, &Disk5, &rect5);
            break;
        default:
            break;
    }
}

void DrawAllDisks(){
    for(int i = 0; i < pol1.num.size(); i++){
        SDL_RenderCopy(renderer, Disks, SrcRect(pol1.num[i]), &pol1.disks[i]);
    }
    for(int i = 0; i < pol2.num.size(); i++){
        SDL_RenderCopy(renderer, Disks, SrcRect(pol2.num[i]), &pol2.disks[i]);
    }
    for(int i = 0; i < pol3.num.size(); i++){
        SDL_RenderCopy(renderer, Disks, SrcRect(pol3.num[i]), &pol3.disks[i]);
    }

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

SDL_Rect* DefineRect(){
    int id = 15;
    for(int i = 0; i < pol1.num.size(); i++){
        id -= pol1.num[i];
    }
    for(int i = 0; i < pol2.num.size(); i++){
        id -= pol2.num[i];
    }
    for(int i = 0; i < pol3.num.size(); i++){
        id -= pol3.num[i];
    }
    switch(id){
        case 1:
            return &rect1;
        case 2:
            return &rect2;
        case 3:
            return &rect3;
        case 4:
            return &rect4;
        case 5:
            return &rect5;
        default:
            cerr << "Error: DefineRect() : i = " << id << endl;
            return NULL;
    }
}