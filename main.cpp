#include <iostream>
#include <fstream>
#include "functions.h"

#define NOPOS SDL_WINDOWPOS_UNDEFINED

using namespace std;

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//variables
	Vec3 tmpvec;
	bool run=true,debug=false;
	int tmp=0,tmp1=0,aralik=50,count=0,arrpos=0;
	float x,y;
	string tmps,fonk;
	SDL_Event event;

	//inputs
	cin>>aralik;
	cin>>fonk;

	//reading fonk
	for(int i=0;i<=fonk.length();i++){
		if(fonk[i]==42||fonk[i]==43||fonk[i]==45||fonk[i]==47){
			count++;
		}
	}
	Vec3 vecc[count];
	for(int i=0;i<=fonk.length();i++){
		switch(fonk[i]){
			case 42:
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=42;
			vecc[arrpos].z=1;
			arrpos++;
			break;
			case 47:
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=47;
			vecc[arrpos].z=1;
			arrpos++;
			break;
			case 43:
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=43;
			vecc[arrpos].z=0;
			arrpos++;
			break;
			case 45:
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=45;
			vecc[arrpos].z=0;
			arrpos++;
			break;
		}
	}
	arrpos=0;
	float arrofnum[count+1];
	tmps.clear();
	for(int i=0;i<=fonk.length();i++){
		if(fonk[i]==42||fonk[i]==43||fonk[i]==45||fonk[i]==47||fonk[i]==59){
			if(tmps[0]==120){
			arrofnum[arrpos]=120;
			}else{
			arrofnum[arrpos]=stof(tmps);
			}
			arrpos++;
			tmps.clear();
		}else{
			tmps+=fonk[i];
		}

	}
	arrpos=0;
	for(int i=0;i<count+1;i++){
		cout<<arrofnum[i];
	}

	//editing vecc
	A:
	for(int i=1;i<count;i++){
		if(vecc[i].z>vecc[i-1].z){
			tmpvec=vecc[i];
			vecc[i]=vecc[i-1];
			vecc[i-1]=tmpvec;
		}
	}
	for(int i=1;i<count;i++){
		if(vecc[i].z>vecc[i-1].z){
			goto A;
		}
	}
	for(int i=0;i<count;i++){
		cout<<vecc[i].z<<",";
	}

	//sdl window and renderer
	SDL_Window *win=SDL_CreateWindow("default",NOPOS,NOPOS,800,600,0);
	SDL_Renderer *ren=SDL_CreateRenderer(win,-1,0);

	while(run){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
				run=false;
				break;
			}
		}
		SDL_SetRenderDrawColor(ren,255,255,255,255);
		SDL_RenderClear(ren);
		grid(ren,aralik);
		SDL_SetRenderDrawColor(ren,0,0,255,255);


		for(float i=-400.0f;i<=400;i++){
			x=i/aralik;
			//function
			float arrofnumcopy[count+1];
			Vec3 veccopy[count];
			for(int k=0;k<=count;k++){
				arrofnumcopy[k]=arrofnum[k];
			}
			for(int k=0;k<count;k++){
				veccopy[k]=vecc[k];
			}
			for(int k=0;k<count;k++){
				switch(veccopy[k].y){
					case 42:
					if(arrofnumcopy[veccopy[k].x]==120&&arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fm(x,x);
					}else if(arrofnumcopy[veccopy[k].x]==120){
					arrofnumcopy[veccopy[k].x]=fm(x,arrofnumcopy[veccopy[k].x+1]);
					}else if(arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fm(arrofnumcopy[veccopy[k].x],x);
					}else{
					arrofnumcopy[veccopy[k].x]=fm(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
					}
					break;
					case 43:
					if(arrofnumcopy[veccopy[k].x]==120&&arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fp(x,x);
					}else if(arrofnumcopy[veccopy[k].x]==120){
					arrofnumcopy[veccopy[k].x]=fp(x,arrofnumcopy[veccopy[k].x+1]);
					}else if(arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fp(arrofnumcopy[veccopy[k].x],x);
					}else{
					arrofnumcopy[veccopy[k].x]=fp(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
					}
					break;
					case 45:
					if(arrofnumcopy[veccopy[k].x]==120&&arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fs(x,x);
					}else if(arrofnumcopy[veccopy[k].x]==120){
					arrofnumcopy[veccopy[k].x]=fs(x,arrofnumcopy[veccopy[k].x+1]);
					}else if(arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fs(arrofnumcopy[veccopy[k].x],x);
					}else{
					arrofnumcopy[veccopy[k].x]=fs(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
					}
					break;
					case 47:
					if(arrofnumcopy[veccopy[k].x]==120&&arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fd(x,x);
					}else if(arrofnumcopy[veccopy[k].x]==120){
					arrofnumcopy[veccopy[k].x]=fd(x,arrofnumcopy[veccopy[k].x+1]);
					}else if(arrofnumcopy[veccopy[k].x+1]==120){
					arrofnumcopy[veccopy[k].x]=fd(arrofnumcopy[veccopy[k].x],x);
					}else{
					arrofnumcopy[veccopy[k].x]=fd(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
					}
					break;
				}
				for(int a=0;a<count;a++){
					if(veccopy[a].x>veccopy[k].x){
						veccopy[a].x-=1;
					}
				}
				for(int a=0;a<=count;a++){
					if(a>veccopy[k].x+1){
						arrofnumcopy[a-1]=arrofnumcopy[a];
					}
				}
			}
			x=arrofnumcopy[0];
			//function
			//drawing
			SDL_RenderDrawLine(ren,i+400,tmp,i+400,300-(aralik*x));
			tmp=300-(aralik*x);
		}
		SDL_RenderPresent(ren);
	}

	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}