#include "def.h"

void __Background(){
    SDL_RenderCopy(renderer, Background, NULL, NULL);
    if(RestartClicked) SDL_RenderCopy(renderer, RestartButtonDown, NULL, &RestartRect);
    else SDL_RenderCopy(renderer, RestartButtonUp, NULL, &RestartRect);

    
    if(Mix_PlayingMusic() == 0){
        Mix_PlayMusic(BG_music, -1);
    }else Mix_ResumeMusic();

    Mix_VolumeMusic(40);
}