#include "def.h"
int main(int argc,char **argv){
//////////          INITIALIZATION          //////////
    InitSDL();
    InitPoles();

//////////          GAMELOOP          //////////
    while(isRunning){
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, Background, NULL, NULL);
        
        if(Mix_PlayingMusic() == 0){
            Mix_PlayMusic(BG_music, -1);
        }else Mix_ResumeMusic();

        Mix_VolumeMusic(40);

    //////////          DRAW          //////////
        DrawColoredPole();
        DrawAllDisks();

    //////////          WIN          //////////
        if(GameMode == "NORMAL"){
            if(Win()){
                SDL_RenderCopy(renderer, WinTexture, NULL, NULL);
                DrawStar(MoveCount);
            }
        }else if(GameMode == "SPEEDRUN"){
            // Speedrun mode
        }

    //////////          EVENT          //////////
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                isRunning = false;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                OpeningCursor = false;
                if(Win()){
                    Restart();
                }else{
                    HoldingProcess();
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT){
                OpeningCursor = true;
                DroppingProcess();
            }
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_r){
                    Restart();
                }
                if(event.key.keysym.sym == SDLK_q){
                    isRunning = false;
                }
            }
        }

        // DebugNum();

        CheckValidMove();
        DrawCursor(!OpeningCursor);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

//////////          CLEANUP          //////////
    delete TmpRect;
    CleanUp();
    Quit();
    return 0;
}