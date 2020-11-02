/*
	Author: Valeria Montagna
	
	Solution Description:
	The idea is to compute an array B. At every position i of B it is stored the number of times in which 
	we have s(k) = s(k+1) (for k that goes from 0 to i).
	Building this array before the queries, we can compute any range query [l, r] returning the difference
	between B[r-1] and B[l-1].

	Complexity: 
	Since we need to build array B so that we can answer range queries in O(1), this solution 

*/


#include<iostream>
#include<vector>
#include<map>


int main(int argc, char const *argv[])
{
	std::string str;

	std::cin >> str;
	std::vector<char> v(str.begin(), str.end());

	std::vector<int> b;
	b.reserve(v.size());

	int sum_prefix = 0;
	b.push_back(sum_prefix);

	for (int i = 0; i < v.size() - 1; ++i)
	{
		if(v[i] == v[i+1])
			sum_prefix += 1;

		b.push_back(sum_prefix);
	}


	int m = 0;
	scanf("%d", &m);

	for (int i = 0; i < m; ++i)
	{
		int l = 0, r = 0;

		scanf("%d", &l);
		scanf("%d", &r);
		int sum = 0;

		printf("%d\n", b[r-1] - b[l-1]);
	}

	return 0;
}