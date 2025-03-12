#pragma once
#include "media.h"
#include "global_var.h"

void __Background();
void DrawStar(int MoveCount);
void DrawColoredPole();
void DrawAllDisks();
void DrawPole(bool isRed, int n);
void DrawMoveCount();
void DrawTime(unsigned long long time);
void DrawTimeScore(unsigned long long time);