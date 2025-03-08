#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

class Pole{
    public:
        std :: vector <int> num;
        std :: vector <SDL_Rect> disks;
        Pole(){
            num = {};
            disks = {};
        }
};

extern Pole poles[3];

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;
extern Mix_Music *BG_music;
extern Mix_Chunk *DropSound;
extern Mix_Chunk *WinSound;
extern SDL_Texture *Background;
extern SDL_Texture *Cursor;
extern SDL_Rect *TmpRect;
extern SDL_Rect rect5, rect4, rect3, rect2, rect1, Disk1, Disk2, Disk3, Disk4, Disk5;
extern SDL_Rect RedPoleSrc, GreenPoleSrc, OpenCursorSrc, CloseCursorSrc;
extern SDL_Rect FirstPole, SecondPole, ThirdPole, CursorRect, RestartRect, textRect, TimeScoreRect;
extern const int SCREEN_WIDTH, SCREEN_HEIGHT;
extern unsigned long long StartTime, CurrentTime;
extern std::vector <int> col1, col2, col3;
extern SDL_Texture *Disks;
extern SDL_Texture *textTexture;
extern SDL_Texture *ScoreTexture;
extern SDL_Texture *RestartButtonUp;
extern SDL_Texture *RestartButtonDown;
extern SDL_Texture *ColoredPole;
extern SDL_Texture *WinTexture;
extern SDL_Texture *OneStar;
extern SDL_Texture *TwoStar;
extern SDL_Texture *ThreeStar;
extern std::string BasePath;
extern std::string GameMode;
extern std::string GUI;
extern std::string CursorConfig;
extern int CurrentDisk;
extern bool isRunning, ValidDrop, OpeningCursor, RestartClicked;
extern int isHolding, target, x, y, MoveCount;
extern SDL_Color textColor, scoreColor;
extern TTF_Font *font;
extern SDL_Surface *textSurface;
extern SDL_Surface *ScoreSurface;

void InitSDL();
void InitPoles();
void LoadMedia();
void GetConfig();

void __Background();
void DrawStar(int MoveCount);
void DrawColoredPole();
void DrawCursor(bool isHolding);
void DrawAllDisks();
void DrawPole(bool isRed, int n);
void DrawMoveCount();
void DrawTime(unsigned long long time);
void DrawTimeScore(unsigned long long time);

void HoldingProcess();
void DroppingProcess();
void MoveUpdate();
void CheckValidMove();

void CleanUp();
bool Win();
void Quit();
void Restart();

void MainGameplay();
void Config();


void DebugNum();
SDL_Rect *SrcRect(int n);
std::string SetPrecison(double n);