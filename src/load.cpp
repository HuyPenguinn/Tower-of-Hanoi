#include "global_var.h"
#include "def.h"
#include "media.h"
#include "menumedia.h"
#include <fstream>

void GetConfig(){
    std::ifstream ifs((BasePath + "/data/config.txt").c_str());
    std::string s;
    getline(ifs, s);//Max Star
    MaxStar = s[12];
    getline(ifs, s);// CursorConfig
    CursorConfig = "";
    for(int i = 16; i < s.size() - 1; i++){
        CursorConfig += s[i];
    }
    getline(ifs, s); // Background Music
    BackgroundMusicConfig = "";
    for(int i = 20; i < s.size() - 1; i++){
        BackgroundMusicConfig += s[i];
    }
    getline(ifs, s); // Sound Effect
    SoundEffectConfig = "";
    for(int i = 16; i < s.size() - 1; i++){
        SoundEffectConfig += s[i];
    }
    ifs.close();
}

void LoadClouds(){
    srand(time(0));
    int CloudID = rand() % 8 + 1;
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
}

void LoadMenuBackground(){
    int id = rand() % 4 + 1;
    switch(id){
        case 1:
            MenuBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuBG/MenuBG-1.png").c_str());
            break;
        case 2:
            MenuBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuBG/MenuBG-2.png").c_str());
            break;
        case 3:
            MenuBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuBG/MenuBG-3.png").c_str());
            break;
        case 4:
            MenuBackground = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuBG/MenuBG-4.png").c_str());
            break;
        default:
            std::cout << "Error: MenuBackground ID" << std::endl;
            std::cout << id << std::endl;
            break;
    }
}

void LoadMenuButtons(){
    StartButtonUp = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/StartButtonUp.png").c_str());
    StartButtonDown = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/StartButtonDown.png").c_str());
    
    OptionsButtonUp = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/OptionsButtonUp.png").c_str());
    OptionsButtonDown = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/OptionsButtonDown.png").c_str());
    
    HowToPlayButtonUp = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/HowToPlayButtonUp.png").c_str());
    HowToPlayButtonDown = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/HowToPlayButtonDown.png").c_str());
    
    BackButton = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/BackButton.png").c_str());
    BackButtonDown = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/BackButtonDown.png").c_str());
    
    NormalButton = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/NormalButton.png").c_str());
    NormalButtonDown = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/NormalButtonDown.png").c_str());
    
    SpeedrunButton = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/SpeedrunButton.png").c_str());
    LockedSpeedrunButton = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/LockedSpeedrunButton.png").c_str());
    SpeedrunButtonDown = IMG_LoadTexture(renderer, (BasePath + "data/image/MenuButtons/SpeedrunButtonDown.png").c_str());
}
void LoadMedia(){
    LoadClouds();
    LoadMenuBackground();
    LoadMenuButtons();

    if(CursorConfig != "Window") SDL_ShowCursor(SDL_DISABLE);
    else if(CursorConfig == "Window") SDL_ShowCursor(SDL_ENABLE);
    if(CursorConfig == "Hand") Cursor = IMG_LoadTexture(renderer, (BasePath + "/data/image/cursor.png").c_str());

}