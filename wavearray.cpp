/*
 * Problem: Given an array, arrange the elements such that a1>=a2<=a3>=a4<=a5...
 * Author: Kartheek Diwakar Pingali
 *
 */

#include<bits/stdc++.h>
using namespace std;

vector<int >input;

class Solution{


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
		
		vector<int >::iterator waveArray();


};


vector<int >::iterator Solution::waveArray()
{


	int n=input.size();

	for(int i=0; i<n; i+=2)
	{
		swap(input[i],input[i+1]);
	}

	vector<int >::iterator it = input.begin();
	return it;
}



int main()
{
	Solution obj(6);
	vector<int >::iterator it;

	it = obj.waveArray();
	for(;it != input.end(); it++)
	{
		cout << *it << " ";
	}
	
	cout << "\n";
	return 0;

}
