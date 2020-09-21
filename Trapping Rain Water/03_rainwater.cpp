#include <iostream>
#include <vector>

void compute_water(std::vector<int> const& v){

	// Computation of the array of maximums between predecessors
	std::vector<int> ml;
	ml.reserve(v.size());
	int max = v.front();
	ml.push_back(max);

	for (auto it = v.begin() + 1; it != v.end(); ++it)
		if(*it > max){
			max = *it;
			ml.push_back(max);
		} else ml.push_back(max);

	// Computation of the array of maximums between successors
	std::vector<int> ms;
	ms.reserve(v.size());
	max = v.back();
	ms.push_back(max);

	for(auto it = v.rbegin() + 1; it != v.rend(); ++it)
		if(*it > max){
			max = *it;
			ms.push_back(max);
		} else ms.push_back(max);

	// Sum of water's block
	int j = ms.size() - 1;
	int sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += std::min(ml[i], ms[j]) - v[i];
		j--;
	}

	std::cout << sum << std::endl;

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

		compute_water(v);
		v.clear();
	}
	
	return 0;
}