#include "global_var.h"
#include "def.h"
#include "menumedia.h"
#include "howtoplay.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

SDL_Texture* GameRules = IMG_LoadTexture(renderer, (BasePath + "data/image/HowToPlay.png").c_str());

void DrawBackButton(){
    SDL_Rect BackButtonRect = {260, 400, 380, 60};
    if(!isClickingBackButton) SDL_RenderCopy(renderer, BackButton, nullRect, &BackButtonRect);
    else SDL_RenderCopy(renderer, BackButtonDown, nullRect, &BackButtonRect);
}

void DrawGameRules(){
    SDL_Rect GameRulesBackgroundRect = {0, 0, 900, 500};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &GameRulesBackgroundRect);
    SDL_Rect GameRulesRect = {100, 50, 700, 300};
    SDL_RenderCopy(renderer, GameRules, nullRect, &GameRulesRect);
}
void HowToPlay(){
    SDL_RenderCopy(renderer, MenuBackground, nullRect, nullRect);
    DrawGameRules();
    DrawBackButton();
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q){
            isRunning = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            OpeningCursor = false;
            if(event.button.button == SDL_BUTTON_LEFT){
                if(x >= 260 && x <= 640 && y >= 400 && y <= 460){
                    isClickingBackButton = true;
                }
            }
        }

        if(event.type == SDL_MOUSEBUTTONUP){
            OpeningCursor = true;
            if(event.button.button == SDL_BUTTON_LEFT){
                if(isClickingBackButton){
                    GUI = "MainMenu";
                    isClickingBackButton = false;
                }
            }
        }

    }
}