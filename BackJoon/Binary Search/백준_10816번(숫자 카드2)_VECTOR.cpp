#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 500001

int N,M;
vector<int> card;
int target(MAX_N);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N;
	vector<int> v(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> v[i];
		
	sort(v.begin(), v.end());
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " "; 
	}
	cout << endl;
	return 0;
}
