#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <SDL2/SDL.h>

void grid(SDL_Renderer *ren,int aralik);

typedef struct{
	int x,y,z;
}Vec3;

float fm(float x,float y);
float fp(float x,float y);
float fs(float x,float y);
float fd(float x,float y);
float f2(float x,float y);

void clearscreen(SDL_Renderer *ren, int aralik, bool grid);

#endif

//to do:
//functionise more of main file(especially ones copying buffers)
//add for each loops and arrays for processing of integer ids