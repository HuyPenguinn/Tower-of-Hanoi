#pragma once
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;
extern SDL_Texture *Background;
extern SDL_Rect rect5, rect4, rect3, rect2, rect1;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern std::vector <int> col1, col2, col3;
extern SDL_Texture *Disk1, *Disk2, *Disk3, *Disk4, *Disk5;
extern SDL_Texture *RedPole, *GreenPole;

void Init();
void CleanUp();
void BlendRect(SDL_Rect *rct, int r, int g, int b);