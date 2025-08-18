// Approach 1 (Recursion)
int solve(int start , int cnt , int n , int maxVal){
	if(cnt == n)
		return 1 ;
	
	long long result = 0 ;
	for(int multiplier = 1 ; start * multiplier <= maxVal ; multiplier++){
		result = (result + solve(start * multiplier , cnt +1 , n , maxVal)) % MOD ;
	}	
	return result ;
}

int idealArrays(int n , int maxValue){
	long long result = 0 ;
	
	for(int startVal = 1; startVAL <= maxVal ; startVal++){
		result = (result + solve(startVal , 1 , n , maxVal)) % MOD ;
	}
	return result ;
}

// Appraoch 2 (Memoization)
vector<vector<int>> & dp ;
int solve(int start , int cnt , int n , int maxVal){
	if(cnt == n)
		return 1 ;
		
	if(dp[start][count] != -1)
		return dp[start][count] ;
		
	long long result = 0 ;
	for(int multiplier = 1 ; start * multiplier <= maxVal ; multiplier++){
		result = (result + solve(start * multiplier , cnt +1 , n , maxVal)) % MOD ;
	}	
	return dp[start][count] = result ;
}

int idealArrays(int n , int maxValue){
	long long result = 0 ;
	dp.resize(maxVal +1 , vector<int> (n+1 , -1)) ;
	for(int startVal = 1; startVAL <= maxVal ; startVal++){
		result = (result + solve(startVal , 1 , n , maxVal)) % MOD ;
	}
	return result ;
}
