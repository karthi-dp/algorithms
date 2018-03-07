/*
 * Problem: Given an array of numbers, obtain the largest number that can be obtained by combining these numbers and return it as a string
 * Author: Kartheek Diwakar Pingali
 *
 */



#include <bits/stdc++.h>
using namespace std;

vector<int >input;

class Solution
{
	public:
		Solution(int n)
		{
			cout << "Enter the elements of the array: ";
			for(int i=0; i<n; i++)
			{
				int c;
				cin >> c;
				input.push_back(c);
			}
		}
		string largestNumber();
};


bool my_compare(int A, int B)
{
	string AB = to_string(A).append(to_string(B));
	string BA = to_string(B).append(to_string(A));

	return AB.compare(BA) > 0 ? 1:0;
}


string Solution::largestNumber()
{

	sort(input.begin(), input.end(), my_compare);
	string res = " ";

	for(int i=0; i<input.size(); i++)
	{
		res += to_string(input[i]);
	}

	if(res[0] == '0')
	{
		return "0";
	}

	return res;
}



int main()
{

	Solution obj(6);
	string res = obj.largestNumber();
	cout << "largest Number: " << res;
	cout << "\n";
	return 0;
}
