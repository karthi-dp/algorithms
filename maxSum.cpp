/* Problem: Given an array of integers, identify the contiguous subarray that gives max sum
 * Hint: Apply kadane's algorithm for O(n)
 *
 */



#include<bits/stdc++.h>
using namespace std;
vector<int >input;

class Solution
{

	public:
		Solution(int n)
		{
			cout << "Enter " << n << " elements ";

			for(int i=0; i<n; i++)
			{
				int c;
				cin >> c;
				input.push_back(c);
			}
			
		}
		int maxSum();
};


int Solution::maxSum()
{

	int current_sum = 0;
	int max_sum = -1000000000;

	for(int i=0; i<input.size(); i++)
	{
		current_sum += input[i];
		max_sum = max(current_sum, max_sum);
		if(current_sum < 0) current_sum = 0;
			
	}

	return max_sum;

	

}


int main()
{


	Solution obj(6);
	cout << " Max sum: " << obj.maxSum() ;
	cout << "\n";
	return 0;



}
