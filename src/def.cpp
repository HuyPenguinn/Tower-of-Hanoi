#include "global_var.h"
#include "def.h"
#include "draw.h"
#include "win.h"
#include "gameplay.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

Pole poles[3];
unsigned long long StartTime = 0, CurrentTime = 0;
int CurrentDisk = 0;

//crop the image
SDL_Rect Disk1 = {0, 50, 100, 50};
SDL_Rect Disk2 = {0, 100, 140, 50};
SDL_Rect Disk3 = {0, 150, 180, 50};
SDL_Rect Disk4 = {0, 200, 220, 50};
SDL_Rect Disk5 = {0, 250, 260, 50};
SDL_Rect RedPoleSrc = {0, 40, 40, 300};
SDL_Rect GreenPoleSrc = {40, 40, 40, 300};
SDL_Rect OpenCursorSrc = {0, 0, 40, 60};
SDL_Rect CloseCursorSrc = {50, 0, 40, 60};
SDL_Rect RestartRect = {840, 20, 40, 40};

SDL_Rect CursorRect = {x - 20, y - 30, 40, 60};
SDL_Rect FirstPole = {130, 160, 40, 300};
SDL_Rect SecondPole = {430, 160, 40, 300};
SDL_Rect ThirdPole = {730, 160, 40, 300};

SDL_Rect *TmpRect = new SDL_Rect;


//index of the disks
SDL_Rect rect5 = {20, 410, 260, 50};
SDL_Rect rect4 = {40, 360, 220, 50};
SDL_Rect rect3 = {60, 310, 180, 50};
SDL_Rect rect2 = {80, 260, 140, 50};
SDL_Rect rect1 = {100, 210, 100, 50};