#include <iostream>

using namespace std;

int arr[100], arr2[100];

int gcd(int a, int b){
	if(a % b == 0)
		return b;
	else
		return gcd(b, a%b);
}
int main(void){
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	
	for(int i=1; i<N; i++){
		int GCD = gcd(arr[0],arr[i]);
		cout << arr[0] / GCD << "/" << arr[i] / GCD;
		cout << "\n";
	}
	
}
