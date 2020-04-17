#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
 
using namespace std;
 
int dp[502][502];
int arr[502];
int pSum[502];
 
int main()
{
    int tc;
    scanf("%d", &tc);
 
    while (tc--)
    {
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));
 
        int n;
        scanf("%d", &n);
 
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            pSum[i] = pSum[i - 1] + arr[i];
        }
 
        for (int i = 2; i <= n; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                dp[j][i] = 987654321;
                for (int k = j; k <= i; k++)
                    dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i]);
 
                dp[j][i] += pSum[i] - pSum[j - 1];
            }
        }
        printf("%d\n", dp[1][n]);
 
    }
    return 0;
}
