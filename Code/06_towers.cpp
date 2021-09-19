#include <queue>
#include <vector>
#include <iostream>

/**
 * Author : Valeria Montagna
 * 
 * Description :
 * For this solution, I store vector's elements in a max heap, to give them a decreasing order.
 * In turn, I pop every element and I keep track of the number of unique elements and the most frequent
 * element in the heap. At the end, I print the results.
 *  
 * Time complexity :
 * for every item in the vector, there's a push and a pop. Their cost is logaritmic. In total Θ(nlog(n))
 **/

void compute_towers(std::vector<int> const& v, int const dim){
	std::priority_queue<int> pq;

	for (int i = 0; i < dim; ++i)
		pq.push(v[i]);
	
	int max_h = 1;
	int current_h = 0;
	int towers = 0;
	int el = 1001;
	int current = 0;

	while(!pq.empty()){
		current = pq.top();
		pq.pop();

		if(el != current){
			towers++;
			current_h = 1;
			el = current;
		} else{
			current_h++;
			max_h = current_h > max_h ? current_h : max_h;
		}
	}

	std::cout << max_h << " " << towers << std::endl;
}

int main(int argc, char const *argv[])
{
	int bars = 0;
	std::cin >> bars;

	std::vector<int> woods;
	woods.reserve(bars);

	for (int i = 0; i < bars; ++i)
	{
		int x = 0;
		std::cin >> x;

		woods.push_back(x);
	}

	compute_towers(woods, bars);
	woods.clear();

	return 0;
}