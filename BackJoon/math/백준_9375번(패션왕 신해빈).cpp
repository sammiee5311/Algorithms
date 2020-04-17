#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];
int main(void){
	int N,C;
	cin >> N;
	vector<pair<string, string> > v;
	for(int i=0; i<N; i++){
		cin >> C;
		for(int j=0; j<C; j++){
			string A,B;
			cin >> A >> B;
			v.push_back(pair<string, string>(A,B));
		}
		sort(v.begin(),v.end());
		for(int c=0; c<C; c++){
			cout << v[c].second << "\n";
		}
		v.clear();
	}
}
