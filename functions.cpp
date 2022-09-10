#include "functions.h"
#include <iostream>
#include <fstream>

//function of drawing grid
void grid(SDL_Renderer *ren,int aralik){
		SDL_SetRenderDrawColor(ren,0,0,0,100);
		for(int i=-400;i<=400;i++){
			if(i%aralik==0){
				SDL_RenderDrawLine(ren,i+400,0,i+400,600);
			}
			if(i==0){
				SDL_SetRenderDrawColor(ren,255,0,0,100);
				SDL_RenderDrawLine(ren,i+400,0,i+400,600);
				SDL_SetRenderDrawColor(ren,0,0,0,100);
			}
		}
		for(int i=-300;i<=300;i++){
			if(i%aralik==0){
				SDL_RenderDrawLine(ren,0,300-i,800,300-i);
			}
			if(i==0){
				SDL_SetRenderDrawColor(ren,255,0,0,100);
				SDL_RenderDrawLine(ren,0,300-i,800,300-i);
				SDL_SetRenderDrawColor(ren,0,0,0,100);
			}
		}
}

//processes
float fm(float x,float y){
return x*y;
}
float fp(float x,float y){
return x+y;
}
float fd(float x,float y){
return x/y;
}
float fs(float x,float y){
return x-y;
}
float f2(float x,float y){
	if(y==1){
		return x;
	}
	y--;
	return x*f2(x,y);
}

//clearing screen
void clearscreen(SDL_Renderer *ren, int aralik, bool gridb){
	SDL_SetRenderDrawColor(ren,255,255,255,255);//white
	SDL_RenderClear(ren);//painting whole screen white
	if(grid){
	grid(ren,aralik);//calling grid function
	}
	SDL_SetRenderDrawColor(ren,0,0,255,255);//blue
}

//foreach loop