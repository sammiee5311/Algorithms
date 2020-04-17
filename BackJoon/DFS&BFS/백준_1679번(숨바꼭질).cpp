#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int N,K;
bool visit[MAX];

int bfs(int n,int k){
	
	queue<pair<int, int> > q;
	q.push(make_pair(n,0));
	visit[n] = 1;
	
	while(!q.empty()){
		int now = q.front().first;
		int later = q.front().second;
		q.pop();
		
		if(now == k)
			return later;
			
		if(now + 1 <= MAX && !visit[now+1]){
			q.push(make_pair(now+1,later+1));
			visit[now+1] = 1;
		}
		
		if(now - 1 >= 0 && !visit[now-1]){
			q.push(make_pair(now-1,later+1));
			visit[now-1] = 1;
		}
		
		if(now * 2 <= MAX && !visit[now*2]){
			q.push(make_pair(now*2,later+1));
			visit[now*2] = 1;
		}
	}
}

int main(void){
	cin >> N >> K;
	cout <<	bfs(N,K) << "\n";
}
