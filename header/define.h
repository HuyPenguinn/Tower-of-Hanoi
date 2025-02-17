#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
using namespace std;

class Pole{
    public:
        std :: vector <int> num;
        std :: vector <SDL_Rect> disks;
        Pole(){
            num = {};
            disks = {};
        }
};

extern Pole pol1, pol2, pol3;
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;
extern SDL_Texture *Background;
extern SDL_Rect *TmpRect;
extern SDL_Rect rect5, rect4, rect3, rect2, rect1, Disk1, Disk2, Disk3, Disk4, Disk5;
extern SDL_Rect RedPoleSrc, GreenPoleSrc;
extern SDL_Rect FirstPole, SecondPole, ThirdPole;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern std::vector <int> col1, col2, col3;
extern SDL_Texture *Disks;
extern SDL_Texture *ColoredPole;
extern std::string BasePath;
extern int CurrentDisk;
extern bool isRunning, ValidDrop;
extern int isHolding, target, x, y;

void Init();
void CleanUp();
void DrawAllDisks();
void HoldingProcess();
void DroppingProcess();
void DrawPole(bool isRed, int n);
SDL_Rect *SrcRect(int n);