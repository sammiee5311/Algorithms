#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int MAP[129][129];
int white=0,blue=0;


void count(int xs, int ys,int xe, int ye){

	int color = MAP[xs][ys];
	
	for(int i=xs; i<xe; i++){
		for(int j=ys; j<ye; j++){
			if(color == 1 && MAP[i][j] != 1)
				color = 2;
			if(color == 0 && MAP[i][j] != 0)
				color = 2;
			if(color == 2){
				count(xs,ys,(xs+xe)/2,(ye+ys)/2);
				count((xs+xe)/2,ys,xe,(ye+ys)/2);
				count(xs,(ys+ye)/2,(xe+xs)/2,ye);
				count((xs+xe)/2,(ys+ye)/2,xe,ye);
				return;
			}
		}
	}
	
	if(color == 1)
		blue++;
	else if(color == 0)
		white++;
}

int main(void){
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> MAP[i][j];
		}
	}
	
	count(0,0,N,N);
	
	cout << white << "\n";
	cout << blue << "\n";
}
