#include <iostream>
#include <queue>

using namespace std;

int F,S,G,U,D;
int visited[1000001];

queue<pair<int,int> > q;

int bfs(){
	q.push(make_pair(S,0));
	visited[S] = 1;
	
	while(!q.empty()){
		int curr = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(curr == G)
			return cnt;
		
		if(curr + U <= F && visited[curr+U] == 0){
			q.push(make_pair(curr+U,cnt+1));
			visited[curr+U] = 1;
		}
		
		if(curr - D >= 1 && visited[curr-D] == 0){
			q.push(make_pair(curr-D,cnt+1));
			visited[curr-D] = 1;
		}
	}
	return -1;
}
int main(void){
	cin >> F >> S >> G >> U >> D;
	
	int ans = bfs();
	
	if(ans == -1)
		cout << "use the stairs";
	else
		cout << ans;
}
