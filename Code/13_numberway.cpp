/*
	Author: Valeria Montagna
	
	Solution Description:
	If total sum "sum" cannot be divided by 3, there's no solution. So, I check that and in case I return 0.
	Otherwise, I compute the prefix sums of the input vector and I create an auxiliary vector aux where I place 1 each time the current value is
	sum/3. Then, I find position j of elements equal to sum/3 and I add value in position j+2 of vector aux to the result. This is done because
	I have to find all possible ways to split remaining 2/3 of the vector in order to obtain sum/3 in both parts.

	Complexity: Time complexity is O(m)

*/


#include<iostream>
#include<vector>


int main(int argc, char const *argv[])
{
	std::vector<int64_t> v;

	int m = 0;
	std::cin >> m;
	v.reserve(m);

	int64_t sum = 0;

	for (int i = 0; i < m; ++i)
	{
		int64_t x = 0;

		std::cin >> x;
		v.push_back(x);

		sum += x;
	}

	if(sum % 3 != 0){
		std::cout << 0 << std::endl;
		return 0;
	}

	std::vector<int64_t> c(m);
	int64_t partial_sum = sum / 3;
	int64_t res = 0;

	// Find all the ways to split first part of the array
	for(int i = m-1; i >= 0; --i){
		res += v[i];

		if(res == partial_sum){
			if(i != m-1)
				c[i] = c[i+1] + 1; // This is another way to split first part of the array, a part from the ways found previously
			else
				c[i] = 1; // Corner case, when a first way to split it is at first element of the array
		}
		else{
			if(i != m-1)
				c[i] = c[i+1]; // Suffix sum is equal to the previous result
			else
				c[i] = 0;
		}
	}

	// Find all the ways to split other two parts of the array
	res = 0;
	int64_t allways = 0;
	for(int i = 0; i < m-2; ++i){
		res += v[i];

		if(res == partial_sum)
			allways += c[i+2];
	}

	std::cout << allways;
	return 0;
}