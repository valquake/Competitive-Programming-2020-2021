/*
	Author: Valeria Montagna
	
	Solution Description:
	
	In this solution, I use a max heap, that stores vector's positions under which
	we can find the maximum for that window and actual values.
	At each step i, the window of size k slides by 1 position and we do the following things:
	- Add the new couple <e, pos>
	- Store the top
	- See if top's position is smaller than the first element of the sliding window. If it is, do the pop
	  and extract new top. Do this until top's position is inside the window
	- Print the top
	
	Time Complexity:
	The cost must be computed in terms of #pops and #push in the stack (the sum of them).
*/

#include <iostream>
#include <vector>
#include <queue>


void compute_max(int k, std::vector<int> const& v){
	std::priority_queue<std::pair<int, int>> pq;
	std::pair<int, int> couple;

	for (int i = 0; i < k; ++i)
	{
		pq.push(std::pair<int,int>(v[i], i));
	}
	couple = pq.top();
	std::cout << couple.first << " ";

	for (int i = k; i < v.size(); ++i)
	{
		pq.push(std::pair<int, int>(v[i],i));
		couple = pq.top();

		while(couple.second < i - k){
			pq.pop();
			couple = pq.top();
		}

		std::cout << couple.first << " ";
	}

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
