#pragma once
#include <vector>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
// using namespace std;

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
extern SDL_Rect RedPoleSrc, GreenPoleSrc, CursorSrc;
extern SDL_Rect FirstPole, SecondPole, ThirdPole, CursorRect;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern std::vector <int> col1, col2, col3;
extern SDL_Texture *Disks;
extern SDL_Texture *ColoredPole;
extern SDL_Texture *WinTexture;
extern std::string BasePath;
extern std::string GameMode;
extern int CurrentDisk;
extern bool isRunning, ValidDrop;
extern int isHolding, target, x, y, MoveCount;

void InitSDL();
void InitPoles();
void EventProcess();
void DrawColoredPole();
void DrawCursor();
void CleanUp();
void DrawAllDisks();
void DrawStar(int MoveCount);
void HoldingProcess();
void DroppingProcess();
void DrawPole(bool isRed, int n);
void CheckValidMove();
void Quit();
void Restart();
bool Win();
SDL_Rect *SrcRect(int n);