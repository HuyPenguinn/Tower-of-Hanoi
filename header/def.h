#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

class Pole{
    public:
        std :: vector <int> num;
        std :: vector <SDL_Rect> disks;
};

extern Pole poles[3];

extern SDL_Rect rect5, rect4, rect3, rect2, rect1, Disk1, Disk2, Disk3, Disk4, Disk5;
extern SDL_Rect RedPoleSrc, GreenPoleSrc, OpenCursorSrc, CloseCursorSrc;
extern SDL_Rect FirstPole, SecondPole, ThirdPole, CursorRect, RestartRect, textRect, TimeScoreRect;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern unsigned long long StartTime, CurrentTime;
extern std::vector <int> col1, col2, col3;
extern std::string BasePath;
extern int CurrentDisk;
extern int CloudID;
// extern SDL_Color textColor, scoreColor;

void HoldingProcess();
void DroppingProcess();
void MoveUpdate();
void CheckValidMove();

bool Win();
void Restart();

void DebugNum();
SDL_Rect *SrcRect(int n);
std::string SetPrecison(double n);