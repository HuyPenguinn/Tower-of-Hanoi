#include <windows.h>
#include <fstream>
#include <iostream>
#include "main.h"
int main(int argc,char **argv){
    // FreeConsole();

//////////          INITIALIZATION          //////////
    InitSDL();
    InitPoles();
    LoadMedia();
    GetConfig();

    bool isLoaded = false;
//////////          GAMELOOP          //////////
    while(isRunning){

        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);
        SDL_GetMouseState(&x, &y);

        if(GUI == "MainGameplay") {
            if(!isLoaded) {
                LoadGameplayMedia();
                isLoaded = true;
            }
            MainGameplay();
        }
        else if(GUI == "MainMenu"){
            MainMenu();
        }
        else if(GUI == "Config"){
            Config();
            UpdateConfig();
            GetConfig();
        }
        else if(GUI == "HowToPlay"){
            // HowToPlay Window
        }else if(GUI == "ChooseGamemode"){
            ChooseGamemode();
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