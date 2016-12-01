#include <cstdio>
#define MAX_N 500
#define HEIGHT 22
#define WIDTH 26

#define min(a,b) a>b?b:a
#define max(a,b) a<b?b:a

struct Window{
public:
	int handle;
	int x,y,w,h;
	Window *parent;
	Window *childs[MAX_N];
	int childCnt;
	char display[HEIGHT][WIDTH];
	Window(int handle, int x, int y, int w, int h, char bg) : handle(handle), x(x), y(y), w(w), h(h), childCnt(0){
		for(int y=0; y <HEIGHT; y++){
			for(int x=0; x <WIDTH; x++){
				display[y][x] = bg;
			}
		}
	}
	void addChild(Window *child){
		childs[childCnt++] = child;
	}
	void removeChild(int handle){
		int pos;
		for(pos=0; pos <childCnt; pos++){
			if(childs[pos]->handle == handle) break;
		}
		for(int i = pos; i < childCnt-1; i++){
			childs[i] = childs[i+1];
		}
		childCnt--;
	}
};

char DisplayBuf[HEIGHT][WIDTH];
int createdCnt;
Window *root;
Window *windows[MAX_N]; // handle 이 인덱스

void rootToDisplay(){
	for(int y = 0; y <HEIGHT; y++){
		for(int x = 0; x <WIDTH; x++){
			DisplayBuf[y][x] = root->display[y][x];
		}
	}
}

void updateTree(Window *here){
	for(int i = 0; i < here->childCnt; i++){
		updateTree(here->childs[i]);
	}
	if(here->handle != -1){
		Window *parent = here->parent;
		int x1 = max(0,here->x);
		int y1 = max(0,here->y);
		int x2 = min(WIDTH,here->x+here->w);
		int y2 = min(HEIGHT,here->y+here->h);

		for(int y = y1; y < y2; y++){
			for(int x = x1; x < x2; x++){
				parent->display[y][x] = here->display[y-here->y][x-here->x];
			}
		}
	}
}

void init(char bg){
	createdCnt=0;
	root = new Window(-1,0,0,160,120,bg);
}

int createWindow(int parent, int x, int y, int w, int h, char bg){
	Window *parentWindow;
	if(parent==-1) parentWindow = root;
	else parentWindow = windows[parent];
	Window *newWindow = new Window(createdCnt,x,y,w,h,bg);
	windows[createdCnt++] = newWindow;
	newWindow->parent = parentWindow;
	parentWindow->addChild(newWindow);
	updateTree(root);
	rootToDisplay();
	return createdCnt-1;
}

void destroyWindow(int handle){
	Window *target = windows[handle];
	Window *parentWindow = target->parent;
	parentWindow->removeChild(target->handle);

	updateTree(root);
	rootToDisplay();
}

void click(int x, int y){
	int pos;
	for(pos = root->childCnt-1; pos>=0; pos--){
		Window *child = root->childs[pos];
		if(child->x <= x && x < child->x+child->w && child->y <= y && y < child->y+child->h){
			break;
		}
	}
	if(pos!=-1) {
		Window *target = root->childs[pos];
		root->removeChild(target->handle);
		root->addChild(target);
	}

	updateTree(root);
	rootToDisplay();
}

void activateWindow(int handle){
	Window *target = windows[handle];
	while(target->parent->handle != root->handle)
		target = target->parent;
	root->removeChild(target->handle);
	root->addChild(target);
	updateTree(root);
	rootToDisplay();
}

void fillRect(int handle, int x, int y, int w, int h, char color){
	Window *target = windows[handle];
	int x1 = max(0,x);
	int y1 = max(0,y);
	int x2 = min(WIDTH,x+w);
	int y2 = min(HEIGHT,y+h);
	for(int y = y1; y < y2; y++){
		for(int x = x1; x < x2; x++){
			target->display[y][x] = color;
		}
	}

	updateTree(root);
	rootToDisplay();
}

void printDisplay(){ // DisplayBuf 출력 테스트용
	for(int y = 0; y < HEIGHT; y++){
		for(int x = 0; x < WIDTH; x++){
			printf("%c",DisplayBuf[y][x]);
		}
		printf("\n");
	}
	printf("\n\n");
}
int main(){ // DisplayBuf 출력 테스트용
	init('w');
	createWindow(-1,5,5,10,10,'b');
	createWindow(-1,10,10,7,7,'g');
	createWindow(0,6,6,2,2,'r');
	// activateWindow(0);
	click(14,14);
	printDisplay();
}