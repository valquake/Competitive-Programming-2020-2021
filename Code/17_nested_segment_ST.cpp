/*
	Author: Valeria Montagna

	Solution Description:
	This is the same approach descripted in nested segment problem, but in this case I use a segment tree,
	instead of a fenwick tree.


	Complexity:
	I use Θ(2 * 2 ^ (logn)) space for storing ST.
	Time complexity for this solution is Θ(nlog(n))
*/

#include <tuple>
#include <algorithm>

#include "./../Utility/sum_segment_tree.cpp"

struct point
{
	int idx; // index of input's vector
	int t; // denote if it is a starting point (0) or an end point (1)
	int64_t p; // point in the space [0, 2n)

	bool operator <(const point &other){
		return std::tie(t,p) < std::tie(other.t, other.p);
	}
};

int main(int argc, char const *argv[])
{
	int n = 0;
	std::cin >> n;

	std::vector<segment> input;
	std::vector<point> mapping;
	
	std::vector<int64_t> res(n);
	input.reserve(n);
	mapping.reserve(2*n);
	sum_segment_tree<int64_t> st(2*n);

	for (int i = 0; i < n; ++i)
	{
		int64_t l = 0, r = 0;

		std::cin >> l >> r;

		mapping.push_back({i, 0, l}); // Store starting points with index of input vector
		mapping.push_back({i, 1, r});
		input.push_back({l, r});
	}

	std::sort(mapping.begin(), mapping.end()); // Order starting points by increasing order

	// Remapping operation
	for(int j = 0; j < mapping.size(); ++j){
		if(mapping[j].t == 0)
			input[mapping[j].idx].left = j;
		else{
			input[mapping[j].idx].right = j;
			st.update(j,1);
		}

		mapping[j].p = j;
	}



	for(int i = 0; i < n; ++i){
		int idx = mapping[i].idx;
		int r_idx = input[idx].right; // Find endpoint associated to this segment

		st.update(r_idx, -1); // Assign zero to that right endpoint
		res[idx] = st.query(0, r_idx); // Recover sum until this right endpoint (exclude itself)
	}

	for(auto it = res.begin(); it != res.end(); ++it)
		std::cout << *it << std::endl;


	return 0;
}