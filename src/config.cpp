#include "global_var.h"
#include "def.h"
#include "media.h"
#include "menumedia.h"
#include "config.h"
#include <fstream>

SDL_Texture *ConfigButton_BGMusic = IMG_LoadTexture(renderer, (BasePath + "/data/image/MenuButtons/ConfigButton_BGMusic.png").c_str());
SDL_Texture *ConfigButton_SoundEffect = IMG_LoadTexture(renderer, (BasePath + "/data/image/MenuButtons/ConfigButton_SoundEffect.png").c_str());
SDL_Texture *ConfigButton_Cursor = IMG_LoadTexture(renderer, (BasePath + "/data/image/MenuButtons/ConfigButton_Cursor.png").c_str());

bool isClickingBackgroundMusicMinusButton = false;
bool isClickingBackgroundMusicPlusButton = false;
bool isClickingSoundEffectMinusButton = false;
bool isClickingSoundEffectPlusButton = false;

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

void DrawSettingButtons(int _x, int _y, int _w, int _h, bool isPlus, bool isClicking){
    SDL_Rect ButtonRect = {_x, _y, _w, _h};
    if(!isPlus){//Minus
        if(isClicking){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer, &ButtonRect);
            SDL_Rect MinusRect = {_x + 5, _y + 10, _w - 10, _h - 20};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &MinusRect);
        }else{
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderFillRect(renderer, &ButtonRect);
            SDL_Rect MinusRect = {_x + 5, _y + 10, _w - 10, _h - 20};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &MinusRect);
        }
    }
    else{//Plus
        if(isClicking){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderFillRect(renderer, &ButtonRect);
            SDL_Rect FirstPlusRect = {_x + 5, _y + 10, _w - 10, _h - 20};
            SDL_Rect SecondPlusRect = {_x + 10, _y + 5, _w - 20, _h - 10};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &FirstPlusRect);
            SDL_RenderFillRect(renderer, &SecondPlusRect);
        }else{
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &ButtonRect);
            SDL_Rect FirstPlusRect = {_x + 5, _y + 10, _w - 10, _h - 20};
            SDL_Rect SecondPlusRect = {_x + 10, _y + 5, _w - 20, _h - 10};
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &FirstPlusRect);
            SDL_RenderFillRect(renderer, &SecondPlusRect);

        }
    }
}

void DrawConfigButtons(){
    SDL_Rect BackgroundMusicLev = {320 + (BackgroundMusicConfig == "0" ? 0 : std::stoi(BackgroundMusicConfig) * 5), 90, 20, 40};
    SDL_Rect BackgroundMusicLine = {320, 100, 510, 20};
    SDL_Rect SoundEffectLev = {320 + (SoundEffectConfig == "0" ? 0 : std::stoi(SoundEffectConfig) * 5), 190, 20, 40};
    SDL_Rect SoundEffectLine = {320, 200, 510, 20};
    SDL_Rect BackButtonRect = {260, 400, 380, 60};
    
    if(!isClickingBackButton) SDL_RenderCopy(renderer, BackButton, nullRect, &BackButtonRect);
    else SDL_RenderCopy(renderer, BackButtonDown, nullRect, &BackButtonRect);
    
    SDL_SetRenderDrawColor(renderer, 112, 128, 144, 255);
    SDL_RenderFillRect(renderer, &BackgroundMusicLine);
    SDL_RenderFillRect(renderer, &SoundEffectLine);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderFillRect(renderer, &SoundEffectLev);
    SDL_RenderFillRect(renderer, &BackgroundMusicLev);
    
    DrawSettingButtons(280, 95, 30, 30, false, isClickingBackgroundMusicMinusButton);
    DrawSettingButtons(280, 195, 30, 30, false, isClickingSoundEffectMinusButton);
    DrawSettingButtons(840, 95, 30, 30, true, isClickingBackgroundMusicPlusButton);
    DrawSettingButtons(840, 195, 30, 30, true, isClickingSoundEffectPlusButton);
}
// void DrawConfigButtons(){
//     SDL_Rect BackButtonRect = {260, 400, 380, 60};
//     if(!isClickingBackButton) SDL_RenderCopy(renderer, BackButton, nullRect, &BackButtonRect);
//     else SDL_RenderCopy(renderer, BackButtonDown, nullRect, &BackButtonRect);
    
//     SDL_Rect BackgroundMusicLine = {320, 100, 500, 20};
//     SDL_Rect SoundEffectLine = {320, 200, 500, 20};

//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//     SDL_RenderFillRect(renderer, &BackgroundMusicLine);
//     SDL_RenderFillRect(renderer, &SoundEffectLine);

// }


void Config(){
    SDL_RenderCopy(renderer, MenuBackground, nullRect, nullRect);

    DrawConfigButtons();

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q){
            isRunning = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            OpeningCursor = false;
            if(event.button.button == SDL_BUTTON_LEFT){
                if(x >= 260 && x <= 640 && y >= 400 && y <= 460){
                    isClickingBackButton = true;
                }else if(x >= 280 && x <= 310 && y >= 95 && y <= 125){
                    isClickingBackgroundMusicMinusButton = true;
                    if(BackgroundMusicConfig != "0"){
                        if(std::stoi(BackgroundMusicConfig) > 0) BackgroundMusicConfig = std::to_string(std::stoi(BackgroundMusicConfig) - 5);
                    }
                }else if(x >= 280 && x <= 310 && y >= 195 && y <= 225){
                    isClickingSoundEffectMinusButton = true;
                    if(SoundEffectConfig != "0"){
                        if(std::stoi(SoundEffectConfig) > 0) SoundEffectConfig = std::to_string(std::stoi(SoundEffectConfig) - 5);
                    }
                }else if(x >= 840 && x <= 870 && y >= 95 && y <= 125){
                    isClickingBackgroundMusicPlusButton = true;
                    if(BackgroundMusicConfig != "100"){
                        if(std::stoi(BackgroundMusicConfig) < 100) BackgroundMusicConfig = std::to_string(std::stoi(BackgroundMusicConfig) + 5);
                    }
                }else if(x >= 840 && x <= 870 && y >= 195 && y <= 225){
                    isClickingSoundEffectPlusButton = true;
                    if(SoundEffectConfig != "100"){
                        if(std::stoi(SoundEffectConfig) < 100) SoundEffectConfig = std::to_string(std::stoi(SoundEffectConfig) + 5);
                    }
                }

            }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
            OpeningCursor = true;
            isClickingBackgroundMusicMinusButton = false;
            isClickingBackgroundMusicPlusButton = false;
            isClickingSoundEffectMinusButton = false;
            isClickingSoundEffectPlusButton = false;

            if(event.button.button == SDL_BUTTON_LEFT){
                if(isClickingBackButton){
                    GUI = "MainMenu";
                    isClickingBackButton = false;
                }
            }
        }
    }
}