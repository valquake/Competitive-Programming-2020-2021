/*
	Author: Valeria Montagna

	Solution Description:
	For this solution it is sufficient to implement a data structure that reply to range minimum query 
	and able to update a range of data and not a single index. This can be notoriously done with a 
	segment tree.
	Moreover, seen that input array is circular, when ending point is less than starting point, an
	operation can be divided into two parts: one that goes from starting point to the end of array
	and one that goes from 0 to ending point.

	Complexity:
	Since every operation is solved with segment tree, complexity is O((n + q)logn) time and
	Θ(2 * 2 ^ (logn)) space for storing ST.
*/

#include <iostream>
#include <sstream>

#include "./../Utility/min_segment_tree.cpp"

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int64_t> input;
	input.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		int64_t x;
		std::cin >> x;

		input.push_back(x);
	}

	min_segment_tree<int64_t> st(input);

	int m;
	std::cin >> m;

	std::cin.ignore();

	for (int i = 0; i < m; ++i)
	{
		std::string tmp;
		std::getline(std::cin, tmp);
		std::stringstream ss(tmp);

		int l,r,v;

		ss >> l >> r;

		if(ss >> v){
			if(l <= r)
				st.update_range(l,r,v);
			else{
				st.update_range(l, n-1, v);
				st.update_range(0, r, v);
			}
		}
		else{
			if(l <= r)
				std::cout << st.query(l, r) << std::endl;
			else{
				std::cout << std::min(st.query(l, n-1),
								st.query(0, r)) 
						  << std::endl;
			}
		}

	}

	return 0;
}
