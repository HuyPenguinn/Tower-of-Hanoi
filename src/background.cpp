#include "global_var.h"
#include "def.h"
// #include "draw.h"
#include "media.h"
#include "draw.h"

void Toolbar(){
    SDL_Rect HUDRect = {0, 0, 900, 80};
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 191, 255, 100);
    SDL_RenderFillRect(renderer, &HUDRect);
    if(RestartClicked) SDL_RenderCopy(renderer, RestartButtonDown, nullRect, &RestartRect);
    else SDL_RenderCopy(renderer, RestartButtonUp, nullRect, &RestartRect);

    if(!Win() && GameMode == "SPEEDRUN" ){ 
        if(GAMESTARTED) CurrentTime = SDL_GetTicks() % 1000000000 - StartTime;
        else CurrentTime = 0;
        DrawTime(CurrentTime);
    }else if(!Win() && GameMode == "NORMAL"){
        textSurface = TTF_RenderText_Solid(font, std::to_string(MoveCount).c_str(), textColor);
        DrawMoveCount();
    }
}

void __Background(){

    SDL_RenderCopy(renderer, CloudBackground, nullRect, nullRect);
    SDL_RenderCopy(renderer, Background, nullRect, nullRect);
    
    Toolbar();
    
    if(Mix_PlayingMusic() == 0){
        Mix_PlayMusic(BG_music, -1);
    }else Mix_ResumeMusic();

    Mix_VolumeMusic(40);
}