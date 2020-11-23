/*
	Author: Valeria Montagna
	
	Solution Description
	In this solution, iterate over the vector from begin + 1 to end.
	Keep a variable sum, at each step add the current element if sum is currently positive.
	If not, restart the sum from current element.
	
	At each iteration, the solution is maximum value between sum and current max.
	
	Time complexity for each test case is O(n), where n is the size of vector.
*/

#include <iostream>
#include <vector>

void kadame_algo(std::vector<int> const& v){
	int sum = v.front(), max = v.front();

	for (auto it = v.begin() + 1; it != v.end(); ++it)
	{
		if(sum > 0) sum += *it;
		else sum = *it;

		if(sum > max) max = sum;
	} 

	std::cout << max << std::endl;
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

		v.reserve(dim);
		for (int j = 0; j < dim; ++j)
		{
			int x = 0;
			std::cin >> x;
			v.push_back(x);
		}

		kadame_algo(v);
		v.clear();
	}
	
	return 0;
}
