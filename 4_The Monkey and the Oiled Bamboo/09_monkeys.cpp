/*
	Author: Valeria Montagna

	Solution Description:
	Since we don't know an upper bound for the strength factor, we could use Exponential Binary Search to find it,
	and then simple Binary Search to find minimum solution.	


	Time Complexity:

*/

#include <iostream>
#include <vector>
#include <stack>

using ull = long long int;

bool is_enought(std::vector<ull> const& v, ull k){
	if(v[0] > k)
		return false;
	else if(v[0] == k)
		k--;

	for (int i = 1; i < v.size(); ++i) {
		int gap = v[i] - v[i-1];

		if(gap == k) k--;
		else if(gap > k) return false;
	}

	return true;
}

ull find_minimum_k_BS(std::vector<ull> const& v, ull low, ull high){

	ull top = high;

	while(low <= high) {

		ull middle = (low + high)/2;

		// std::cout << low << " " << middle << " " << high << std::endl;

		if(is_enought(v, middle)){
			top = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}

	return top;
}

ull find_minimum_k(std::vector<ull> const& v){
	if(v.size() == 1)
		return v[0];

	ull k = v[0];

	while(!is_enought(v, k))
		k *= 2;

	return find_minimum_k_BS(v, k/2, k);
}

int main(int argc, char const *argv[])
{
	int test_cases = 0;
	std::cin >> test_cases;
	std::vector<ull> r;
	r.reserve(test_cases);

	std::vector<ull> v;
	for (int i = 0; i < test_cases; ++i)
	{
		int dim = 0;
		std::cin >> dim;

		v.reserve(dim);
		for (int j = 0; j < dim; ++j)
		{
			ull x = 0;
			std::cin >> x;
			v.push_back(x);
		}

		int k = find_minimum_k(v);
		r.push_back(k);
		
		v.clear();
	}

	for (int k = 0; k < test_cases; ++k)
		std::cout << "Case " << k + 1 << ": " << r[k] << std::endl;

	return 0;
}