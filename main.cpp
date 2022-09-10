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
	bool run=true,debug=false,grid=true;
	int tmp=0,tmp1=0,aralik=50,count=0,arrpos=0;
	int procarr[5]={42,43,45,47,94};
	float x;
	string tmps,fonk;
	SDL_Event event;

	//inputs
	cin>>aralik;//space between 2 integers
	cin>>fonk;//the function

	//reading fonk
	for(int i=0;i<=fonk.length();i++){
		for(int k=0;k<sizeof(procarr)/sizeof(int);k++){//to go through all values automatically
			if(fonk[i]==procarr[k])//if value found in process array
			count++;//length of process array
		}
	}
	Vec3 vecc[count];//creating process array
	//assigning process array values
	for(int i=0;i<=fonk.length();i++){
		switch(fonk[i]){
			case 94://exponention
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=94;
			vecc[arrpos].z=2;
			arrpos++;
			break;
			case 42://multiplication
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=42;
			vecc[arrpos].z=1;
			arrpos++;
			break;
			case 47://division
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=47;
			vecc[arrpos].z=1;
			arrpos++;
			break;
			case 43://addition
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=43;
			vecc[arrpos].z=0;
			arrpos++;
			break;
			case 45://substraction
			vecc[arrpos].x=arrpos;
			vecc[arrpos].y=45;
			vecc[arrpos].z=0;
			arrpos++;
			break;
		}
	}
	arrpos=0;
	float arrofnum[count+1];//array of input numbers
	tmps.clear();
	//assigning number array values
	for(int i=0;i<=fonk.length();i++){
		if(fonk[i]==94||fonk[i]==42||fonk[i]==43||fonk[i]==45||fonk[i]==47||fonk[i]==59){
			if(tmps[0]==120){
			arrofnum[arrpos]=-1;
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
	//debug
	if(debug){
	for(int i=0;i<count+1;i++){
		cout<<arrofnum[i];
	}
	}

	A://editing vecc
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
	//debug
	if(debug){
	for(int i=0;i<count;i++){
		cout<<vecc[i].z<<",";
	}
	}

	//sdl window and renderer
	SDL_Window *win=SDL_CreateWindow("default",NOPOS,NOPOS,800,600,0);
	SDL_Renderer *ren=SDL_CreateRenderer(win,-1,0);

	//drawing back buffer start
	//clearing screen
	clearscreen(ren,aralik,grid);

	for(float i=-400.0f;i<=400;i++){
		x=i/aralik;
		//function
		float arrofnumcopy[count+1];
		Vec3 veccopy[count];
		for(int k=0;k<=count;k++){
			arrofnumcopy[k]=arrofnum[k];//creatimg a copy for use to keep original safe
		}
		for(int k=0;k<count;k++){
			veccopy[k]=vecc[k];//creatimg a copy for use to keep original safe
		}
		for(int k=0;k<count;k++){
			switch(veccopy[k].y){
				case 94:
				if(arrofnumcopy[veccopy[k].x]==-1&&arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=f2(x,x);
				}else if(arrofnumcopy[veccopy[k].x]==-1){
				arrofnumcopy[veccopy[k].x]=f2(x,arrofnumcopy[veccopy[k].x+1]);
				}else if(arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=f2(arrofnumcopy[veccopy[k].x],x);
				}else{
				arrofnumcopy[veccopy[k].x]=f2(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
				}
				break;
				case 42:
				if(arrofnumcopy[veccopy[k].x]==-1&&arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=fm(x,x);
				}else if(arrofnumcopy[veccopy[k].x]==-1){
				arrofnumcopy[veccopy[k].x]=fm(x,arrofnumcopy[veccopy[k].x+1]);
				}else if(arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=fm(arrofnumcopy[veccopy[k].x],x);
				}else{
				arrofnumcopy[veccopy[k].x]=fm(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
				}
				break;
				case 43:
				if(arrofnumcopy[veccopy[k].x]==-1&&arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=fp(x,x);
				}else if(arrofnumcopy[veccopy[k].x]==-1){
				arrofnumcopy[veccopy[k].x]=fp(x,arrofnumcopy[veccopy[k].x+1]);
				}else if(arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=fp(arrofnumcopy[veccopy[k].x],x);
				}else{
				arrofnumcopy[veccopy[k].x]=fp(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
				}
				break;
				case 45:
				if(arrofnumcopy[veccopy[k].x]==-1&&arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=fs(x,x);
				}else if(arrofnumcopy[veccopy[k].x]==-1){
				arrofnumcopy[veccopy[k].x]=fs(x,arrofnumcopy[veccopy[k].x+1]);
				}else if(arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=fs(arrofnumcopy[veccopy[k].x],x);
				}else{
				arrofnumcopy[veccopy[k].x]=fs(arrofnumcopy[veccopy[k].x],arrofnumcopy[veccopy[k].x+1]);
				}
				break;
				case 47:
				if(arrofnumcopy[veccopy[k].x]==-1&&arrofnumcopy[veccopy[k].x+1]==-1){
				arrofnumcopy[veccopy[k].x]=fd(x,x);
				}else if(arrofnumcopy[veccopy[k].x]==-1){
				arrofnumcopy[veccopy[k].x]=fd(x,arrofnumcopy[veccopy[k].x+1]);
				}else if(arrofnumcopy[veccopy[k].x+1]==-1){
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
		x=arrofnumcopy[0];//assigning y value of graph
		//function
		SDL_RenderDrawLine(ren,i+400,tmp,i+400,300-(aralik*x));//drawing
		tmp=300-(aralik*x);
	}
	//drawing back buffer end

	SDL_RenderPresent(ren);//switching buffers

	//main loop
	while(run){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT://QUIT event
				run=false;//stopping loop
				break;
			}
		}
	}
	//quitting
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}