#include "global_var.h"

SDL_Rect* nullRect = nullptr;
SDL_Window* nullWindow = nullptr;
SDL_Renderer* nullRenderer = nullptr;
SDL_Texture* nullTexture = nullptr;
SDL_Surface* nullSurface = nullptr;
Mix_Music* nullMusic = nullptr;
Mix_Chunk* nullChunk = nullptr;
TTF_Font* nullFont = nullptr;
SDL_Event event;
SDL_Window *window = nullWindow;
SDL_Renderer *renderer = nullRenderer;
std::string BasePath = SDL_GetBasePath();
std::string MaxStar = "";
std::string GameMode = "";
std::string CursorConfig = "";
std::string BackgroundMusicConfig = "";
std::string SoundEffectConfig = "";
std::string GUI = "MainMenu";
bool GAMESTARTED = false;
int isHolding = 0;
int target = 0;
int x, y, MoveCount = 0;
bool isRunning = true, ValidDrop = true, OpeningCursor = true, RestartClicked = false;