
mat[1][1] = dp[1][1];

for(int i=1; i<=n; i++){
	for(int j=1; j<=n; j++){
		if(i==1)
			dp[i][j] = dp[i][j-1] + mat[i][j];
		if(j==1)
			dp[i][j] = dp[i-1][j] + mat[i][j];
		
		dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + mat[i][j];
	}
}
