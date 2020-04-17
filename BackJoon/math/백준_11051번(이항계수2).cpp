#include <iostream>

#define MAX 1001
#define Moduler 10007
using namespace std;

int N, K;
int dp[MAX][MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N >> K;
    
    for(int i=1; i<=N; i++){
		dp[i][1] = i;
		dp[i][i] = dp[i][0] = 1;
	}
	
	for(int i=2; i<=N; i++){
		for(int j=2; j<i; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % Moduler;
		}
	}
    
    cout << dp[N][K];
}
