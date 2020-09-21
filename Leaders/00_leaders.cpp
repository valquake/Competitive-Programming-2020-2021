#include <iostream>
#include <vector>

void print_leaders(std::vector<int> const& v){

	std::vector<int> leaders;
	leaders.reserve(v.size());

	// Insert last element, regardless his value!
	int max = v.back();
	leaders.push_back(max);

	// Check the condition for all the element at reverse, and save current max
	for (auto it = v.rbegin() + 1; it != v.rend(); ++it ) {
		// If this condition is checked, then we have a new leader!
		if(*it >= max) {
			max = *it;
			leaders.push_back(max);
		}
	}

	// Print all the leader in the right order!
	for (auto it = leaders.rbegin(); it != leaders.rend(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;

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

		print_leaders(v);
		v.clear();
	}
	
	return 0;
}