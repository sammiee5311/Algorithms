#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(a%b == 0)
		return b;
	else
		return gcd(b, a%b);
}

int main(void){
	int N,x;
	cin >> N;
	
	vector<int> v;
	vector<int> num;
	
	for(int i=0; i<N; i++){
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	
	int GCD = v[1] - v[0];
	for(int i=2; i<N; i++){
		GCD = gcd(GCD,v[i] - v[i-1]);
	}
	
	for(int i=2; i*i <=GCD; i++){
		if(GCD % i == 0){
			num.push_back(i);
			num.push_back(GCD/i);
		}
	}
	
	num.push_back(GCD);
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	
	for(int i=0; i<num.size(); i++){
		cout << num[i] << " ";
	}
	
	cout << "\n";
}
