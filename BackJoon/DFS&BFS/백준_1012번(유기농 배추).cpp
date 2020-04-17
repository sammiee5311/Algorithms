#include <iostream>
#include <string.h>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int MAP[51][51];
bool visited[51][51];
int T,K,cnt,M,N;

void dfs(int x, int y){
	
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(ny<0 || ny>=N || nx<0 || nx >=M)
			continue;
		
		if(MAP[nx][ny] == 1 && !visited[nx][ny]){
			visited[nx][ny] = true;
			dfs(nx,ny);
		}
		
	}
}

int main(void){
	cin >> T;
	
	for(int i=0; i<T; i++){
		
		memset(MAP,0,sizeof(MAP));
        memset(visited,0,sizeof(visited));
        
        int cnt=0;
        
		cin >> M >> N;
		cin >> K;
		for(int j=0; j<K; j++){
			int a,b;
			cin >> a >> b;
			MAP[a][b] = 1;
		}
		
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				if(MAP[i][j] == 1 && !visited[i][j]){
					cnt++;
					visited[i][j] = true;
					dfs(i,j);
				} 
			}
		}
		
		cout << cnt << "\n";
	}
}
