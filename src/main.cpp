#include <windows.h>
#include <fstream>
#include <iostream>
#include "main.h"

bool isLoaded = false;

int main(int argc,char **argv){
    FreeConsole();

//////////          INITIALIZATION          //////////
    InitSDL();
    InitPoles();
    LoadMedia();
    GetConfig();
    LoadGameplayMedia();
//////////          GAMELOOP          //////////
    while(isRunning){

        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);
        SDL_GetMouseState(&x, &y);

        if(Mix_PlayingMusic() == 0)
            Mix_PlayMusic(BG_music, -1);    

        if(GUI == "MainGameplay"){
            // if(!isLoaded && GameMode == "SPEEDRUN") {
            //     ChangeMusic();
            //     isLoaded = true;
            // }
            
            MainGameplay();
        }
        else if(GUI == "MainMenu"){
            // if(!isLoaded && GameMode != "SPEEDRUN") {
            //     ChangeMusic();
            //     isLoaded = true;
            // }
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