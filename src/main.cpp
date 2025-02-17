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
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    if(x >= 0 && x < 300 && y >= 80 && y <= 460){
                        if(pol1.num.size() > 0){
                            isHolding = 1;
                            CurrentDisk = pol1.num[pol1.num.size() - 1];
                            pol1.num.pop_back();
                            // pol1.disks[pol1.disks.size() - 1].y = 100;
                            *TmpRect = pol1.disks[pol1.disks.size() - 1];
                            pol1.disks.pop_back();
                        }
                    }else if(x >= 300 && x < 600 && y >= 80 && y <= 460){
                        if(pol2.num.size() > 0){
                            isHolding = 2;
                            CurrentDisk = pol2.num[pol2.num.size() - 1];
                            pol2.num.pop_back();
                            // pol2.disks[pol2.disks.size() - 1].y = 100;
                            *TmpRect = pol2.disks[pol2.disks.size() - 1];
                            pol2.disks.pop_back();
                        }
                    }else if(x >= 600 && y >= 80 && y <= 460){
                        if(pol3.num.size() > 0){
                            isHolding = 3;
                            CurrentDisk = pol3.num[pol3.num.size() - 1];
                            pol3.num.pop_back();
                            // pol3.disks[pol3.disks.size() - 1].y = 100;
                            *TmpRect = pol3.disks[pol3.disks.size() - 1];
                            pol3.disks.pop_back();
                        }
                    }
                }
            }
            if(event.type == SDL_MOUSEBUTTONUP){
                if(event.button.button == SDL_BUTTON_LEFT){
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    if(isHolding){
                        if(x >= 0 && x < 300 && y >= 80 && y <= 460){
                            if(pol1.num.size() == 0 || CurrentDisk < pol1.num.back()){
                                pol1.num.push_back(CurrentDisk);
                                if(TmpRect != NULL){
                                    (*TmpRect).x = 120 - CurrentDisk * 20;
                                    (*TmpRect).y = 460 - pol1.num.size() * 50;
                                    pol1.disks.push_back(*TmpRect);
                                    TmpRect = NULL;
                                }
                            }else{
                                if(isHolding == 1){
                                    pol1.num.push_back(CurrentDisk);
                                    pol1.disks.push_back(*TmpRect);
                                    // pol1.disks[pol1.disks.size() - 1].y = 460 - pol1.num.size() * 50;
                                }else if(isHolding == 2){
                                    pol2.num.push_back(CurrentDisk);
                                    pol2.disks.push_back(*TmpRect);
                                    // pol2.disks[pol2.disks.size() - 1].y = 460 - pol2.num.size() * 50;
                                }else if(isHolding == 3){
                                    pol3.num.push_back(CurrentDisk);
                                    pol3.disks.push_back(*TmpRect);
                                    // pol3.disks[pol3.disks.size() - 1].y = 460 - pol3.num.size() * 50;                          
                                }
                            }
                            CurrentDisk = 0;
                            isHolding = false;
                        }else if(x >= 300 && x < 600 && y >= 80 && y <= 460){
                            if(pol2.num.size() == 0 || CurrentDisk < pol2.num.back()){
                                pol2.num.push_back(CurrentDisk);
                                if(TmpRect != NULL){
                                    (*TmpRect).x = 420 - CurrentDisk * 20;
                                    (*TmpRect).y = 460 - pol2.num.size() * 50;
                                    pol2.disks.push_back(*TmpRect);
                                    TmpRect = NULL;
                                }
                            }else{
                                if(isHolding == 1){
                                    pol1.num.push_back(CurrentDisk);
                                    pol1.disks.push_back(*TmpRect);
                                    // pol1.disks[pol1.disks.size() - 1].y = 460 - pol1.num.size() * 50;
                                }else if(isHolding == 2){
                                    pol2.num.push_back(CurrentDisk);
                                    pol2.disks.push_back(*TmpRect);
                                    // pol2.disks[pol2.disks.size() - 1].y = 460 - pol2.num.size() * 50;
                                }else if(isHolding == 3){
                                    pol3.num.push_back(CurrentDisk);
                                    pol3.disks.push_back(*TmpRect);
                                    // pol3.disks[pol3.disks.size() - 1].y = 460 - pol3.num.size() * 50;
                                }
                            }
                            CurrentDisk = 0;
                            isHolding = false;
                        }else if(x >= 600 && y >= 80 && y <= 460){
                            if(pol3.num.size() == 0 || CurrentDisk < pol3.num.back()){
                                pol3.num.push_back(CurrentDisk);
                                if(TmpRect != NULL){
                                    (*TmpRect).x = 720 - CurrentDisk * 20;
                                    (*TmpRect).y = 460 - pol3.num.size() * 50;
                                    pol3.disks.push_back(*TmpRect);
                                    TmpRect = NULL;
                                }
                            }else{
                                if(isHolding == 1){
                                    pol1.num.push_back(CurrentDisk);
                                    pol1.disks.push_back(*TmpRect);
                                    // pol1.disks[pol1.disks.size() - 1].y = 460 - pol1.num.size() * 50;
                                }else if(isHolding == 2){
                                    pol2.num.push_back(CurrentDisk);
                                    pol2.disks.push_back(*TmpRect);
                                    // pol2.disks[pol2.disks.size() - 1].y = 460 - pol2.num.size() * 50;
                                }else if(isHolding == 3){
                                    pol3.num.push_back(CurrentDisk);
                                    pol3.disks.push_back(*TmpRect);
                                    // pol3.disks[pol3.disks.size() - 1].y = 460 - pol3.num.size() * 50;
                                }
                            }
                            CurrentDisk = 0;
                            isHolding = false;
                        }else{
                            if(isHolding == 1){
                                pol1.num.push_back(CurrentDisk);
                                pol1.disks.push_back(*TmpRect);
                                pol1.disks[pol1.disks.size() - 1].y = 460 - pol1.num.size() * 50;
                            }else if(isHolding == 2){
                                pol2.num.push_back(CurrentDisk);
                                pol2.disks.push_back(*TmpRect);
                                pol2.disks[pol2.disks.size() - 1].y = 460 - pol2.num.size() * 50;
                            }else if(isHolding == 3){
                                pol3.num.push_back(CurrentDisk);
                                pol3.disks.push_back(*TmpRect);
                                pol3.disks[pol3.disks.size() - 1].y = 460 - pol3.num.size() * 50;
                            }
                            CurrentDisk = 0;
                            isHolding = 0;
                        }
                    }
                }
            }
        }

        DrawAllDisks();
        
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    
    CleanUp();

    return 0;
}