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
    if(CursorConfig == "Default") Cursor = IMG_LoadTexture(renderer, (BasePath + "/data/image/cursor.png").c_str());
    
    
    font = TTF_OpenFont((BasePath + "/data/font/8514oem.ttf").c_str(), 32);
    
    Disks = IMG_LoadTexture(renderer, (BasePath + "/data/image/disks.png").c_str());

    Background = IMG_LoadTexture(renderer, (BasePath + "/data/image/background.png").c_str());
    int CloudID = rand() % 8;
    switch(CloudID){
        case 1:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-1.png").c_str());
            break;
        case 2:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-2.png").c_str());
            break;
        case 3:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-3.png").c_str());
            break;
        case 4:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-4.png").c_str());
            break;
        case 5:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-5.png").c_str());
            break;
        case 6:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-6.png").c_str());
            break;
        case 7:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-7.png").c_str());
            break;
        case 8:
            CloudBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/Clouds/Clouds-8.png").c_str());
            break;
        default:
            std::cout << "Error: CloudID" << std::endl;
            std::cout << CloudID << std::endl;
            break;
    }

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