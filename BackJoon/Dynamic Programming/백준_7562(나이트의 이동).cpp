#include <iostream>
#include <queue>
#include <cstring>

using namespace std; 

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int I,N;
bool visited[300][300];

pair<int, int> start,end;

void bfs(int a, int b){
	
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(a,b), 0));
	visited[a][b] = true;
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int Cnt = q.front().second;
		q.pop();
		
		if(x == end.first && y == end.second){
			cout << Cnt << "\n";
			return;
		}
		
		for(int i=0; i<8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < I && ny < I){
				if(visited[nx][ny] == false){
					visited[nx][ny] = true;
					q.push(make_pair(make_pair(nx,ny),Cnt+1));
				}
			}
		}
	}
}

int main(void){
	cin >> N;

	for(int i=1; i<=N; i++){
		cin >> I;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		
		bfs(start.first,start.second);
		memset(visited, false, sizeof(visited));
	}
}
