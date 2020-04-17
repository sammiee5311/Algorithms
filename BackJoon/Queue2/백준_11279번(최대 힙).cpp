#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,tmp;
	cin >> N;
	
	priority_queue<int> q;

	for(int i=0; i<N; i++){
		cin >> tmp;
		if(tmp == 0){
			if(q.empty())
				cout << "0" << "\n";
			else{
				int ans = q.top();
				cout << ans << "\n";
				q.pop();
			}
		}
		else{
			q.push(tmp);
		}
			
	}
	
}
