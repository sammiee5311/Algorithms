#include <iostream>

using namespace std;

long long arr[101];

long long triangle(int n){
	if(n == 1 || n == 2 || n == 3)
		return 1;
	if(n == 4 || n == 5)
		return 2;
	if(n == 6)
		return 3; 
	if(arr[n] != 0)
		return arr[n];
		
	return arr[n] = triangle(n-1) + triangle(n-5);
		
}

int main(void){
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++){
		int n;
		cin >> n;
		cout << triangle(n) << "\n";
	}
	
}
