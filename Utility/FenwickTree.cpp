#include <vector>
#include <iostream>

#define LSB(i) ((i) & -(i)) // zeroes all the bits except the least significant one

struct BIT
{
	std::vector<int64_t> vec;

	BIT(size_t const n): vec(n+1) {};

	int sum(int idx){
		int64_t s = 0;

		while(idx != 0){
			s += vec[idx];
			idx -= LSB(idx);
		}

		return s;
	}

	void add(int idx, int v){
		while(idx <= vec.size()){
			vec[idx] += v;
			idx += LSB(idx);
		}
	}
};

/*int main(int argc, char const *argv[])
{
	std::vector<int> v = {3,2,-1,5,7,-3,2,1};
	BIT ft(v.size());

	for(int i = 0; i < v.size(); ++i){
		ft.add(i+1, v[i]);
	}

	std::cout << ft.sum(7) << std::endl; // Print 15

	return 0;
}*/