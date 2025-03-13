#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

extern SDL_Texture *MenuBackground;

extern SDL_Texture *StartButtonUp;
extern SDL_Texture *StartButtonDown;

extern SDL_Texture *OptionsButtonUp;
extern SDL_Texture *OptionsButtonDown;

extern SDL_Texture *HowToPlayButtonUp;
extern SDL_Texture *HowToPlayButtonDown;

extern SDL_Texture *NormalButton;
extern SDL_Texture *NormalButtonDown;

extern SDL_Texture *LockedSpeedrunButton;
extern SDL_Texture *SpeedrunButton;
extern SDL_Texture *SpeedrunButtonDown;

extern SDL_Texture *BackButton;
extern SDL_Texture *BackButtonDown;

extern bool isClickingNormalButton;
extern bool isClickingSpeedrunButton;
extern bool isClickingBackButton;

extern bool isClickingStartButton;
extern bool isClickingOptionsButton;
extern bool isClickingHowToPlayButton;
