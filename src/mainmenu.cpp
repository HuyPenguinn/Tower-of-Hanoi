#include "global_var.h"
#include "def.h"
#include "media.h"
#include "menumedia.h"

SDL_Rect StartButtonRect = {260, 240, 380, 60};
SDL_Rect OptionsButtonRect = {260, 320, 380, 60};
SDL_Rect HowToPlayButtonRect = {260, 400, 380, 60};
SDL_Texture *MenuBackground = nullTexture;
SDL_Texture *StartButtonUp = nullTexture;
SDL_Texture *StartButtonDown = nullTexture;
SDL_Texture *OptionsButtonUp = nullTexture;
SDL_Texture *OptionsButtonDown = nullTexture;
SDL_Texture *HowToPlayButtonUp = nullTexture;
SDL_Texture *HowToPlayButtonDown = nullTexture;
bool isClickingStartButton = false;
bool isClickingOptionsButton = false;
bool isClickingHowToPlayButton = false;

unsigned long long DelayTime = 500;
unsigned long long tmpTime = 0;
void DrawButtons(){
    if(isClickingStartButton){
        SDL_RenderCopy(renderer, StartButtonDown, nullRect, &StartButtonRect);
    }else{
        SDL_RenderCopy(renderer, StartButtonUp, nullRect, &StartButtonRect);
    }

    if(isClickingOptionsButton){
        SDL_RenderCopy(renderer, OptionsButtonDown, nullRect, &OptionsButtonRect);
    }else{
        SDL_RenderCopy(renderer, OptionsButtonUp, nullRect, &OptionsButtonRect);
    }

    if(isClickingHowToPlayButton){
        SDL_RenderCopy(renderer, HowToPlayButtonDown, nullRect, &HowToPlayButtonRect);
    }else{
        SDL_RenderCopy(renderer, HowToPlayButtonUp, nullRect, &HowToPlayButtonRect);
    }
}

void MainMenu(){
    SDL_RenderCopy(renderer, MenuBackground, nullRect, nullRect);
    DrawButtons();
    
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q){
            isRunning = false;
        }

        if(event.type == SDL_MOUSEBUTTONDOWN){
            if(x >= StartButtonRect.x && x <= StartButtonRect.x + StartButtonRect.w && y >= StartButtonRect.y && y <= StartButtonRect.y + StartButtonRect.h){

                isClickingStartButton = true;
            }else if(x >= OptionsButtonRect.x && x <= OptionsButtonRect.x + OptionsButtonRect.w && y >= OptionsButtonRect.y && y <= OptionsButtonRect.y + OptionsButtonRect.h){

                isClickingOptionsButton = true;
            }else if(x >= HowToPlayButtonRect.x && x <= HowToPlayButtonRect.x + HowToPlayButtonRect.w && y >= HowToPlayButtonRect.y && y <= HowToPlayButtonRect.y + HowToPlayButtonRect.h){
                
                isClickingHowToPlayButton = true;
            }
        }
       
        if(event.type == SDL_MOUSEBUTTONUP){
            if(isClickingStartButton){
                GUI = "ChooseGamemode";
                isClickingStartButton = false;
            }else if(isClickingOptionsButton){
                GUI = "Config";
                isClickingOptionsButton = false;
            }else if(isClickingHowToPlayButton){
                GUI = "HowToPlay";
                isClickingHowToPlayButton = false;
            }
        }
    
    }

}