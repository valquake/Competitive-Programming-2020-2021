/*
	Author: Valeria Montagna

	Solution Description:
	First of all, sort the array of tuples by team mates' affinity with std library's sorting algorithm. Then, choose by brute force team mates
	until all members of tournament are coupled.

	Time Complexity:
	O(nlog(n)) (for sorting) + O(n) = O(nlog(n))

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
	
int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;

    return res;
}


int main(int argc, char const *argv[])
{

	int n = 0;
	std::cin >> n;

	std::vector<std::tuple<int, int, int64_t>> v;

	v.reserve(C(2*n, 2));
	for (int i = 2; i <= 2*n; ++i)
	{
		for (int j = 1; j <= (i-1); ++j)
		{
			int64_t value = 0;
			std::tuple<int, int, int64_t> x (i, j, 0);
			std::cin >> value;
			std::get<2>(x) = value; 
			v.push_back(x);
		}
	}

	std::sort(v.begin(), v.end(),
	[](std::tuple<int, int, int64_t> const& el1, std::tuple<int, int, int64_t> const& el2){
		return (std::get<2>(el1) > std::get<2>(el2)); 
	});

    std::vector<int> teammates(2*n);
    int not_paired = 2*n;
	
    for (int i = 0; i < v.size(); ++i)
    {
    	int first = std::get<0>(v[i]);
    	int second = std::get<1>(v[i]);
    	if(teammates[first - 1] == 0 and teammates[second - 1] == 0){
    		teammates[first - 1] = second;
    		teammates[second - 1] = first;
    		not_paired -= 2;

    		if(not_paired == 0)
    			break;
    	}
    }

    for(auto it = teammates.begin(); it != teammates.end(); it++)
    	std::cout << *it << " ";

    std::cout << std::endl;
	
	return 0;
}