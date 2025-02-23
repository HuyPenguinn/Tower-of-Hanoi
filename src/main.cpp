#include "define.h"
int main(int argc,char **argv){
//////////          INITIALIZATION          //////////
    InitSDL();
    InitPoles();

//////////          GAMELOOP          //////////
    while(isRunning){
        if(TmpRect == NULL) TmpRect = new SDL_Rect;
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, Background, NULL, NULL);

    //////////          DRAW          //////////
        DrawColoredPole();
        DrawAllDisks();
        cerr << MoveCount << endl;
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
            // if(event.type == SDL_MOUSEMOTION){
            //     DrawCursor(isHolding);
            // }
        }

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