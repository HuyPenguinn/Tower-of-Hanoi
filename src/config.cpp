#include "global_var.h"
#include "def.h"
#include "media.h"
#include "menumedia.h"
#include "config.h"
#include <fstream>

SDL_Texture *ConfigButton_BGMusic = IMG_LoadTexture(renderer, (BasePath + "/data/image/MenuButtons/ConfigButton_BGMusic.png").c_str());
SDL_Texture *ConfigButton_SoundEffect = IMG_LoadTexture(renderer, (BasePath + "/data/image/MenuButtons/ConfigButton_SoundEffect.png").c_str());
SDL_Texture *ConfigButton_Cursor = IMG_LoadTexture(renderer, (BasePath + "/data/image/MenuButtons/ConfigButton_Cursor.png").c_str());

void UpdateConfig(){
    std::ofstream ofs((BasePath + "/data/config.txt").c_str());
    ofs << "Max Star = \"" << MaxStar << "\"" << std::endl;
    ofs << "CursorConfig = " << "\"" << CursorConfig << "\"" << std::endl;
    if(BackgroundMusicConfig != "0") ofs << "Background Music = \"" << BackgroundMusicConfig << "\"" << std::endl;
    else ofs << "Background Music = \"0\"" << std::endl;
    if(SoundEffectConfig != "0") ofs << "Sound Effect = \"" << SoundEffectConfig << "\"" << std::endl;
    else ofs << "Sound Effect = \"0\"" << std::endl;
    ofs.close();
}

void DrawConfigButtons(){
    SDL_Rect BackButtonRect = {260, 400, 380, 60};
    if(!isClickingBackButton) SDL_RenderCopy(renderer, BackButton, nullRect, &BackButtonRect);
    else SDL_RenderCopy(renderer, BackButtonDown, nullRect, &BackButtonRect);

    SDL_Rect BackgroundMusicLine = {320, 100, 500, 20};
    SDL_Rect SoundEffectLine = {320, 200, 500, 20};

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &BackgroundMusicLine);
    SDL_RenderFillRect(renderer, &SoundEffectLine);

}

void Config(){
    SDL_RenderCopy(renderer, MenuBackground, nullRect, nullRect);

    DrawConfigButtons();

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q){
            isRunning = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT){
                if(x >= 260 && x <= 640 && y >= 400 && y <= 460){
                    isClickingBackButton = true;
                }
            }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
            if(event.button.button == SDL_BUTTON_LEFT){
                if(isClickingBackButton){
                    GUI = "MainMenu";
                    isClickingBackButton = false;
                }
            }
        }
    }
}