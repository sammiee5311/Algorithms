#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int value[1001];

int main(void){
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> value[i];
	}
	
	dp[1] = value[1];
	if(n > 1)
		dp[2] = value[1] + value[2];
	
	for(int i=3; i<=n; i++){
		dp[i] = max(dp[i-3]+value[i-1]+value[i],dp[i-2]+value[i]);
		dp[i] = max(dp[i],dp[i-1]);
	}

	cout << dp[n];
}
