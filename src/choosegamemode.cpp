#include "global_var.h"
#include "def.h"
#include "media.h"
#include "menumedia.h"

SDL_Texture *NormalButton = nullTexture;
SDL_Texture *NormalButtonDown = nullTexture;

SDL_Texture *SpeedrunButton = nullTexture;
SDL_Texture *SpeedrunButtonDown = nullTexture;
SDL_Texture *LockedSpeedrunButton = nullTexture;

SDL_Texture *BackButton = nullTexture;
SDL_Texture *BackButtonDown = nullTexture;

bool isClickingNormalButton = false;
bool isClickingSpeedrunButton = false;
bool isClickingBackButton = false;

void DrawGamemodeButtons(){
    SDL_Rect NormalButtonRect = {260, 240, 380, 60};
    SDL_Rect SpeedrunButtonRect = {260, 320, 380, 60};
    SDL_Rect BackButtonRect = {260, 400, 380, 60};
    if(!isClickingNormalButton) SDL_RenderCopy(renderer, NormalButton, nullRect, &NormalButtonRect);
    else SDL_RenderCopy(renderer, NormalButtonDown, nullRect, &NormalButtonRect);
    if(MaxStar == "3" && !isClickingSpeedrunButton){
        SDL_RenderCopy(renderer, SpeedrunButton, nullRect, &SpeedrunButtonRect);
    }
    else if(MaxStar == "3" && isClickingSpeedrunButton) SDL_RenderCopy(renderer, SpeedrunButtonDown, nullRect, &SpeedrunButtonRect);
    else SDL_RenderCopy(renderer, LockedSpeedrunButton, nullRect, &SpeedrunButtonRect);
    
    if(!isClickingBackButton) SDL_RenderCopy(renderer, BackButton, nullRect, &BackButtonRect);
    else SDL_RenderCopy(renderer, BackButtonDown, nullRect, &BackButtonRect);
}

bool ChooseNormal(){
    if(x >= 260 && x <= 640 && y >= 240 && y <= 300){
        return true;
    }
    return false;
}

bool ChooseSpeedrun(){
    if(x >= 260 && x <= 640 && y >= 320 && y <= 380){
        return true;
    }
    return false;
}

bool ChooseBack(){
    if(x >= 260 && x <= 640 && y >= 400 && y <= 460){
        return true;
    }
    return false;
}


void ChooseGamemode(){
    SDL_RenderCopy(renderer, MenuBackground, nullRect, nullRect);
    DrawGamemodeButtons();
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q){
            isRunning = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            OpeningCursor = false;
            if(ChooseNormal()){
                isClickingNormalButton = true;
            }else if(ChooseSpeedrun()){
                if(MaxStar == "3"){
                    isClickingSpeedrunButton = true;
                }else{
                    // Locked Speedrun Message
                }
            }else if(ChooseBack()){
                isClickingBackButton = true;
            }
        }
        
        if(event.type == SDL_MOUSEBUTTONUP){
            OpeningCursor = true;
            if(isClickingNormalButton && ChooseNormal()){
                GameMode = "NORMAL";
                GUI = "MainGameplay";
                // Mix_PauseMusic();
                ChangeMusic();
                Restart();
            }else if(isClickingSpeedrunButton && ChooseSpeedrun()){
                GameMode = "SPEEDRUN";
                GUI = "MainGameplay";
                // Mix_PauseMusic();
                ChangeMusic();
                // BG_music = Mix_LoadMUS((BasePath + "data/sound/BGmusic2.mp3").c_str());
                Restart();
            }else if(isClickingBackButton && ChooseBack()){
                GUI = "MainMenu";
            }
            isClickingNormalButton = false;
            isClickingSpeedrunButton = false;
            isClickingBackButton = false;
        }
    
    }
}