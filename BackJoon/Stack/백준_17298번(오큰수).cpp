#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
int a[1000000];
int ans[1000000];

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    s.push(1e7+1);
    for (int i=n-1; i>=0; i--){
        while(s.top() <= a[i]) s.pop();
        if (s.top() > 1e7) ans[i] = -1;
        else ans[i] = s.top();
        s.push(a[i]);
    }
    for (int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
