#include <iostream>

using namespace std;

int MAP[100][100];
long long dp[100][100];
int N;

int main(void){
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> MAP[i][j];
		}
	}
	dp[0][0] = 1;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(dp[i][j] == 0 || (i==N-1 && j==N-1))
				continue;
			
			int num = MAP[i][j];
			int down = num + i;
			int right = num + j;
			
			if(down < N)
				dp[down][j] = dp[i][j] + dp[down][j];
			if(right < N)
				dp[i][right] = dp[i][j] + dp[i][right];
		}
	}
	cout << dp[N-1][N-1];
}

