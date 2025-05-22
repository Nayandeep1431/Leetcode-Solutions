// --> recursion
long long solve(int dice , int faces , int target){
	if(target < 0)
		return 0 ;
	if(dice == 0 && target != 0)
		return 0 ;
	if(target == 0 && dice != 0)
		return 0 ;
	if(dice == 0 && target ==0)
		return 1;
		
	int ans =0 ;	
	for(int i =1 ; i<= faces ; i++ ){
		ans = ans + solve(dice -1 , faces , target-i);
	}
	return ans ;				
}

// Memoization
long long solve(int dice , int faces , int target , vector<vector<int>> &dp){
	if(target < 0)
		return 0 ;
	if(dice == 0 && target != 0)
		return 0 ;
	if(target == 0 && dice != 0)
		return 0 ;
	if(dice == 0 && target !=0)
		return 1;
	if(dp[dice][target] != -1)
		return dp[dice][target]	 ;
	int ans =0 ;	
	for(int i =1 ; i<= faces ; i++ ){
		ans = ans + solve(dice -1 , faces , target-i) , dp;
	}
	return dp[dice][target] = ans  ;				
}

// Tabulation
long long solve( int dice ,int face , int t){
	vector<vector<long long>> dp(dice+1, vector<long long>(t+1 , 0));
	dp[0][0] = 1;
	
	for(int d = 1; d<= dice ; d++){
		for(int t =1 ; t<= target ; t++){
			long long ans =0 ;
			for(int i =1 ; i<= face ; i++){
				if(t - i >=0)
					ans = ans + dp[d-1][t-i];
			}
			dp[d][t] = ans ;
		}
	}
	return dp[dice][target];
}

long long noOfWays(int m , int n, int x){
	return solve(n , m , x);
	vector<vector<int>> dp(n+1 , vcetor<(target+1 , -1));
}
