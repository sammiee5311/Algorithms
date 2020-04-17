#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
vector<int> v;

int main(void){
	int num;
	cin >> num;
	
	for(int i=0; i<num; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}	
	
	sort(v.begin(), v.end());
	int answer = v[0]*v[num-1];
	cout << answer << "\n";
}
