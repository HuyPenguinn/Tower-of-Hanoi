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
extern std::string MaxStar;
extern std::string GameMode;
extern std::string CursorConfig;
extern std::string BackgroundMusicConfig;
extern std::string SoundEffectConfig;
extern std::string GUI;
extern std::string BasePath;

extern bool isRunning, ValidDrop, OpeningCursor, isClickingRestartButton, GAMESTARTED, isCLickingHomeButton;
extern int isHolding, target, MoveCount;

extern SDL_Rect* nullRect;
extern SDL_Window* nullWindow;
extern SDL_Renderer* nullRenderer;
extern SDL_Texture* nullTexture;
extern SDL_Surface* nullSurface;
extern Mix_Music* nullMusic;
extern Mix_Chunk* nullChunk;
extern TTF_Font* nullFont;
extern Mix_Music *BG_music;

int to_int(std::string s);
void ChangeMusic();