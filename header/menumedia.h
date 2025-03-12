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

extern bool isClickingStartButton;
extern bool isClickingOptionsButton;
extern bool isClickingHowToPlayButton;
