#include <iostream>

using namespace std;

int N,cnt=0;
int money[6] = {500,100,50,10,5,1};

int main(void){
	cin >> N;
	
	N = 1000 - N;
	
	while(1){
		for(int i=0; i<6; i++){
			if(N >= money[i]){
				N = N-money[i];
				cnt++;
				break;
			}
		}
		if(N == 0)
			break;
	}
	cout << cnt;
}
