/*
	Author: Valeria Montagna

	Solution Description:
	First of all, I map starting and ending points in range [0, 2*n]. I use a FT to storing all contribution of
	right endpoints of segments.
	- I initially update FT adding 1 to all indexes associated with ending points of all segments. In this way, I
	  include for a current segment all segments partially and fully contained in it.
	- Then, I apply sweeping line algorithm to scan in order starting points and to count segments included in 
	  actual segment. To exclude partially contained segments, before computing the sum on FT, I must update index
	  associated with current segment's endpoint it with -1, in order to erase his contribution. Doing so, I 
	  progressively delete all segment partially contained and count become correct.


	Complexity:
	I use Θ(n) space for storing input vector, data structure for mapping, result vector and FT.
	Time complexity for this solution is Θ(nlog(n))
*/

#include <tuple>
#include <algorithm>

#include "./../Utility/FenwickTree.cpp"

struct segment
{
	int64_t l;
	int64_t r;

	bool operator <(const segment &other){
		return l < other.l;
	}
};

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
	BIT ft(2*n);

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
			input[mapping[j].idx].l = j;
		else{
			input[mapping[j].idx].r = j;
			ft.add(j, 1);
		}

		mapping[j].p = j;
	}



	for(int i = 0; i < n; ++i){
		int idx = mapping[i].idx;
		int r_idx = input[idx].r; // Find endpoint associated to this segment

		ft.add(r_idx, -1); // Assign zero to that right endpoint
		res[idx] = ft.sum(r_idx); // Recover sum until this right endpoint (exclude itself)
	}

	for(auto it = res.begin(); it != res.end(); ++it)
		std::cout << *it << std::endl;


	return 0;
}
