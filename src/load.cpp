#include "def.h"
#include <fstream>

void GetConfig(){
    std::ifstream ifs((BasePath + "/data/config.txt").c_str());
    std::string s;
    getline(ifs, s);// GameMode
    for(int i = 12; i < s.size() - 1; i++){
        GameMode += s[i];
    }
    // std::cout << GameMode << std::endl;
    getline(ifs, s);// CursorConfig
    for(int i = 10; i < s.size() - 1; i++){
        CursorConfig += s[i];
    }
    ifs.close();
}

void LoadMedia(){
    if(CursorConfig == "Default") SDL_ShowCursor(SDL_DISABLE);
    else if(CursorConfig == "Window") SDL_ShowCursor(SDL_ENABLE);
    font = TTF_OpenFont((BasePath + "/data/font/8514oem.ttf").c_str(), 32);
    if(CursorConfig == "Default") Cursor = IMG_LoadTexture(renderer, (BasePath + "/data/image/cursor.png").c_str());
    Disks = IMG_LoadTexture(renderer, (BasePath + "/data/image/disks.png").c_str());
    Background = IMG_LoadTexture(renderer, (BasePath + "/data/image/background.png").c_str());
    RestartButtonUp = IMG_LoadTexture(renderer, (BasePath + "/data/image/restart.png").c_str());
    RestartButtonDown = IMG_LoadTexture(renderer, (BasePath + "/data/image/restart_down.png").c_str());
    ColoredPole = IMG_LoadTexture(renderer, (BasePath + "/data/image/poles.png").c_str());
    WinTexture = IMG_LoadTexture(renderer, (BasePath + "/data/image/win.png").c_str());
    OneStar = IMG_LoadTexture(renderer, (BasePath + "/data/image/1star.png").c_str());
    TwoStar = IMG_LoadTexture(renderer, (BasePath + "/data/image/2stars.png").c_str());
    ThreeStar = IMG_LoadTexture(renderer, (BasePath + "/data/image/3stars.png").c_str());
    if(GameMode == "NORMAL") BG_music = Mix_LoadMUS((BasePath + "/data/audio/BGmusic.mp3").c_str());
    else if(GameMode == "SPEEDRUN") BG_music = Mix_LoadMUS((BasePath + "/data/audio/BGmusic2.mp3").c_str());
    if(BG_music == NULL) std::cout << "Error: " << Mix_GetError() << std::endl;
    DropSound = Mix_LoadWAV((BasePath + "/data/audio/Droplet.wav").c_str());
}