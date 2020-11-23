/*
	Author: Valeria Montagna
	

	Solution Description:
	In this solution I used std::set, that offers us a series of advantages: implicitly maintains the order dictated by data type,
	it does not admit duplicates and iterators are not affected by changes caused by insertions and deletions. This last consideration
	is fundamental for my solution, because it is based on the use of an iterator that everytime points to the smaller element that
	needs to be doubled in order to obtain maximal damage.

	The insertion of a lighting spell is executed in the following way:
	- If it is greater than element pointed by iterator, it is implicitly admitted in the set, then we do not need to move iterator.
	- Otherwise, iterator is moved back by 1 position, because there's a new spell that doubles the next greater element that does
	  not belong yet to spells that have to be doubled.

	The insertion of a fire spell is executed in the following way:
	- If it is greater than element pointed by iterator, this element substitutes the smaller element between doubled spells, so
	  iterator has to be moved up to 1 position.
	- Otherwise, iterator does not need to be moved.

	The deletion of a lighting spell is executed in the following way:
	- If it is greater or equal to actual value pointed by iterator, iterator has to be changed only in the case that it points to
	  spell that has to be forgotten.
	- Otherwise, iterator is moved up by 1 position, because there must be another lighting spell that has to be put in place of it.
	  So we have to remove from doubled spells the smaller.

	The deletion of a fire spell is executed in the following way:
	- If it is greater or equal to actual value pointed by iterator, iterator has to be moved back by one position, taking the
	  greater element not in doubled spells.
	- Otherwise, iterator does not need to be moved.


	Complexity: 
	This solution requires space Θ(n). Every insertion and deletion operation in a std::set costs Θ(log(n)), so this
	solution requires Θ(log(n)) time.
*/

#include <iostream>
#include <set>
 
typedef long long ll;
 
int main(int argc, char const *argv[])
{
	std::set<ll> fire, lightning, doubling;
	fire.insert(0);
	auto it = doubling.end();

	ll sum = 0;
 
	int test_cases = 0;
	std::cin >> test_cases;
 
	for (int i = 0; i < test_cases; ++i)
	{
		int type = 0;
		std::cin >> type;
 
		int damage = 0;
		std::cin >> damage;	

		if(damage > 0){
			sum += damage;
			doubling.insert(damage);

			if(type == 0){
				fire.insert(damage);
				if(it != doubling.end() && damage > *it)
				{
					sum += damage;
					sum -= *it;
					it++;
				}
			}
			else
			{
				lightning.insert(damage);
				if(it != doubling.end() && damage > *it)
				{
					sum += damage;
				}
				else
				{
					it--;
					sum += *it;
				}
			}
		}
		else{
			damage = abs(damage);
			sum -= damage;

			if(type == 0)
			{
				fire.erase(damage);
				if(it != doubling.end() && damage >= *it)
				{
					sum -= damage;
					it--;
					sum += *it;
				}
			}
			else
			{
				lightning.erase(damage);
				if(it != doubling.end() && damage >= *it)
				{
					sum -= damage;
					if(*it == damage)
						it++;
				}
				else
				{
					sum -= *it;
					it++;
				}
			}
			doubling.erase(damage);
		}
		ll num = 0;
		
		// If there is at least a lighting's spell, and the smallest between lighting's spell
		// is greater than the largest fire's spell, surely the former does not belong to spells that
		// are doubled. 
		if(lightning.size() != 0 && *lightning.begin() > *fire.rbegin())
			num = *fire.rbegin() - *lightning.begin();

		/*if(it != doubling.end())
			std::cout << "Where is the iterator: " << *it << std::endl;
 		
 		std::cout << "FIRE SET: " ;
		for(auto it_f = fire.begin(); it_f != fire.end(); it_f++)
			std::cout << *it_f << " ";
		std::cout<<std::endl;
		std::cout << "LIGHT SET: " ;
		for(auto it_f = lightning.begin(); it_f != lightning.end(); it_f++)
			std::cout << *it_f << " ";
		std::cout<<std::endl;
		std::cout << "doubling SET: ";
		for(auto it_f = doubling.begin(); it_f != doubling.end(); it_f++)
			std::cout << *it_f << " ";
		std::cout<<std::endl;

		std::cout << "CORNER CASE = " << num << std::endl;*/
		std::cout << sum + num << std::endl;
	}
	
	return 0;
}