#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(void){
	string str1,str2;
	cin >> str1 >> str2;

	for(int i=1; i<=str2.length(); i++){
		for(int j=1; j<=str1.length(); j++){
			if(str2.at(i-1) == str1.at(j-1)){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	cout << dp[str1.length()][str2.length()];
}
