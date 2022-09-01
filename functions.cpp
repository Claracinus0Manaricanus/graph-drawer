#include "functions.h"
#include <iostream>
#include <fstream>

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

//işlemler
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
float f2(float x){
return x*x;
}