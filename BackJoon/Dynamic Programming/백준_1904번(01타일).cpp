#include <iostream>

using namespace std;

long long arr[1000000];

long long tile(int n){
	if(n == 1) 
		return 1;
	if(n == 2) 
		return 2;
	if(arr[n] != 0) 
		return arr[n];
	return arr[n] = (tile(n-1) + tile(n-2)) % 15746;
}


int main(void){
	int n;
	cin >> n;
	
	cout << tile(n);
}
