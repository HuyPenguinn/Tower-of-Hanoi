#include "def.h"

void DrawAllDisks(){
    int id = 15;
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < poles[k].num.size(); i++){
            SDL_RenderCopy(renderer, Disks, SrcRect(poles[k].num[i]), &(poles[k].disks[i]));
            id -= poles[k].num[i];
        }
    }
    switch(id){
        case 1:
            if(isHolding){
                rect1.x = 120 + (isHolding - 1) * 300 - id * 20;
                rect1.y = 100;
                SDL_RenderCopy(renderer, Disks, &Disk1, &rect1);
            }
            break;
        case 2:
            if(isHolding){
                rect2.x = 120 + (isHolding - 1) * 300 - id * 20;
                rect2.y = 100;
                SDL_RenderCopy(renderer, Disks, &Disk2, &rect2);
            }
            break;
        case 3:
            if(isHolding){    
                rect3.x = 120 + (isHolding - 1) * 300 - id * 20;
                rect3.y = 100;
                SDL_RenderCopy(renderer, Disks, &Disk3, &rect3);
            }
            break;
        case 4:
            if(isHolding){
                rect4.x = 120 + (isHolding - 1) * 300 - id * 20;
                rect4.y = 100;
                SDL_RenderCopy(renderer, Disks, &Disk4, &rect4);
            }
            break;
        case 5:
            if(isHolding){
                rect5.x = 120 + (isHolding - 1) * 300 - id * 20;
                rect5.y = 100;
                SDL_RenderCopy(renderer, Disks, &Disk5, &rect5);
            }
            break;
        default:
            break;
    }
}

void DrawPole(bool isValid, int n){
    
    if(!isValid){
        switch(n){
            case 1:
                SDL_RenderCopy(renderer, ColoredPole, &RedPoleSrc, &FirstPole);
                break;
            case 2:
                SDL_RenderCopy(renderer, ColoredPole, &RedPoleSrc, &SecondPole);
                break;
            case 3:
                SDL_RenderCopy(renderer, ColoredPole, &RedPoleSrc, &ThirdPole);
                break;
        }
    }else{
        switch(n){
            case 1:
                SDL_RenderCopy(renderer, ColoredPole, &GreenPoleSrc, &FirstPole);
                break;
            case 2:
                SDL_RenderCopy(renderer, ColoredPole, &GreenPoleSrc, &SecondPole);
                break;
            case 3:
                SDL_RenderCopy(renderer, ColoredPole, &GreenPoleSrc, &ThirdPole);
                break;
        }
    }
}

void DrawCursor(bool closing){
    SDL_GetMouseState(&x, &y);
    CursorRect.x = x;
    CursorRect.y = y;
    if(closing)
        SDL_RenderCopy(renderer, Cursor, &CloseCursorSrc, &CursorRect);
    else
        SDL_RenderCopy(renderer, Cursor, &OpenCursorSrc, &CursorRect);
}

void DrawColoredPole(){
    if(isHolding && isHolding != target){
        switch(target){
            case 1:
                DrawPole(ValidDrop, 1);
                break;
            case 2:
                DrawPole(ValidDrop, 2);
                break;
            case 3:
                DrawPole(ValidDrop, 3);
                break;
            default:
                break;
        }
    }
}

void DrawMoveCount(){
    SDL_Rect textRect = {20, 20, textSurface->w, textSurface->h};
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
}

void DrawStar(int MoveCount){
    if(MoveCount == 31){
        SDL_RenderCopy(renderer, ThreeStar, NULL, NULL);
    }else if(MoveCount <= 36){
        SDL_RenderCopy(renderer, TwoStar, NULL, NULL);
    }else{
        SDL_RenderCopy(renderer, OneStar, NULL, NULL);
    }
}