#include <iostream>

using namespace std;

long long d[100];

int zero = 0, one = 0;

long long fivo(int n){
	if(n == 0){
		zero++;
		return 0;
	}
	if(n == 1){
		one++;
		return 1;
	}
	if(d[n] != 0)
		return d[n];
	else{
	return d[n] = fivo(n-1) + fivo(n-2);
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	long long answer = fivo(n);
	cout << answer << "\n";
}
