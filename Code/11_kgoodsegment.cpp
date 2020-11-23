/*
	Author: Valeria Montagna
	
	Solution Description:
	Solution consists on considering left and right position i and j (initially set to zero). With an hashmap, I keep track of frequencies of elements actually 
	between left index i and right index j.
	Everytime I move j by one position and I check if I already met current right element or not:
	- If it is, I don't need to check any other thing, except if my actual segment is longer than max segment length. In case, I have to update i and j.   
	- Otherwise, I check if I have less than k distinct elements or not.
		- If I have it, I simply update hashmap with my new element and in case longest path segment' indexes.
		- If not, I move on left index i, updating frequencies, until it is erased from hashmap frequency a sufficient number of elements that bring me back to 
		  have no more than k elements.
	When I reach the end of array with right index, I print left and right indexes that maximize length of k-good segment.

	Complexity: 
	As there will be no more than n deletions and insertions, time complexity is Θ(n). Space complexity is O(n).

*/


#include<iostream>
#include<vector>
#include<map>


int main(int argc, char const *argv[])
{
	int n = 0, k = 0;
	scanf("%d", &n);
	scanf("%d", &k);

	std::vector<long> elems;
	std::map<long, int> freq;
	elems.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		long x = 0;

		scanf("%lu", &x);

		elems.push_back(x);
	}

	int i = 0, max_i = 0;
	int j = 0, max_j = 0;

	while(j < n){
		long e = elems[j];
		auto it = freq.find(elems[j]);

		if(it != freq.end())
		{
			it->second += 1;
			j++;
		}
		else
		{
			if(freq.size() >= k){

				while(freq.size() >= k){
					auto it_sx = freq.find(elems[i]);
					it_sx->second -= 1;

					if(it_sx->second == 0)
						freq.erase(it_sx);

					i++;
				}

			}

			freq.insert({elems[j], 1});
			j++;
		}

		if(j - i > max_j - max_i){
			max_i = i;
			max_j = j;
		}
	}

	printf("%d %d", max_i+1, max_j);

	return 0;
}