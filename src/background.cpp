#include "def.h"

void Toolbar(){
    if(RestartClicked) SDL_RenderCopy(renderer, RestartButtonDown, NULL, &RestartRect);
    else SDL_RenderCopy(renderer, RestartButtonUp, NULL, &RestartRect);

    if(!Win() && GameMode == "SPEEDRUN"){ 
        CurrentTime = SDL_GetTicks() - StartTime;
        DrawTime(CurrentTime);
    }else if(!Win() && GameMode == "NORMAL"){
        textSurface = TTF_RenderText_Solid(font, std::to_string(MoveCount).c_str(), textColor);
        DrawMoveCount();
    }
}

void __Background(){
    SDL_RenderCopy(renderer, Background, NULL, NULL);

    Toolbar();
    
    if(Mix_PlayingMusic() == 0){
        Mix_PlayMusic(BG_music, -1);
    }else Mix_ResumeMusic();

    Mix_VolumeMusic(40);
}