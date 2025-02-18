#include "define.h"
#include <bits/stdc++.h>

int main(int argc,char **argv){
    
    Init();
    while(isRunning){

        if(TmpRect == NULL) TmpRect = new SDL_Rect;

        SDL_SetRenderDrawColor(renderer, 180, 220, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Background, NULL, NULL);
        
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                isRunning = false;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                if(event.button.button == SDL_BUTTON_LEFT){
                    HoldingProcess();
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP){
                if(event.button.button == SDL_BUTTON_LEFT){
                    DroppingProcess();
                }
            }
            if(event.type == SDL_MOUSEMOTION){
                SDL_GetMouseState(&x, &y);
                if(x >= 0 && x < 300 && y >= 80 && y <= 460){
                    target = 1;
                    switch(isHolding){
                        case 1:
                            ValidDrop = true;
                            break;
                        case 2:
                            if(pol1.num.size() == 0 || CurrentDisk < pol1.num.back()){
                                ValidDrop = true;
                            }else{
                                ValidDrop = false;
                            }
                            break;
                        case 3:
                            if(pol1.num.size() == 0 || CurrentDisk < pol1.num.back()){
                                ValidDrop = true;
                            }else{
                                ValidDrop = false;
                            }
                            break;
                        default:
                            break;
                    }
                }
                else if(x >= 300 && x < 600 && y >= 80 && y <= 460){
                    target = 2;
                    switch(isHolding){
                        case 1:
                            if(pol2.num.size() == 0 || CurrentDisk < pol2.num.back()){
                                ValidDrop = true;
                            }else{
                                ValidDrop = false;
                            }
                            break;
                        case 2:
                            ValidDrop = true;
                            break;
                        case 3:
                            if(pol2.num.size() == 0 || CurrentDisk < pol2.num.back()){
                                ValidDrop = true;
                            }else{
                                ValidDrop = false;
                            }
                            break;
                        default:
                            break;
                    }
                }
                else if(x >= 600 && y >= 80 && y <= 460){
                    target = 3;
                    switch(isHolding){
                        case 1:
                            if(pol3.num.size() == 0 || CurrentDisk < pol3.num.back()){
                                ValidDrop = true;
                            }else{
                                ValidDrop = false;
                            }
                            break;
                        case 2:
                            if(pol3.num.size() == 0 || CurrentDisk < pol3.num.back()){
                                ValidDrop = true;
                            }else{
                                ValidDrop = false;
                            }
                            break;
                        case 3:
                            ValidDrop = true;
                            break;
                        default:
                            break;
                    }
                }
                else{
                    target = 0;
                }
            }
        }

        //Draw the colored pole
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
        cerr << "ValidDrop: " << ValidDrop << endl;
        DrawAllDisks();
        
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    
    CleanUp();

    return 0;
}