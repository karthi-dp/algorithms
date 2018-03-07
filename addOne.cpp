#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: Given a non negative integer represented as an array of digits, return the array such that number represented by resultant array is one greater than the original array
 * Author: Kartheek Diwakar Pingali
 *
 */


vector<int >res;
vector<int >A;
class Solution
{
	public:
	Solution(int n)
	{
		cout << "enter " << n << " elements ";
	       for(int i=0; i<n; i++)
	       {
		       int c;
		       cin >> c;
		       A.push_back(c);

		}
	}	
	vector<int >::iterator plusOne(vector<int>A);
};


vector<int>::iterator Solution::plusOne(vector<int> A)
{

	int n = A.size();
	reverse(A.begin(),A.end());
	int carry = 1;

	for(int i=0; i<n; i++)
	{

		int sum = A[i]+carry;
		res.push_back(sum%10);
		carry = sum/10;
		
	}

	while(carry)
	{
		res.push_back(carry%10);
		carry /= 10;
	}

	while(res[res.size()-1] == 0 && res.size() > 1)
	{
		res.pop_back();
	}


	reverse(res.begin(),res.end());
	vector<int >::iterator it = res.begin();
	return it;
	
}


int main()
{

	Solution obj(6);
	vector<int >::iterator it;
	it = obj.plusOne(A);
	for(; it != res.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
	return 0;
}
