int add(int a , int b){
	return (a % mod + b % mod) % mod ;
}
int multiply(int a , int b){
	return ((a % mod) * (b % mod) ) % mod ;
}
// -> recursion
int solve(int n , int k){
	if(n == 1)
		return k ;
	
	if(n ==2 )
		return add(k , multiply( k , k-1));	
	
	int ans = add(multiply(solve(n-2 , k) , k-1) , multiply(solve(n-1 , k), k-1));
	return ans ;	
}
// --> memoization
int solve(int n , int k , vector<int> & dp){
	if(n == 1)
		return k ;
	
	if(n ==2 )
		return add(k , multiply( k , k-1));	
	if(dp[n] != -1)
		returndp[n] ;
	dp[n] = add(multiply(solve(n-2 , k , dp) , k-1) , multiply(solve(n-1 , k ,dp), k-1));
	return dp[n] ;	
}

// --> Tabulation
int solve(int n , int k){
	vector<int> dp(n-1 , 0);
	dp[1] = k;
	dp[2] = add(k , multiply(k , k-1));
	
	for(int i =3 ; i<=n ; i++){
		dp[i] = add(multiply(dp[i-2] , k-1) ,multiply(dp[i-1] , k-1));
	}
	return dp[n] ;
}

// --> sapce optimization
int solve(int n , int k){
	vector<int> dp(n-1 , 0);
	prev2 = k;
	prev1 = add(k , multiply(k , k-1));
	
	for(int i =3 ; i<=n ; i++){
		dp[i] = add(multiply(prev2 , k-1) ,multiply(prev1 , k-1));
		prev2 = prev1 ;
		prev1 = ans
	}
	return prev1 ;
}
