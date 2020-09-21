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