#include <iostream>
#include<cstring>

using namespace std;

int dp[31][31];
int n;

int main(void){
	cin >> n;
	
	for(int i=0; i<n; i++){
		int A,B;
		cin >> A >> B;
		
		for(int i=1; i<=B; i++){
			dp[1][i] = i;
		}
		
		for(int i=2; i<=A; i++){
			for(int j=i; j<=B; j++){
				for(int k=j; k>=i; k--){
					dp[i][j] = dp[i][j] + dp[i-1][k-1];
				}
			}
		}
		
		cout << dp[A][B] << "\n";
		
		memset(dp,0,sizeof(dp));
	}
}
