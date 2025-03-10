#include "def.h"

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

std::string BasePath = SDL_GetBasePath();
std::string GameMode = "";
std::string CursorConfig = "";
std::string GUI = "MainGameplay";

Pole poles[3];
unsigned long long StartTime = 0, CurrentTime = 0;
int CurrentDisk = 0;
bool isRunning = true, ValidDrop = true, OpeningCursor = true, RestartClicked = false;
bool GAMESTARTED = false;
int isHolding = 0;
int target = 0;
int x, y, MoveCount = 0;

SDL_Window *window = NULL;
Mix_Music *BG_music = NULL;
Mix_Chunk *DropSound = NULL;
Mix_Chunk *WinSound = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;
SDL_Texture *RestartButtonUp = NULL;
SDL_Texture *RestartButtonDown = NULL;
SDL_Texture *Background = NULL;
SDL_Texture *Disks = NULL;
SDL_Texture *WinTexture = NULL;
SDL_Texture *ColoredPole = NULL;
SDL_Texture *OneStar = NULL;
SDL_Texture *TwoStar = NULL;
SDL_Texture *ThreeStar = NULL;
SDL_Texture *Cursor = NULL;
SDL_Texture *CloudBackground = NULL;
SDL_Texture *textTexture = NULL;
SDL_Texture *ScoreTexture = NULL;
SDL_Surface *textSurface = NULL;
SDL_Surface *ScoreSurface = NULL;

SDL_Color textColor = {255, 255, 255, 255}, scoreColor = {255, 0, 0, 255};
TTF_Font *font = NULL;

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