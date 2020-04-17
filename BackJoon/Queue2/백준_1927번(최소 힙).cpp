#include<cstdio>
#include<queue>
#include<vector>
 
using namespace std;
 
int main(void){
    int n;
    scanf("%d",&n);
    priority_queue<int, vector<int>, greater<int> > q;
    
    while(n--){
        int tmp;
        scanf("%d",&tmp);
        if(tmp == 0){
            if(q.empty())
                printf("0\n");
            else{
                printf("%d\n",q.top());
                q.pop();        
            }
        }
        else{
            q.push(tmp);
        }
    }
    return 0;
}
