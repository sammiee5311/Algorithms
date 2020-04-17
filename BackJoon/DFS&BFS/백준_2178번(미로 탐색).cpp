#include <iostream>
#include <queue>

using namespace std;

int n,m;
bool visited[100][100];
char MAP[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(){
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0,0),1));
	visited[0][0] = 1;
	
	while(!q.empty()){
		
		int x = q.front().first.second;
		int y = q.front().first.first;
		int z = q.front().second;
		
		q.pop();
		
		if(x == m-1 && y == n-1)
			return z;
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >=m || ny < 0 || ny >=n)
				continue;
			if(visited[ny][nx] == 1)
				continue;
			if(MAP[ny][nx] != '1')
				continue;
				
			q.push(make_pair(make_pair(ny,nx), z+1));
			visited[ny][nx] = 1;
		}
	}
}

int main(void){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		cin >> MAP[i];
	}
	
	cout << bfs();
}
