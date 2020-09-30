
/*
	Author: Valeria Montagna
	
	Solution Description:
	While we are applying merge sort to sort elements, count the pairs that are inversions.
	When I meet a pair of elements that obey to inversion criteria, I have to count as inversions 
	all the elements from smaller element to middle.
	
	Time Complexity:
	O(nlog(n)) (for doing merge sort)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

uint64_t merge_and_count(std::vector<uint64_t>& v, size_t low, size_t middle,  size_t high){
	size_t i = low, j = middle + 1, index = 0; 
	uint64_t invs = 0;

	std::vector<uint64_t> temp((high - low) + 1);

	while((i <= middle) and (j <= high)) {

		if(v[i] < v[j]){
			temp[index] = v[i];
			i++;
		} else {
			temp[index] = v[j];
			j++;
			invs += (middle-i) + 1;
		}

		index ++;
	}

	while(j <= high){
		temp[index] = v[j];
		j++;
		index++;
	}

	while(i <= middle){
		temp[index] = v[i];
		i++;
		index++;
	}
	

	std::copy(temp.begin(), temp.end(), v.begin() + low);

	return invs;
}

uint64_t merge_sort(std::vector<uint64_t>& v, size_t i, size_t e){
	if(i < e) {
		size_t middle = (i+e) / 2;
		uint64_t inv_sx = merge_sort(v, i, middle);
		uint64_t inv_dx = merge_sort(v, middle + 1, e);

		return inv_sx + inv_dx + merge_and_count(v, i, middle, e);
	}

	return 0;
}



int main(int argc, char const *argv[])
{
	int test_cases = 0;
	std::cin >> test_cases;

	std::string blank;
	std::getline(std::cin, blank);

	std::vector<uint64_t> v;
	for (int i = 0; i < test_cases; ++i)
	{
		int dim = 0;
		std::cin >> dim;

		v.reserve(dim);
		for (int j = 0; j < dim; ++j)
		{
			uint64_t x = 0;
			std::cin >> x;
			v.push_back(x);
		}

		std::getline(std::cin, blank);

		uint64_t invs = merge_sort(v, 0, dim - 1);

		std::cout << invs << std::endl;

		v.clear();
	}
	
	return 0;
}

