#include <iostream>
#include <cstring>

using namespace std;

int arr[3];
int map[2200][2200];


bool check(int x, int y, int size){
	int right = map[x][y];
	
	for(int i=x; i<x+size; i++){
		for(int j=y; j<y+size; j++){
			if(right != map[i][j])
				return false;
		}
	}
	return true;
}

void count(int x, int y, int size){
	if(check(x,y,size)){
		int right = map[x][y];
		if(right == -1)
			arr[0]++;
		else if(right == 0)
			arr[1]++;
		else if(right == 1)
			arr[2]++;
	}
	
	else{
		int newsize = size/3;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				count(x+(i*newsize),y+(j*newsize),newsize);
			}
		}
	}
}


int main(void){
	ios::sync_with_stdio(false);
    cin.tie(0);
    
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> map[i][j];
		}
	}
	
	count(1,1,n);
	
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
}
