#include "define.h"
#include <iostream>

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

std :: vector <int> col1;
std :: vector <int> col2;
std :: vector <int> col3;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
SDL_Texture *Background = NULL;
SDL_Texture *Disk1 = NULL;
SDL_Texture *Disk2 = NULL;
SDL_Texture *Disk3 = NULL;
SDL_Texture *Disk4 = NULL;
SDL_Texture *Disk5 = NULL;
SDL_Texture *RedPole = NULL;
SDL_Texture *GreenPole = NULL;

SDL_Rect rect5 = {20, 410, 260, 50};
SDL_Rect rect4 = {40, 360, 220, 50};
SDL_Rect rect3 = {60, 310, 180, 50};
SDL_Rect rect2 = {80, 260, 140, 50};
SDL_Rect rect1 = {100, 210, 100, 50};