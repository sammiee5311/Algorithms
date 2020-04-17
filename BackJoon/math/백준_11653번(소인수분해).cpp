#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10000001];
vector<int> v;

bool compare(int a,int b){
	return a > b;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int num;
	cin >> num;
	
	for(int i=2; i<=num; i++){
		if(num % i == 0){
			while(num % i == 0){
			v.push_back(i);
			num /= i;
			}
		}
		else
			continue;
	}
	
	sort(v.begin(),v.end(),compare);
	
	while(!v.empty()){
		cout << v.back() << "\n";
		v.pop_back();
	}
	
}
