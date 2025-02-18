#include "define.h"

void CheckValidMove(){
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

bool Win(){
    return pol3.num.size() == 5 && pol1.num.size() == 0 && pol2.num.size() == 0;
}

void HoldingProcess(){
    if(x >= 0 && x < 300 && y >= 80 && y <= 460){
        if(pol1.num.size() > 0){
            isHolding = 1;
            CurrentDisk = pol1.num[pol1.num.size() - 1];
            pol1.num.pop_back();
            *TmpRect = pol1.disks[pol1.disks.size() - 1];
            pol1.disks.pop_back();
        }
    }else if(x >= 300 && x < 600 && y >= 80 && y <= 460){
        if(pol2.num.size() > 0){
            isHolding = 2;
            CurrentDisk = pol2.num[pol2.num.size() - 1];
            pol2.num.pop_back();
            *TmpRect = pol2.disks[pol2.disks.size() - 1];
            pol2.disks.pop_back();
        }
    }else if(x >= 600 && y >= 80 && y <= 460 && !Win()){
        if(pol3.num.size() > 0){
            isHolding = 3;
            CurrentDisk = pol3.num[pol3.num.size() - 1];
            pol3.num.pop_back();
            *TmpRect = pol3.disks[pol3.disks.size() - 1];
            pol3.disks.pop_back();
        }
    }
}

void DroppingProcess(){
    if(isHolding){
        if(x >= 0 && x < 300 && y >= 80 && y <= 460){
            if(pol1.num.size() == 0 || CurrentDisk < pol1.num.back()){
                pol1.num.push_back(CurrentDisk);
                MoveCount++;
                if(TmpRect != NULL){
                    (*TmpRect).x = 120 - CurrentDisk * 20;
                    (*TmpRect).y = 460 - pol1.num.size() * 50;
                    pol1.disks.push_back(*TmpRect);
                    TmpRect = NULL;
                }
            }else{
                if(isHolding == 2){// 1 -> 2
                    pol2.num.push_back(CurrentDisk);
                    pol2.disks.push_back(*TmpRect);
                }else if(isHolding == 3){// 1 -> 3
                    pol3.num.push_back(CurrentDisk);
                    pol3.disks.push_back(*TmpRect);                       
                }
            }
            CurrentDisk = 0;
            isHolding = false;
        }else if(x >= 300 && x < 600 && y >= 80 && y <= 460){
            if(pol2.num.size() == 0 || CurrentDisk < pol2.num.back()){
                pol2.num.push_back(CurrentDisk);
                MoveCount++;
                if(TmpRect != NULL){
                    (*TmpRect).x = 420 - CurrentDisk * 20;
                    (*TmpRect).y = 460 - pol2.num.size() * 50;
                    pol2.disks.push_back(*TmpRect);
                    TmpRect = NULL;
                }
            }else{
                if(isHolding == 1){// 2 -> 1
                    pol1.num.push_back(CurrentDisk);
                    pol1.disks.push_back(*TmpRect);
                }else if(isHolding == 3){// 2 -> 3
                    pol3.num.push_back(CurrentDisk);
                    pol3.disks.push_back(*TmpRect);
                }
            }
            CurrentDisk = 0;
            isHolding = false;
        }else if(x >= 600 && y >= 80 && y <= 460){
            if(pol3.num.size() == 0 || CurrentDisk < pol3.num.back()){
                pol3.num.push_back(CurrentDisk);
                MoveCount++;
                if(TmpRect != NULL){
                    (*TmpRect).x = 720 - CurrentDisk * 20;
                    (*TmpRect).y = 460 - pol3.num.size() * 50;
                    pol3.disks.push_back(*TmpRect);
                    TmpRect = NULL;
                }
            }else{
                if(isHolding == 1){//3 -> 1
                    pol1.num.push_back(CurrentDisk);
                    pol1.disks.push_back(*TmpRect);
                }else if(isHolding == 2){//3 -> 2
                    pol2.num.push_back(CurrentDisk);
                    pol2.disks.push_back(*TmpRect);
                }
            }
            CurrentDisk = 0;
            isHolding = false;
        }

        // Invalid zone for dropping
        else{
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

void EventProcess(){
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
            if(Win()){
                Restart();
            }else{
                HoldingProcess();
            }
        }
        if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT){
            DroppingProcess();
        }
        if(event.type == SDL_MOUSEMOTION){
            CheckValidMove();
        }
    }
}
