#include <iostream>
#include <algorithm>

using namespace std;

int card[600000];
int serch[600000];
 
int twoserch(int left, int right, int count ,int serchnum){
    int mid = (left + right) / 2;
    int result;
    if (left > right)
        return 0;
    else {
        if (card[mid] > serchnum){
            result = twoserch(left, mid-1, count, serchnum);
        }
        else if (card[mid] < serchnum)
        {
            result = twoserch(mid +1, right, count, serchnum);
        }
        else{
        
            result = twoserch(left, mid - 1, count, serchnum);
            result += twoserch(mid + 1, right, count, serchnum);
            result += 1;
        }
 
        return result;
    }
}
 
int main(void){

    ios::sync_with_stdio(false);
    
    int N, M;
 
    cin >> N;
 
    for (int i = 0; i < N; i++)
        cin >> card[i];
 
    cin >> M;
 
    for (int i = 0; i < M; i++)
        cin >> serch[i];
 
    sort(card, card + N);
 
    for (int i = 0; i < M; i++){
        int searchNum = serch[i];
        int left = 0, right = N-1;
        int mid;
        int count = 0;
        
        cout << twoserch(left, right,0 , searchNum) << " ";
 
    }
}
