//KnapSack Problem...

//2-D dp
//Theif problem

int solve(vector<int>& weight, vector<int>& value, int index, int capacity ) {
	//Base case
	//if only 1 item to steal, then just compare its weight to its knapsack capacity
	
	if (index == 0) {
		if( weight[0] <= capacity)
		return value[0];
		else
		return 0;
	} 
	
	int include = 0;
	if(weight[index] <= capacity)
	include = value[index] + solve(weight, value, index-1, capacity - weight[index]);
	
	int exclude = 0 + solve(weight, value, index-1, capacity);
	
	int ans = max(exclude,include);
	return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return solve(weight, value, n-1, maxWeight);
}


//Using Memoization(Top-Down dp)...


int solveMem(vector<int>& weight, vector<int>& value, int index, int capacity,
vector<vector<int> >& dp) {
	//Base case
	//if only 1 item to steal, then just compare its weight to its knapsack capacity
	
	if (index == 0) {
		if( weight[0] <= capacity)
		return value[0];
		else
		return 0;
	} 
	
	if(dp[index][capacity] != -1)
	return dp[index][capacity];
	
	int include = 0;
	if(weight[index] <= capacity)
	include = value[index] + solveMem(weight, val, index-1, capacity - weight[index],dp);
	
	int exclude = 0 + solveMem(weight, val, index-1, capacity, dp);
	
	dp[index][capacity] = max(exclude,include);
	return dp[index][apacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
//	return solve(weight, value, n-1, maxWeight);

vector<vector<int> > dp(n, vector<int>(maxWeight+1, -1));// 2D dp for rows and columns
return solveMem(weight, value, n-1, maxWeight, dp);   

}

//Using Tabulation(Bottom-Up dp)...


int solveTab(vector<int>& weight, vector<int>& value, int index, int capacity) {
	//Step 1...
	vector<vector<int> > dp(n, vector<int>(capacity+1, 0));
		
	//Step 2: Analyse Base Case...
	for(int w = weight[0]; w<=capacity; w++) {
		if(weight[0] <= capacity)
		dp[0][w] = value[0];
		else
		dp[0][w] = 0;
	}	
	
	//step3: Take care of remaining recursive calls
	for(int index = 1; index<n; index++) {
		for(w = 0; w<=capacity; w++) {
			int include = 0;
			
			if(weight[index] <= w)
			include = value[index] + dp[index - 1][w - weight[index]];
			
			int exclude = 0 + dp[index-1][w];
			
			dp[index][w] = max(exclude, include);
			
		}
	}
	return dp[n-1][capacity];
	   
}
//s.c: O(n*maxWeight)...
	 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
return solveTab(weight, value, n, maxWeight);
}

//Using Space Optimization...


int solveTabSO(vector<int>& weight, vector<int>& value, int index, int capacity) {
	//Step 1...
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);
    
    //step2: Analyse base case
    for(int w = weight[0]; w<=caapcity; w++) {
    	if(weight[0] <= capacity)
    	prev[w] = value[0];
    	else
    	prev[w] = 0;
	}

    //step3: take care of remaining recursive calls...
    
    for(int index = 1; index<n; index++) {
    	for(int w = 0; w<=capacity; w++) {
    		
    		int include = 0;
    		
    		if(weight[index] <= w)
    		include = value[index] + prev[w-weight[index]];
    		
    		int exclude = 0 + prev[w];
    		
    		curr[w] = max(exclude, include);
		}
		
		prev = curr;
	}
    return prev[capacity];

}
//s.c: O(2*maxWeight)

	 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
return solveTab(weight, value, n, maxWeight);
}

//Using More Space Optimization...


int solveTabMSO(vector<int>& weight, vector<int>& value, int index, int capacity) {
	//Step 1...
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);
    
    //step2: Analyse base case
    for(int w = weight[0]; w<=caapcity; w++) {
    	if(weight[0] <= capacity)
    	curr[w] = value[0];
    	else
    	curr[w] = 0;
	}

    //step3: take care of remaining recursive calls...
    
    for(int index = 1; index<n; index++) {
    	for(int w = capacity; w>=0; w--) { //most impotant line as we are traversing 
    	//from the end (non dependent part)...
    		
    		int include = 0;
    		
    		if(weight[index] <= w)
    		include = value[index] + prev[w-weight[index]];
    		
    		int exclude = 0 + curr[w];
    		
    		curr[w] = max(exclude, include);
		}
		
		
	}
    return curr[capacity];
}
//s.c: O(maxWeight)... due to only one CURR array...

