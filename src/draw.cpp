#include "define.h"

void DrawAllDisks(){
    int id = 15;
    for(int i = 0; i < pol1.num.size(); i++){
        SDL_RenderCopy(renderer, Disks, SrcRect(pol1.num[i]), &pol1.disks[i]);
        id -= pol1.num[i];
    }
    for(int i = 0; i < pol2.num.size(); i++){
        SDL_RenderCopy(renderer, Disks, SrcRect(pol2.num[i]), &pol2.disks[i]);
        id -= pol2.num[i];
    }
    for(int i = 0; i < pol3.num.size(); i++){
        SDL_RenderCopy(renderer, Disks, SrcRect(pol3.num[i]), &pol3.disks[i]);
        id -= pol3.num[i];
    }
    switch(id){
        case 1:
            switch(isHolding){
                case 1:
                    rect1.x = 100;
                    rect1.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk1, &rect1);
                    break;
                case 2:
                    rect1.x = 400;
                    rect1.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk1, &rect1);
                    break;
                case 3:
                    rect1.x = 700;
                    rect1.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk1, &rect1);
                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch(isHolding){
                case 1:
                    rect2.x = 80;
                    rect2.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk2, &rect2);
                    break;
                case 2:
                    rect2.x = 380;
                    rect2.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk2, &rect2);
                    break;
                case 3:
                    rect2.x = 680;
                    rect2.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk2, &rect2);
                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch(isHolding){
                case 1:
                    rect3.x = 60;
                    rect3.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk3, &rect3);
                    break;
                case 2:
                    rect3.x = 360;
                    rect3.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk3, &rect3);
                    break;
                case 3:
                    rect3.x = 660;
                    rect3.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk3, &rect3);
                    break;
                default:
                    break;
            }
            break;
        case 4:
            switch(isHolding){
                case 1:
                    rect4.x = 40;
                    rect4.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk4, &rect4);
                    break;
                case 2:
                    rect4.x = 340;
                    rect4.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk4, &rect4);
                    break;
                case 3:
                    rect4.x = 640;
                    rect4.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk4, &rect4);
                    break;
                default:
                    break;
            }
            break;
        case 5:
            switch(isHolding){
                case 1:
                    rect5.x = 20;
                    rect5.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk5, &rect5);
                    break;
                case 2:
                    rect5.x = 320;
                    rect5.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk5, &rect5);
                    break;
                case 3:
                    rect5.x = 620;
                    rect5.y = 100;
                    SDL_RenderCopy(renderer, Disks, &Disk5, &rect5);
                    break;
                default:
                    break;
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

void DrawCursor(){
    SDL_GetMouseState(&x, &y);
    CursorRect.x = x;
    CursorRect.y = y;
    SDL_RenderCopy(renderer, ColoredPole, &CursorSrc, &CursorRect);
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

void DrawStar(int MoveCount){
    if(MoveCount == 31){
        // 3 stars
    }else if(MoveCount <= 36){
        // 2 stars
    }else{
        // 1 star
    }
    return;
}