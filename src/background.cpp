#include "global_var.h"
#include "def.h"
#include "media.h"
#include "draw.h"
#include "main.h"

void Toolbar(){
    SDL_Rect HUDRect = {0, 0, 900, 80};
    SDL_Rect RestartRect = {840, 20, 40, 40};
    SDL_Rect HomeRect = {780, 20, 40, 40};
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 191, 255, 100);
    SDL_RenderFillRect(renderer, &HUDRect);
    if(isClickingRestartButton) SDL_RenderCopy(renderer, RestartButtonDown, nullRect, &RestartRect);
    else SDL_RenderCopy(renderer, RestartButtonUp, nullRect, &RestartRect);

    if(isCLickingHomeButton) SDL_RenderCopy(renderer, HomeButtonDown, nullRect, &HomeRect);
    else SDL_RenderCopy(renderer, HomeButtonUp, nullRect, &HomeRect);

    if(!Win() && GameMode == "SPEEDRUN" ){ 
        if(GAMESTARTED) CurrentTime = SDL_GetTicks() % 1000000000 - StartTime;
        else CurrentTime = 0;
        DrawTime(CurrentTime);
    }else if(!Win() && GameMode == "NORMAL"){
        textSurface = TTF_RenderText_Solid(font, std::to_string(MoveCount).c_str(), textColor);
        DrawMoveCount();
    }
}

int to_int(std::string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        res = res * 10 + s[i] - '0';
    }
    return res;
}

void __Background(){

    SDL_RenderCopy(renderer, CloudBackground, nullRect, nullRect);
    SDL_RenderCopy(renderer, Background, nullRect, nullRect);
    
    Toolbar();
    if(Mix_PlayingMusic() == 0){
        Mix_PlayMusic(BG_music, -1);
    }else Mix_ResumeMusic();
    Mix_VolumeMusic(to_int(BackgroundMusicConfig));
}