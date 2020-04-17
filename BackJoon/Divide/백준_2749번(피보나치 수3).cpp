#include <iostream>

using namespace std;

long long dp[1500000];
int INF = 1000000;

void fibo(){
	dp[0] = 0;
	dp[1] = 1;
	for(int i=0; i<1500000; i++){
		dp[i+2]=(dp[i+1]%INF + dp[i]%INF) % INF;
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	fibo();
	cout << dp[n%1500000] << "\n";
}
