/*
	Author: Valeria Montagna

	Solution Description:
	First of all, sort the integer vector v and create lengths' vector l. Then, for each step, check if the current element of v is equal to his predecessor.
	If not, add a new element to the vector l, initialized to 1. If it is, increment the current element of l. 

	Time Complexity:
	O(nlog(n)) (for sorting) + Θ(n), where n is vector's dimension.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
	

int main(int argc, char const *argv[])
{

	std::vector<int> v;

	int dim = 0;
	std::cin >> dim;

	v.reserve(dim);
	for (int j = 0; j < dim; ++j)
	{
		int x = 0;
		std::cin >> x;
		v.push_back(x);
	}

	std::sort(v.begin(), v.end());
	std::vector<int> l;

	l.reserve(v.size()); // At most, I have all towers formed by 1 piece

	int maxL = 1, k = 0, curr = v.front();
	l.push_back(1);

	for (int i = 1; i < v.size(); ++i){

		if(curr == v[i]) {
			l[k]++;

			if(l[k] > maxL)
				maxL = l[k];
		}else{
			l.push_back(1);
			curr = v[i];
			k++;
		}
	}

	std::cout << maxL << " " << l.size();

	
	
	return 0;
}