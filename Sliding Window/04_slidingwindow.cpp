#include <iostream>
#include <vector>
#include <deque>

void compute_max(int k, std::vector<int> const& v){
	std::deque<int> Q; // This queue stores positions
	std::vector<int> maxs;
	maxs.reserve(v.size() - k + 1); // We have in total n - k windows

	for (int i = 0; i < v.size(); ++i)
	{
		while(!Q.empty() && Q.front() <= (i - k))
			Q.pop_front();

		while(!Q.empty() && v[Q.back()] <= v[i])
			Q.pop_back();

		Q.push_back(i);

		maxs.push_back(v[Q.front()]);
	}

	for(auto it = maxs.begin() + k - 1; it != maxs.end(); ++it)
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

		int k = 0;
		std::cin >> k;

		v.reserve(dim);
		for (int j = 0; j < dim; ++j)
		{
			int x = 0;
			std::cin >> x;
			v.push_back(x);
		}

		compute_max(k, v);
		v.clear();
	}
	
	return 0;
}