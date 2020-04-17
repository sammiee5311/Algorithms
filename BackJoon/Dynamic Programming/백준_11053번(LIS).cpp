#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];
int values[1001];

int main(void){
	int n;
	cin >> n;
	
	dp[0]=1;
	
	for(int i=0; i<n; i++){
		cin >> values[i];
	}
	
	for(int i=1; i<n; i++){
		int max = 0;
		for(int j=0; j<i; j++){		
			if(values[j]<values[i] && dp[j]>max){
				max = dp[j];
			}
		}
		dp[i] = max+1;
	}
	
	for(int i=0; i<n; i++){
		cout << dp[i] << "\n";
	}
	
	int max = dp[0];
	for(int i=1; i<n; i++){
		if(dp[i] > max)
			max = dp[i];
	}
	cout << max;
}
