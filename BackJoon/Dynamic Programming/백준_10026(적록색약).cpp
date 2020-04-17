#include <iostream>
#include <queue>
#include <cstring>

using namespace std; 

int dx[8] = {1,-1,0,0};
int dy[8] = {0,0,1,-1};
int N,color=0,red=0;
bool visited[101][101];
char MAP[101][101];

queue<pair<int, int> >q;

void bfs(int x, int y){
	q.push(make_pair(x,y));
	visited[x][y] = true;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < N && ny < N){
				if(visited[nx][ny] == false && MAP[nx][ny] == MAP[x][y]){
					visited[nx][ny] = true;
					q.push(make_pair(nx,ny));
				}
			}
		}
		
	}
}

int main(void){
	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
		cin >> MAP[i][j];
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j] == false){
				bfs(i,j);
				color++;
			}
		}
	}
	
	memset(visited,false,sizeof(visited));
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(MAP[i][j] == 'G')
				MAP[i][j] = 'R';
		}
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j] == false){
				bfs(i,j);
				red++;
			}
		}
	}
	
	cout << color << " " << red;
}
