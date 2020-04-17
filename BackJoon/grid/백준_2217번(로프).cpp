#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main(void){
	int n;
	cin >> n;
		
	vector<int> v(n,0);
	
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	
	sort(v.begin(),v.end(),compare);
	
	int answer = 0;
	int j = 1;
	
	for(int i=0; i<v.size(); i++){
		answer = max(answer,v[i]*j);
		j++;
	}
	
	cout << answer;
}
