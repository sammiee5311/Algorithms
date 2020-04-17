#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int main(void){
	cin >> N;
	vector<pair<int, int> > v(N);
	
	for(int i=0; i<N; i++){
		cin >> v[i].first >> v[i].second;
	}
	
	for(int i=0; i<N; i++){
		queue<pair<int, string> > q;
		vector<bool> visited(10000,0);
		q.push(make_pair(v[i].first,""));
		visited[v[i].first] = 1;
		
		while(!q.empty()){
			int now = q.front().first;
			string way = q.front().second;
			q.pop();
			
			if(now == v[i].second){
				cout << way << "\n";
				break;
			}
			
			else{
				int next = (now*2) % 10000;
				if(!visited[next]){
					visited[next] = true;
					q.push(make_pair(next,way+"D"));
				}
				if(now == 0){
					next = 9999;
				}
				else{
					next = now-1;
				}
				if(!visited[next]){
					visited[next] = true;
					q.push(make_pair(next,way+"S"));
				}
				if(now != 0){
					next = (now%1000)*10 + now/1000;
					if(!visited[next]){
						visited[next] = true;
						q.push(make_pair(next,way+"L"));
					}
					
					next = (now%10)*1000 + now/10;
					if(!visited[next]){
						visited[next] = true;
						q.push(make_pair(next,way+"R"));
					}
				}
			}
		}
		
	}
}
