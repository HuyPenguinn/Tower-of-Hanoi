#include "global_var.h"
#include "media.h"

Mix_Music *BG_music = nullMusic;
Mix_Chunk *DropSound = nullChunk;
Mix_Chunk *WinSound = nullChunk;
TTF_Font *font = nullFont;

SDL_Texture *RestartButtonUp = nullTexture;
SDL_Texture *RestartButtonDown = nullTexture;
SDL_Texture *HomeButtonUp = nullTexture;
SDL_Texture *HomeButtonDown = nullTexture;
SDL_Texture *Background = nullTexture;
SDL_Texture *Disks = nullTexture;
SDL_Texture *WinTexture = nullTexture;
SDL_Texture *ColoredPole = nullTexture;
SDL_Texture *OneStar = nullTexture;
SDL_Texture *TwoStar = nullTexture;
SDL_Texture *ThreeStar = nullTexture;
SDL_Texture *Cursor = nullTexture;
SDL_Texture *CloudBackground = nullTexture;
SDL_Texture *textTexture = nullTexture;
SDL_Texture *ScoreTexture = nullTexture;
SDL_Surface *textSurface = nullSurface;
SDL_Surface *ScoreSurface = nullSurface;

SDL_Color textColor = {255, 255, 255, 255}, scoreColor = {255, 0, 0, 255};