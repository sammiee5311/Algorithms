#include <iostream>

using namespace std;

int dp[101][10001];
int space[101];
int memory[101];
int N,M;
int ans = 987654321;

int main(void){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		cin >> space[i];
	}
	
	for(int i=0; i<N; i++){
		cin >> memory[i];
	}
		
	dp[0][memory[0]] = space[0];
	
	for(int i=1; i<N; i++){
		for(int j=0; j<=10000; j++){
			if(j-memory[i] >= 0)			
				dp[i][j] = max(dp[i][j],dp[i-1][j-memory[i]]+space[i]);
			
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
			
			if(dp[i][j] >= M)
				ans = min(ans,j);	
			}
	}
	
	cout << ans;
}
