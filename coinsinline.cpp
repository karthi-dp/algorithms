/*
 * Problem: 
 * Given a set of coins, With players in each turn a player can pick either first coin or last coin
 * Assuming you start the game, what is the max that you can win
 * Total number of coins are even
 *
 * Author: Kartheek Diwakar 
 */

#include <bits/stdc++.h>

using namespace std;

int dp[1002][1002];

int rec(vector<int>&A, int i, int j)
{

	if(i==j)
		return A[j];
	if(j==i+1)
		return max(A[i],A[j]);

	int sum1 = 0;
	int sum2 = 0;

	sum1 += A[i] + min(rec(A,i+2,j), rec(A,i+1,j-1));
	sum2 += A[j] + min(rec(A,i,j-2), rec(A,i+1,j-1));
	return dp[i][j] = max(sum1,sum2);
}



class Solution
{
	public:
		int maxcoin(vector<int> &A);

};


int Solution::maxcoin(vector<int> &A)
{

	int n = A.size();
	memset(dp,0,sizeof(dp));
	return rec(A,0,n-1);
}

int main()
{

	vector<int> A;

	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);

	Solution obj;
	cout << "First player can win a max value: " << obj.maxcoin(A);
	cout << endl;

	return 0;




}
