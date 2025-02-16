#include "define.h"
#include <bits/stdc++.h>

int main(int argc,char **argv){
   
    Init();

    bool isRunning = true;
    while(isRunning){

        SDL_SetRenderDrawColor(renderer, 180, 220, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Background, NULL, NULL);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                isRunning = false;
            }
        }
        
        BlendRect(&rect1, 255, 230, 153);
        BlendRect(&rect2, 255, 215, 128);
        BlendRect(&rect3, 255, 200, 102);
        BlendRect(&rect4, 255, 185, 77);
        BlendRect(&rect5, 255, 170, 51);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    
    CleanUp();

    return 0;
}