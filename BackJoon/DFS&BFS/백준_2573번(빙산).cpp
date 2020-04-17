#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int MAP[101][101];
int c_MAP[101][101];
bool visited[101][101];
int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int a, int b){
	queue<pair<int, int> > q;
	q.push(make_pair(a,b));
	visited[a][b] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < N && ny < M){
				if(visited[nx][ny] == 0 && MAP[i][j] != 0){
					visited[nx][ny] = 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int melt(int x, int y){
	int cnt=0;
	
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(MAP[nx][ny] == 0)
			cnt++;
	}
}
int main(void){
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> MAP[i][j];
		}
	}
	
	int year = 0;
	
	while(1){
		int land_cnt = 0;
		memset(visited,false,sizeof(visited));
		memset(c_MAP,0,sizeof(c_MAP));
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(MAP[i][j] != 0 && visited[i][j] == 0){
					land_cnt++;
					bfs(i,j);
				}
			}
		}
	
		if(land_cnt >= 2){
			cout << year;
			break;
		}
		if(land_cnt == 0){
			cout << 0;
			break;
		}
	
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(MAP[i][j] != 0){
					c_MAP[i][j] = MAP[i][j] - melt(i,j);
					if(c_MAP[i][j] < 0)
						c_MAP[i][j] = 0;
				}
			}
		}
	
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				MAP[i][j] = c_MAP[i][j];
			}
		}
	
		year++;
	}
}
