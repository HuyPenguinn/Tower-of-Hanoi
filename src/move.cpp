#include "def.h"

void CheckValidMove(){
    if(x >= 0 && x < 300 && y >= 80 && y <= 460){
        target = 1;
    }
    else if(x >= 300 && x < 600 && y >= 80 && y <= 460){
        target = 2;
    }
    else if(x >= 600 && y >= 80 && y <= 460){
        target = 3;
    }
    
    if(isHolding){
        if(poles[target - 1].num.size() == 0 || CurrentDisk < poles[target - 1].num.back()){
            ValidDrop = true;
        }else{
            ValidDrop = false;
        }
    }
    else isHolding = false;
}

bool Win(){
    return poles[2].num.size() == 5 && poles[0].num.size() == 0 && poles[1].num.size() == 0;
}

void MoveUpdate(){
    if(ValidDrop && isHolding != target){
        MoveCount++;
    }
}
