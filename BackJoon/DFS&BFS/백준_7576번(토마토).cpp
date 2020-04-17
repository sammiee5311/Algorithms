#include <iostream>
#include <queue>

using namespace std;

int M,N;
int MAP[1001][1001];
int visited[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


int main(void){
	cin >> M >> N;
	queue <pair<int,int> > q;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> MAP[i][j];
			if(MAP[i][j] == 1){
				q.push({i,j});
				visited[i][j] = 1;
			}
		}
	}
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if(MAP[nx][ny] == 0 && visited[nx][ny] == 0){
				visited[nx][ny] = visited[x][y] + 1;
				q.push({nx,ny});
			}
		}
	}
	int result = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			result = max(result,visited[i][j]);
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(MAP[i][j] == 0 && visited[i][j] == -1)
				result = -1;
		}
	}
	
	cout << result;
}
