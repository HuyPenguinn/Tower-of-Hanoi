#include "def.h"
using namespace std;
int main(int argc,char **argv){
//////////          INITIALIZATION          //////////
    InitSDL();
    InitPoles();
    GetConfig();
    LoadMedia();
    

//////////          GAMELOOP          //////////
    while(isRunning){
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);
        SDL_GetMouseState(&x, &y);
    //////////          DRAW          //////////
        __Background();
        DrawColoredPole();
        DrawAllDisks();

    //////////          WIN          //////////
        if(GameMode == "NORMAL"){
            if(Win()){
                SDL_RenderCopy(renderer, WinTexture, NULL, NULL);
                DrawStar(MoveCount);
            }
            textSurface = TTF_RenderText_Solid(font, to_string(MoveCount).c_str(), textColor);
        }else if(GameMode == "SPEEDRUN"){
            // Speedrun mode

        }
        DrawMoveCount();

    //////////          EVENT          //////////
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                isRunning = false;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                OpeningCursor = false;
                if(x >= 840 && x <= 880 && y >= 20 && y <= 60){
                    
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

        // DebugNum();

        if(CursorConfig != "Window") DrawCursor(!OpeningCursor);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

//////////          CLEANUP          //////////
    delete TmpRect;
    CleanUp();
    Quit();
    return 0;
}