/*
	Author: Valeria Montagna

	Solution Description:
	First of all, I map values in input vector with their occurrences. Then, I scan vector from right to left
	and I store in a new vector number of occurrences of value at position i in positions that goes from i+1 to n.
	I build a BIT on this occurrences: sum(k) will output how many times f(i,n,input[i]) < k. 
	This operation is repeated scanning the vector from left to right. In order to require number of indices j s.t.
	j > i and f(j,n,input[j]) < k, I must query sum(k - 1). Each time, I have to subtract contribution of already 
	processed element.

	Complexity:
	Time complexity is O(nlogn), since I use a BIT. 
*/

#include <iostream>
#include <vector>
#include <map>

#include "./../Utility/FenwickTree.cpp"

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(0);
	int n;
	std::cin >> n;
	std::vector<int64_t> input;
	std::vector<int64_t> suffix_counter(n, 0); // stores #occurrences of input[i] in input[i+1,n]
	BIT ft(n); // stores values of suffix_counter s.t. ft[i] = #occs in suffix_counter equal to i
	std::map<int, int> remapping; // this is useful to mapping values with their occurrences in array
	input.reserve(n);


	for (int i = 0; i < n; ++i)
	{
		int64_t x;
		std::cin >> x;

		input.push_back(x);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		remapping[input[i]]++;
		suffix_counter[i] = remapping[input[i]];
		ft.add(suffix_counter[i], 1);
	}

	remapping.clear();
	int64_t res = 0;

	for(int i = 0; i < n; i++){
		remapping[input[i]]++;
		ft.add(suffix_counter[i], -1); // remove contribute of entries in suffix_counter[1,i]
		res += ft.sum(remapping[input[i]] - 1); // we need to count #j s.t. j>i and f(j,n,input[j]) < k
	}

	std::cout << res << std::endl;

	return 0;
}
