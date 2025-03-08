#include "def.h"
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

        if(GUI == "MainGameplay") {
            MainGameplay();
        }
        else if(GUI == "MainMenu"){
            // Start Menu
        }
        else if(GUI == "Config"){
            // Config Window:
            // - GameMode
            // - CursorConfig
        }
        else if(GUI == "Achievement"){
            // Achievement Window
        }
        else if(GUI == "Credit"){
            // Credit Window
        }


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