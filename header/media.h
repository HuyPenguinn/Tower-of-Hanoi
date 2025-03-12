#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

extern SDL_Texture *Background;
extern SDL_Texture *Cursor;

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
extern SDL_Texture *CloudBackground;
extern SDL_Texture *MenuBackground;


extern SDL_Color textColor, scoreColor;

extern SDL_Surface *textSurface;
extern SDL_Surface *ScoreSurface;

extern Mix_Music *BG_music;
extern Mix_Chunk *DropSound;
extern Mix_Chunk *WinSound;
extern TTF_Font *font;