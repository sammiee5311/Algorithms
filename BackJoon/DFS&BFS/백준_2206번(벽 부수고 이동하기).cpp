#include <iostream>
#include <queue>

int N,M;
int MAP[1001][1001];
bool check[1001][1001][2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

using namespace std;

int bfs(){
	queue <pair<pair<int,int>, pair<int,int> > > q;
	q.push(make_pair(make_pair(0,0), make_pair(0,1)));
	check[0][0][0] = 1;

	
	while(!q.empty()){
		
		int x = q.front().first.first;
		int y = q.front().first.second;
		int B = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		
		if(x == N-1 && y == M-1)
			return cnt;
		
		for(int k=0; k<4; k++){
			
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (MAP[nx][ny] == 1 && B == 0)
                {
                    check[nx][ny][B+1] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(B + 1, cnt + 1)));
                }
                else if (MAP[nx][ny] == 0 && check[nx][ny][B] == false)
                {
                    check[nx][ny][B] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(B, cnt + 1)));
                }
            }
		}
	}
	return -1;
}

int main(void){

	cin >> N >> M;
	
    for (int i = 0; i < N; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < M; j++)
        {
            int Tmp = Inp[j] - '0';
            MAP[i][j] = Tmp;
        }
    }
	
	cout << bfs();

}
