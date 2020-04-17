#include <iostream>
#include <string>

using namespace std;

int map[64][64];

void check(int x, int y, int size){
	
	if(size == 1){
		cout << map[y][x];
		return;
	}
	
	bool zero=true,one=true;
	
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(map[i][j])
				zero = false;
			else
				one = false;
		}
	}
	
	if(zero)
		cout << 0;
	else if(one)
		cout << 1;
		
	else{
		cout << "(";
		check(x,y,size/2);
		check(x+size/2,y,size/2);
		check(x,y+size/2,size/2);
		check(x+size/2,y+size/2,size/2);
		cout << ")";
	}
			
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
    bool zero = true, one = true;
    for (int i = 0; i < n; i++)
   {
		string s;
        cin >> s;
        
       	for (int j = 0; j < n; j++)
			map[i][j] = s[j] - '0';
    }
	
	check(0,0,n);
	cout << "\n";
	
}
