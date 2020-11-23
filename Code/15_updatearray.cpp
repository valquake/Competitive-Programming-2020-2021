#include "./../Utility/FenwickTree.cpp"

/*
	Author: Valeria Montagna
	
	Solution description:
	Solution consists on storing in a Fenwick Tree all range updates in the following way: update all nodes whose associated range contains l with v (with BIT's add),
	and all nodes whose associated range contains r+1 (when r != nEl) with -v. Once it is queried value of element at position i, it is sufficient calling BIT's sum.
	
	Complexity: Time complexity is O((nUp + q)log(nEl)), for each test case. 
*/

int main(int argc, char const *argv[])
{
	int test_cases = 0;
	std::cin >> test_cases;

	for (int i = 0; i < test_cases; ++i)
	{
		
		int nEl = 0, nUp = 0;
		std::cin >> nEl;
		std::cin >> nUp;
		BIT ft(nEl);

		for(int j = 0; j < nUp; ++j){
			int l = 0, r = 0, val = 0;
			std::cin >> l;
			std::cin >> r;
			std::cin >> val;

			ft.add(l + 1, val);
			if(r != nEl - 1)
				ft.add(r + 2, val*(-1));
		}

		int q = 0;
		std::cin >> q;

		for(int j = 0; j < q; ++j){
			int idx = 0;
			std::cin >> idx;

			std::cout << ft.sum(idx+1) << std::endl;
		}

	}

	return 0;
}
