#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[100001];
long long number[100001];

int main(void){
	cin >> n;
	long long ans=-10015;
	
	for(int i=0; i<n; i++){
		cin >> number[i];
	}
	
	dp[0] = number[0];
	ans = dp[0];
	
	for(int i=1; i<n; i++){
		dp[i] = max(dp[i-1]+number[i],number[i]);
		ans = max(ans,dp[i]);
	}
	
	cout << ans;
}
