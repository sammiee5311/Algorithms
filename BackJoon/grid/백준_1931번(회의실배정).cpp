#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int,int> a,
			 pair<int,int> b){
		if(a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
}


int main(void){
	int n;
	cin >> n;
	
	vector<pair<int,int> > v;
	
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		v.push_back(pair<int,int>(a,b));
	}
	
	sort(v.begin(),v.end(),compare);

	
	for(int i=0; i<v.size(); i++){
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	
	int end=0;
	int cnt=0;
	
	for(int i=0; i<v.size(); i++){
		if(end <= v[i].first){
			end = v[i].second;
			cnt++;
		}
	}
	
	cout << cnt;
}
