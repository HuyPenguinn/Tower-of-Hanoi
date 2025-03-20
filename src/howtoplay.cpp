#include "global_var.h"
#include "def.h"
#include "menumedia.h"


void DrawBackButton(){
    SDL_Rect BackButtonRect = {260, 400, 380, 60};
    if(!isClickingBackButton) SDL_RenderCopy(renderer, BackButton, nullRect, &BackButtonRect);
    else SDL_RenderCopy(renderer, BackButtonDown, nullRect, &BackButtonRect);
}

void HowToPlay(){
    SDL_RenderCopy(renderer, MenuBackground, nullRect, nullRect);
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