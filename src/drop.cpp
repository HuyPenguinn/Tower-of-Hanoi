#include "define.h"

void DroppingProcess(){
    if(isHolding){
        if(ValidDrop && isHolding != target){// ValidDrop is true when the disk is not being held and the mouse is over a pole
            MoveUpdate();
            poles[target - 1].num.push_back(CurrentDisk);
            if(TmpRect != NULL){
                TmpRect->x = 120 + (target - 1) * 300 - CurrentDisk * 20;
                TmpRect->y = 460 - poles[target - 1].num.size() * 50;
                poles[target - 1].disks.push_back(*TmpRect);
                TmpRect = NULL;
            }
        }else{// Return to the original pole
            poles[isHolding - 1].num.push_back(CurrentDisk);
            poles[isHolding - 1].disks.push_back(*TmpRect);
            poles[isHolding - 1].disks[poles[isHolding - 1].disks.size() - 1].y = 460 - poles[isHolding - 1].num.size() * 50;
        }
    }
    else { // Invalid Space to drop
        poles[isHolding - 1].num.push_back(CurrentDisk);
        poles[isHolding - 1].disks.push_back(*TmpRect);
        poles[isHolding - 1].disks[poles[isHolding - 1].disks.size() - 1].y = 460 - poles[isHolding - 1].num.size() * 50 ;
    }
    CurrentDisk = 0;
    isHolding = 0;
    ValidDrop = false;
}