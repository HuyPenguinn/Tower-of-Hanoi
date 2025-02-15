#ifndef OBJECT_H
#define OBJECT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>
class Disk {
    public:
        int size;
        SDL_Rect box;
        SDL_Texture *texture;
        SDL_Renderer *renderer;
        Disk(SDL_Renderer *renderer,int size,int x,int y);
        void Render();
};
#endif