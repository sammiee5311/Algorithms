#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int N,tmp;
	
	cin >> N;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	for(int i=0; i<N; i++){
		cin >> tmp;
		if(tmp == 0){
			if(pq.empty())
				cout << "0" << "\n";
			else{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else{
			pq.push(make_pair(abs(tmp), tmp));
		}
	}
}
