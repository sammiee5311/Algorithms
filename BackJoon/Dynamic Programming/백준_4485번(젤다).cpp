#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int MAP[125][125];
bool visited[125][125];
int N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void){
	
	while(1){
		cin >> N;
		
		if(N == 0)
			break; 
		
		memset(MAP,0,sizeof(MAP));
		memset(dp,0,sizeof(dp));
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> MAP[i][j];
			}
		}
	}
}
