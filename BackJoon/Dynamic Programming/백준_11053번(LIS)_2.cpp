#include <iostream>

using namespace std;

int dp[1001];
int value[1001];

int main(void){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> value[i];
		dp[i] = 1;
	}
	
	for(int i=0; i<n; i++){
		int max = 0;
		for(int j=0; j<i; j++){
			if(value[j]<value[i] && max<value[j]){
				max = value[j];
				dp[i]++;
			}
		}
	}
	
	int max = dp[0];

	for(int i=1; i<n; i++){
		if(dp[i] > max)
			max = dp[i];
	}

	cout << max;
}
