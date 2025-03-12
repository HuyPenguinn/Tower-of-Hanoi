#include "global_var.h"
#include "def.h"
#include "gameplay.h"
#include "draw.h"

void LoadGameplayMedia(){
    font = TTF_OpenFont((BasePath + "/data/font/8514oem.ttf").c_str(), 32);
    
    Disks = IMG_LoadTexture(renderer, (BasePath + "/data/image/disks.png").c_str());
    
    Background = IMG_LoadTexture(renderer, (BasePath + "/data/image/background.png").c_str());
    

    RestartButtonUp = IMG_LoadTexture(renderer, (BasePath + "/data/image/restart.png").c_str());
    RestartButtonDown = IMG_LoadTexture(renderer, (BasePath + "/data/image/restart_down.png").c_str());

    ColoredPole = IMG_LoadTexture(renderer, (BasePath + "/data/image/poles.png").c_str());
    WinTexture = IMG_LoadTexture(renderer, (BasePath + "/data/image/win.png").c_str());
    OneStar = IMG_LoadTexture(renderer, (BasePath + "/data/image/1star.png").c_str());
    TwoStar = IMG_LoadTexture(renderer, (BasePath + "/data/image/2stars.png").c_str());
    ThreeStar = IMG_LoadTexture(renderer, (BasePath + "/data/image/3stars.png").c_str());
    
    if(GameMode == "NORMAL") BG_music = Mix_LoadMUS((BasePath + "/data/audio/BGmusic.mp3").c_str());
    else if(GameMode == "SPEEDRUN") BG_music = Mix_LoadMUS((BasePath + "/data/audio/BGmusic2.mp3").c_str());

    DropSound = Mix_LoadWAV((BasePath + "/data/audio/Droplet.wav").c_str());
}

void MainGameplay(){
    
    __Background();
    DrawColoredPole();
    DrawAllDisks();

//////////          WIN          //////////
    if (Win()) {
        SDL_RenderCopy(renderer, WinTexture, nullRect, nullRect); 

        if (GameMode == "NORMAL") DrawStar(MoveCount);
        else if (GameMode == "SPEEDRUN") DrawTimeScore(CurrentTime);
        
    }


//////////          EVENT          //////////
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
            OpeningCursor = false;
            if(x >= 840 && x <= 880 && y >= 20 && y <= 60){// Restart button
                Mix_PlayChannel(-1, DropSound, 0);
                Restart();
                continue;
            }
            if(Win()){
                Restart();
            }else{
                HoldingProcess();
            }
        }
        if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT){
            OpeningCursor = true;
            if(RestartClicked){
                RestartClicked = false;
                continue;
            }
            SDL_GetMouseState(&x, &y);
            DroppingProcess();
        }
        if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_r){
                Restart();
                RestartClicked = false;
            }
            if(event.key.keysym.sym == SDLK_q){
                isRunning = false;
            }
        }
    }
    CheckValidMove();
}