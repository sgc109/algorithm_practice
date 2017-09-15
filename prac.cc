#include <cstdio>

#define HEIGHT 12
#define WIDTH 16
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;


struct Window{
public:
	Window *parent;
	Window *childs[500];
	int cntChild;
	int handle;
	char display[HEIGHT][WIDTH];
	int y,x,h,w;
	Window(int handle, int y, int x, int h, int w, char bg) : handle(handle),y(y),x(x),h(h),w(w),cntChild(0){
		for(int y=0;y<HEIGHT;y++){
			for(int x=0;x<WIDTH;x++){
				display[y][x] = bg;
			}
		}
	}
	void addChild(Window *target){
		target->parent=this;
		childs[cntChild++]=target;
	}

	void removeChild(Window *target){

	}
};

char DisplayBuf[HEIGHT+1][WIDTH+1];
int cntWindow;
Window *windows[500];
Window *root;

void root2buf(){
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){
			DisplayBuf[i][j]=root->display[i][j];
		}
	}
}

void updateRoot(Window *cur){
	for(int i=0; i<cur->cntChild;i++){
		updateRoot(cur->childs[i]);
	}
	if(cur->handle==-1) return;
	
	int x1=max(cur->x,0);
	int y1=max(cur->y,0);
	int x2=min(cur->x+cur->w,WIDTH);
	int y2=min(cur->y+cur->h,HEIGHT);
	for(int y=y1;y<y2;y++){
		for(int x=x1;x<x2;x++){
			cur->parent->display[y][x]=cur->display[y-cur->y][x-cur->x];
		}
	}
}

void init(char bg){
	cntWindow=0;
	root = new Window(-1,0,0,HEIGHT,WIDTH,bg);
	root2buf();
}

int createWindow(int parent, int x, int y, int w, int h, char color){
	Window *newWin = new Window(cntWindow,y,x,h,w,color);
	Window *parentWin;
	if(parent==-1) parentWin=root;
	else parentWin=windows[parent];
	parentWin->addChild(newWin);

	updateRoot(root);
	root2buf();
	return cntWindow++;
}

void printWindows(){
	for(int y=0; y<HEIGHT; y++){
		printf("%s\n",DisplayBuf[y]);
	}
	printf("\n");
}

int main(){
	init('w');
	createWindow(-1,0,0,6,4,'b');
	printWindows();
	
	return 0;
}