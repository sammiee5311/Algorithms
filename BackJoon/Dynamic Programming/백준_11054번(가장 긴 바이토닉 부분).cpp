#include <iostream>

using namespace std;

int lis[1001];
int rlis[1001];
int num[1001];

int main(void){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	
	lis[0] = 1;
	rlis[0] = 1;
	
	for(int i=1; i<n; i++){
		int max = 0;
		for(int j=0; j<i; j++){
			if(num[j] < num[i] && lis[j]>max)
				max = lis[j];
		}
		lis[i] = max + 1;
	}
	
	for(int i=n-1; i>=0; i--){
		int max = 0;
		for(int j=n-1; j>i; j--){
			if(num[j] < num[i] && rlis[j]>max)
				max = rlis[j];
		}
		rlis[i] = max + 1;
	}
	
	int max = 0;
	for(int i=0; i<n; i++){
		if(lis[i]+rlis[i] > max)
			max = lis[i]+rlis[i];
	}
	cout << max-1;
}
