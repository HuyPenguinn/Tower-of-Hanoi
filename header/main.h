#pragma once
#include <windows.h>
#include "SDL2/SDL.h"
#include "global_var.h"
#include "gameplay.h"


void InitSDL();
void InitPoles();
void LoadMedia();
void GetConfig();

void MainGameplay();
void MainMenu();
void Config();
void ChooseGamemode();
void HowToPlay();

void Quit();
void CleanUp();
void DrawCursor(bool isHolding);