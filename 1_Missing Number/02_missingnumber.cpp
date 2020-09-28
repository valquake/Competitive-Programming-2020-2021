#include <iostream>
#include <vector>

/*
	Author: Valeria Montagna
	
	Solution Description:
	Knowing how to compute the sum of the first n natural numbers, compute it.
	Iterate over the vector and compute the real sum.
	
	The solution is the difference between the presumptive sum and the real sum.
	
	Time complexity: O(n) for each test case, where n is dimension of the vector.
*/

void search_missing(int n, std::vector<int> const& v){

	// I know how to compute the sum of the first n natural numbers
	int presumptive_sum = (n*(n+1))/2;
	int real_sum = 0;

	for (auto it = v.begin(); it != v.end(); ++it)
		real_sum += *it;

	// Missing number is obtained by difference
	int missing = (presumptive_sum - real_sum);
	std::cout << missing << std::endl; 
}

int main(int argc, char const *argv[])
{
	int test_cases = 0;
	std::cin >> test_cases;

	std::vector<int> v;
	for (int i = 0; i < test_cases; ++i)
	{
		int dim = 0;
		std::cin >> dim;

		v.reserve(dim - 1);
		for (int j = 0; j < dim - 1; ++j)
		{
			int x = 0;
			std::cin >> x;
			v.push_back(x);
		}

		search_missing(dim, v);
		v.clear();
	}
	
	return 0;
}
