// count derangements
// --> recursion
long long countDeragnment(int n){
	if(n == 1)
		return 0 ;
	
	if(n == 2)
		return 1;
	
	int ans = [(n-1) % mod * [(countDeragnment(n-1) %mod + countDeragnment(n-2) % mod )] % mod ] % mod;
	return ans ;		
}
// -> memoization
long long countDeragnment(int n , vector<int> & dp){
	if(n == 1)
		return 0 ;
	
	if(n == 2)
		return 1;
		
	if(dp[n] != -1)
		return dp[n];
		
	dp[n] = [(n-1) % mod * [(countDeragnment(n-1) %mod + countDeragnment(n-2) % mod )] % mod ] % mod;
	return dp[n]  ;		
}

// --> tabulation
long long solve(int n){
	vector<long long int> dp(n+1 , 0);
	dp[1] =0 ;
	dp[2] =1 ;
	
	for(int i =3 ; i<= n ; i++){
		long long int first = dp[i-1] % mod ;
		long long int second = dp[i-2] % mod ;
		long long int sum = (first +second) % mod ;
		
		long long int ans = ((n-1) * sum)% mod ;
		dp[i] = ans ;
		
	}
	return dp[n] ;
}

// -> space optimisation
long long solve(int n){
	long long prev2 =0 ;
	long long prev1 = 1 ;
	
	for(int i =3 ; i<= n ; i++){
		long long int first = dp[i-1] % mod ;
		long long int second = dp[i-2] % mod ;
		long long int sum = (first +second) % mod ;
		
		long long int ans = ((n-1) * sum)% mod ;
		prev2 = prev1 ;
		prev1 = ans ;
		
	}
	return prev1  ;
}
