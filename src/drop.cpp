#include "global_var.h"
#include "def.h"
#include "gameplay.h"
#include "media.h"
void DroppingProcess(){
    if(isHolding){
        if(ValidDrop && isHolding != target){// ValidDrop is true when the disk is not being held and the mouse is over a pole
            MoveUpdate();
            poles[target - 1].num.push_back(CurrentDisk);
            
            if(TmpRect != nullRect){
                TmpRect->x = 120 + (target - 1) * 300 - CurrentDisk * 20;
                TmpRect->y = 460 - poles[target - 1].num.size() * 50;
                poles[target - 1].disks.push_back(*TmpRect);
            }
            
            if(SoundEffectConfig != "0") {
                Mix_VolumeChunk(DropSound, to_int(SoundEffectConfig));
                Mix_PlayChannel(-1, DropSound, 0);
            }
            
        }else{// Return to the original pole
            
            poles[isHolding - 1].num.push_back(CurrentDisk);
            poles[isHolding - 1].disks.push_back(*TmpRect);
            poles[isHolding - 1].disks[poles[isHolding - 1].disks.size() - 1].y = 460 - poles[isHolding - 1].num.size() * 50;
        }
    }
    else { // Invalid Space to drop
        if(CurrentDisk){
            poles[isHolding].num.push_back(CurrentDisk);
            poles[isHolding].disks.push_back(*TmpRect);    
            poles[isHolding].disks[poles[isHolding].disks.size()].y = 460 - poles[isHolding].num.size() * 50 ;
        }
    }

    CurrentDisk = 0;
    isHolding = 0;
    ValidDrop = false;
}