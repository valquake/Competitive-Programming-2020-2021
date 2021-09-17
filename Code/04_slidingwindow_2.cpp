/*
	Author: Valeria Montagna
	
	Solution Description:
	
	In this solution, I use a BST, that stores vector's values inside sliding window.
	At each step i, the window of size k slides by 1 position and BST changes in the
	following way:
	- element i*k - 1 is deleted from BST
	- element i*k + k is added to BST
	- print max from current BST
	
	Time Complexity:
	At each step, we perform deletion, insertion and maximum operations, which cost Θ(logk). 
	Total time complexity is Θ(n*logk)
*/

#include <iostream>
#include <vector>
#include "../Utility/BST.cpp"


void compute_max(int k, std::vector<int> const& v){
	BST<int> bst;

	for (int i = 0; i < k; ++i)
	{
		bst.insert(v[i]);
	}

	bst.display_max();
	cout << " ";

	for (int i = k; i < v.size(); ++i)
	{
		bst.remove(v[i - k]);
		bst.insert(v[i]);
		bst.display_max();
		cout << " ";
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
