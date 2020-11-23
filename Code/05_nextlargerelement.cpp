/*
	Author: Valeria Montagna

	Solution Description:
	In this solution, I used a LIFO data structure (a stack), in the following way:
	- I pushed last element of vector.
	- Reverse-iterating over the vector (starting from second-last element), I always pop the last element of the stack,
	  until I get that current element of vector is less than the popped element. In that case, the popped element is
	  the next greater element for it. If I clear the stack, there's no next greater element for it, so I put -1.
	- At the end, I print at reverse the vector containing next larger elements, because this vector is filled by the end. 

	Time Complexity:
	The cost must be computed in terms of #pops and #push in the stack (the sum of them). Because there are exactly n pushs
	and at most n pops, the cost of the algorithm per iteration is Θ(n).

*/

#include <iostream>
#include <vector>
#include <stack>

using ull = long long int;

void find_next_larger_element(std::vector<ull> const& v){
	std::vector<ull> nextlargerel;
	nextlargerel.reserve(v.size());
	std::stack<ull> T;
	T.push(v.back());
	nextlargerel.push_back(-1);

	for(auto it = v.rbegin() + 1; it != v.rend(); ++it){
		ull next = *it;
		ull el = -1;

		while(!T.empty() && (el = T.top()) < next){
			T.pop();
		}

		if(el < next)
			nextlargerel.push_back(-1);
		else
			nextlargerel.push_back(el);

		T.push(next);
	}

	for (auto it = nextlargerel.rbegin(); it != nextlargerel.rend(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;

}

int main(int argc, char const *argv[])
{
	int test_cases = 0;
	std::cin >> test_cases;

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

		find_next_larger_element(v);
		v.clear();
	}
	
	return 0;
}