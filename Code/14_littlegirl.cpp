/*
	Author: Valeria Montagna

	Solution Description:
	For each query, we compute prefix sums of the frequency vector. Then, we sort both input vector and frequency vector.
	Finally, we compute the sum of the frequency prefix sums times corresponding value in the input vector.

	Complexity:
	Time complexity is O((q+m)log(m)).
*/

#include<iostream>
#include<vector>
#include<algorithm>


int main(int argc, char const *argv[])
{
	std::vector<int64_t> v;

	int m = 0, q = 0;
	std::cin >> m;
	std::cin >> q;
	v.reserve(m);

	for (int i = 0; i < m; ++i)
	{
		int64_t x = 0;

		std::cin >> x;
		v.push_back(x);
	}


	std::vector<int64_t> queries(m);

	for(int i = 0; i < q; ++i){
		int l=0, r=0;

		std::cin >> l;
		std::cin >> r;

		queries[l-1]++;

		if(r != m)
			queries[r]--;
	}

	for(int i = 1; i < m; ++i)
		queries[i] += queries[i-1];

	std::sort(v.begin(), v.end());
	std::sort(queries.begin(), queries.end());
	int64_t sum = 0;

	for (int i = 0; i < m; ++i)
	{
		sum += v[i] * queries[i];
	}

	std::cout << sum << std::endl;

	return 0;
}