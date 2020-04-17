#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101];
vector<pair<int,int> > v;

int main(void){
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}

	sort(v.begin(),v.end());
	
	for(int i=0; i<n; i++){
		int max=0;
		for(int j=0; j<i; j++){
			if(v[j].second < v[i].second && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	
	int max = dp[0];
	
	for(int i=1; i<n; i++){
		if(dp[i] > max)
			max = dp[i];
	}
	
	cout << v.size() - max;
}
