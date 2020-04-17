#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
int countW = 0;
int countB = 0;
int map[130][130];
 
void divCon(int xs, int ys, int xe, int ye){
	int color = map[xs][ys];
	
	for(int x=xs; x<xe; x++){
		for(int y=ys; y<ye; y++){
			if(color == 1 && map[x][y] != 1)
				color = 2;
			if(color == 0 && map[x][y] != 0)
				color = 2;
			if(color == 2){
				divCon(xs,ys,(xs+xe)/2,(ys+ye)/2);
				divCon((xs+xe)/2,(ys+ye)/2,xe,ye);
				divCon((xs+xe)/2,ys,xe,(ys+ye)/2);
				divCon(xs,(ys+ye)/2,(xs+xe)/2,ye);
				return;
			}
		}
	}
	
	if(color==0)
		countW++;
	else if(color==1)
		countB++;
} 
 
int main(int argc, char *argv[])
{
	int n;
	cin >> n;
 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
 
	divCon(0, 0, n, n);
 
	cout << countW << endl;
	cout << countB << endl;
 
	return 0;
}
