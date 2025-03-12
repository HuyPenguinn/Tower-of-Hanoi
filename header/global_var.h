#pragma once
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"


extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event event;
extern int x, y;
extern std::string GameMode;
extern std::string CursorConfig;
extern std::string GUI;

extern bool isRunning, ValidDrop, OpeningCursor, RestartClicked, GAMESTARTED;
extern int isHolding, target, MoveCount;

extern SDL_Rect* nullRect;
extern SDL_Window* nullWindow;
extern SDL_Renderer* nullRenderer;
extern SDL_Texture* nullTexture;
extern SDL_Surface* nullSurface;
extern Mix_Music* nullMusic;
extern Mix_Chunk* nullChunk;
extern TTF_Font* nullFont;