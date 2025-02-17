#include "define.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

std::string BasePath = SDL_GetBasePath();

Pole pol1, pol2, pol3;
int CurrentDisk = 0;
bool isRunning = true;
int isHolding = 0;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
SDL_Texture *Background = NULL;
SDL_Texture *Disks = NULL;
//crop the image
SDL_Rect Disk1 = {0, 50, 100, 50};
SDL_Rect Disk2 = {0, 100, 140, 50};
SDL_Rect Disk3 = {0, 150, 180, 50};
SDL_Rect Disk4 = {0, 200, 220, 50};
SDL_Rect Disk5 = {0, 250, 260, 50};

SDL_Rect *TmpRect = NULL;

SDL_Texture *RedPole = NULL;
SDL_Texture *GreenPole = NULL;


//index of the disks
SDL_Rect rect5 = {20, 410, 260, 50};
SDL_Rect rect4 = {40, 360, 220, 50};
SDL_Rect rect3 = {60, 310, 180, 50};
SDL_Rect rect2 = {80, 260, 140, 50};
SDL_Rect rect1 = {100, 210, 100, 50};

