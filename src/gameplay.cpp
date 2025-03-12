#include "global_var.h"
#include "def.h"
#include "gameplay.h"
#include "draw.h"
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