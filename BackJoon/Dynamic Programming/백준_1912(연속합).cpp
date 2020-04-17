#include <iostream>

using namespace std;

int num[100001];
int dp[100001];

int main(void){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	
	int dp[0] = num[0];
	
	for(int i=1; i<n; i++){
		dp[i] = dp[i-1] + num[i];
	}
	
}
