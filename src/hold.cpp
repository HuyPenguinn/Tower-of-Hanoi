#include "global_var.h"
#include "def.h"
#include "gameplay.h"

void HoldingProcess(){
    if(x >= 0 && x < 300 && y >= 80 && y <= 460){
        if(poles[0].num.size() > 0){
            if(!GAMESTARTED) StartTime = SDL_GetTicks() % 1000000000;
            GAMESTARTED = true;
            isHolding = 1;
            CurrentDisk = poles[0].num[poles[0].num.size() - 1];
            poles[0].num.pop_back();            
            *TmpRect = poles[0].disks[poles[0].disks.size() - 1];
            poles[0].disks.pop_back();
        }
    }else if(x >= 300 && x < 600 && y >= 80 && y <= 460){
        if(poles[1].num.size() > 0){
            if(!GAMESTARTED) StartTime = SDL_GetTicks() % 1000000000;
            GAMESTARTED = true;
            isHolding = 2;
            CurrentDisk = poles[1].num[poles[1].num.size() - 1];
            poles[1].num.pop_back();
            *TmpRect = poles[1].disks[poles[1].disks.size() - 1];
            poles[1].disks.pop_back();
        }
    }else if(x >= 600 && y >= 80 && y <= 460 && !Win()){
        if(poles[2].num.size() > 0){
            if(!GAMESTARTED) StartTime = SDL_GetTicks() %1000000000;
            GAMESTARTED = true;
            isHolding = 3;
            CurrentDisk = poles[2].num[poles[2].num.size() - 1];
            poles[2].num.pop_back();
            *TmpRect = poles[2].disks[poles[2].disks.size() - 1];
            poles[2].disks.pop_back();
        }
    }
}