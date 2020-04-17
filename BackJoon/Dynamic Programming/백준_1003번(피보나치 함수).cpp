#include <iostream>

using namespace std;

long long dp[100];

long long fivo(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else if(dp[n] != 0)
		return dp[n];
	else{
		return dp[n] =  fivo(n-1) + fivo(n-2);
	}
}

int main(void){
	int n;
	cin >> n;
	
	long long answer = fivo(n);
	cout << answer;
}
