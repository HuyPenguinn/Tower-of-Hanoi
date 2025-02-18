#include "define.h"
#include <iostream>
int main(int argc,char **argv){
    InitSDL();
    InitPoles();
    while(isRunning){
        if(TmpRect == NULL) TmpRect = new SDL_Rect;

        SDL_SetRenderDrawColor(renderer, 180, 220, 255, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, Background, NULL, NULL);

        EventProcess();

        DrawColoredPole();
        DrawAllDisks();

        if(GameMode == "NORMAL"){
            if(Win()){
                SDL_RenderCopy(renderer, WinTexture, NULL, NULL);
                DrawStar(MoveCount);
            }
        }else if(GameMode == "SPEEDRUN"){
            // Speedrun mode
        }

        DrawCursor();

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    
    CleanUp();

    return 0;
}