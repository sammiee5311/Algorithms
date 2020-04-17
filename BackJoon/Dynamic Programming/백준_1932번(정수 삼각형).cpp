#include <iostream>
#include <algorithm>

using namespace std;

int dp[502][502];
int a[502][502];

int main(void){
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cin >> a[i][j];
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
		}
	}
	
	int answer = 0;
	for(int i=1; i<=n; i++){
		answer = max(answer,dp[n][i]);
	}
	cout << answer;
}

