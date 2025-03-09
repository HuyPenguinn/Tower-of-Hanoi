#include "def.h"
#include <iomanip>
void InitSDL(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    
    window = SDL_CreateWindow("Tower of Hanoi", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
}

void InitPoles(){
    poles[0].num = {5, 4, 3, 2, 1};
    poles[1].num = {};
    poles[2].num = {};
    poles[0].disks = {rect5, rect4, rect3, rect2, rect1};
    poles[1].disks = {};
    poles[2].disks = {};
}

void CleanUp(){
    Mix_FreeMusic(BG_music);
    Mix_FreeChunk(DropSound);
    TTF_CloseFont(font);
    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(ScoreSurface);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(Background);
    SDL_DestroyTexture(Disks);
    SDL_DestroyTexture(ColoredPole);
    SDL_DestroyTexture(Cursor);
    SDL_DestroyTexture(RestartButtonUp);
    SDL_DestroyTexture(RestartButtonDown);
    SDL_DestroyTexture(WinTexture);
    SDL_DestroyTexture(OneStar);
    SDL_DestroyTexture(TwoStar);
    SDL_DestroyTexture(ThreeStar);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Restart(){
    StartTime = SDL_GetTicks();
    GAMESTARTED = false;
    RestartClicked = true;
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
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

void DebugNum(){
    
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < poles[k].num.size(); i++){
            std::cout << poles[k].num[i] << " ";
        }
        std::cout << "| ";
    }
    std::cout << std::endl;
}

std::string SetPrecison(double n){
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << n;
    return ss.str();
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