#include <vector>
#include <iostream>
#include <cmath>
#include <functional>
#include <limits>

/*
	This is a segment tree created to reply to MIN QUERIES.
	Segment tree can be updated with a simple increment to an element or with a range update by an arbitrary value. 
*/

#define DEBUG(X) std::cout << #X << " = " << X << std::endl;

#define LEFT(i) 	(2 * (i) + 1)
#define RIGHT(i)	(2 * (i) + 2)

struct segment
{
	int64_t left, right;

	segment(int64_t a, int64_t b):left(a), right(b) {}
};

template<typename T>
class min_segment_tree
{
	std::vector<T> v;
	std::vector<T> lazy_v;
	int64_t size;
	std::function<T(T)> f;

	void build(segment smt, const int64_t idx){
		if (smt.left > smt.right)
			return;

		if (smt.left == smt.right){
			v[idx] = f(smt.left);
			return;
		}

		int64_t mid = (smt.left + smt.right) / 2;
		build({smt.left, mid}, LEFT(idx));
		build({mid + 1, smt.right}, RIGHT(idx));

		v[idx] = std::min(v[LEFT(idx)], v[RIGHT(idx)]);
	}

	void update_r(const segment smt, T val, segment tgt, const int64_t idx)
	{
		if (lazy_v[idx] != 0)
		{
			v[idx] += lazy_v[idx];


			if(tgt.left != tgt.right)
			{
				lazy_v[LEFT(idx)] += lazy_v[idx];
				lazy_v[RIGHT(idx)] += lazy_v[idx];
			}

			lazy_v[idx] = 0;
		}
		
		// o.f.r.
		if( tgt.left > smt.right || tgt.right < smt.left || smt.left > smt.right)
			return;

		// Complete overlap
		if( tgt.left >= smt.left && tgt.right <= smt.right )
		{
			v[idx] += val;

			if(tgt.left != tgt.right)
			{
				lazy_v[LEFT(idx)] += val;
				lazy_v[RIGHT(idx)] += val;
			}

			return;
		}

		int64_t mid = (tgt.left + tgt.right) / 2;
		update_r(smt, val, {tgt.left, mid}, LEFT(idx));
		update_r(smt, val, {mid+1, tgt.right}, RIGHT(idx));

		v[idx] = std::min(v[LEFT(idx)], v[RIGHT(idx)]);
	}

	void update(size_t const t, segment const smt, int64_t const idx){
		if (lazy_v[idx] != 0)
		{
			v[idx] += lazy_v[idx];


			if(smt.left != smt.right)
			{
				lazy_v[LEFT(idx)] += lazy_v[idx];
				lazy_v[RIGHT(idx)] += lazy_v[idx];
			}

			lazy_v[idx] = 0;
		}

		if(t < smt.left || t > smt.right)
			return;

		if(smt.left == smt.right) {
			v[idx] = v[idx] + 1;
			return;
		}
		
		int64_t mid = (smt.left + smt.right) / 2;
		update(t, {smt.left, mid}, LEFT(idx));
		update(t, {mid+1, smt.right}, RIGHT(idx));

		v[idx] = std::min(v[LEFT(idx)], v[RIGHT(idx)]);
	}

	T query(segment const& smt, segment tgt, int64_t idx)
	{
		if (lazy_v[idx] != 0)
		{
			v[idx] += lazy_v[idx];


			if(tgt.left != tgt.right)
			{
				lazy_v[LEFT(idx)] += lazy_v[idx];
				lazy_v[RIGHT(idx)] += lazy_v[idx];
			}

			lazy_v[idx] = 0;
		}

		// o.f.r.
		if( tgt.left > smt.right || tgt.right < smt.left || tgt.left > tgt.right){
			return std::numeric_limits<int64_t>::max();
		}


		// Complete overlap
		if( tgt.left >= smt.left && tgt.right <= smt.right )
		{
			return v[idx];
		}

		int64_t mid = (tgt.left + tgt.right) / 2;

		if(smt.left > tgt.right || smt.right < tgt.left)
			return query(smt, {tgt.left, mid}, LEFT(idx));
		else if(smt.left > mid || smt.right < tgt.left)
			return query(smt, {mid + 1, tgt.right}, RIGHT(idx));

		return std::min(query(smt, {tgt.left, mid}, LEFT(idx)), query(smt, {mid+1, tgt.right}, RIGHT(idx)));
	}

	void _print_segment_tree(int64_t pos, int64_t left, int64_t right, int64_t layer){
	    for (int i = 0; i < layer; ++i){
	        printf("---");
	    }
	    //printf("[" PRId64 " " PRId64 "][" PRId64 "] : " PRId64 "\n", left, right, pos, v[pos]);
	    printf("[%ld %ld][%ld] : %ld\n", left, right, pos, v[pos]);
	    if (left == right){
	        return;
	    }
	    int mid = (left + right) / 2;
	    _print_segment_tree(LEFT(pos), left, mid, layer + 1);
	    _print_segment_tree(RIGHT(pos), mid + 1, right, layer +1);
	}

	void _print_lazy_segment_tree(int64_t pos, int64_t left, int64_t right, int64_t layer){
	    for (int i = 0; i < layer; ++i){
	        printf("---");
	    }

	    printf("[%ld %ld][%ld] : %ld\n", left, right, pos, lazy_v[pos]);
	    if (left == right){
	        return;
	    }
	    int mid = (left + right) / 2;
	    _print_lazy_segment_tree(LEFT(pos), left, mid, layer + 1);
	    _print_lazy_segment_tree(RIGHT(pos), mid + 1, right, layer +1);
	}

	public:	
		min_segment_tree(std::vector<T> const& arr) {
			size_t m = 1 << static_cast<size_t>(ceil(log2(arr.size())));
			v.resize(m - 1 + m, 0);
			lazy_v.resize(m - 1 + m, 0);
			size = arr.size();
			f = [&](size_t i){return arr[i];};
			build({0, size - 1}, 0);
		}

		void update_range(const int64_t l, const int64_t r, T val){
			update_r({l, r}, val, {0, size - 1}, 0);
		}

		T query(const int64_t l, const int64_t r){
			return query({l, r}, {0, size - 1}, 0);
		}

		void update(const size_t i){
			update(i, {0, size - 1}, 0);
		}
	void print_trees(){
	    
	    _print_segment_tree(0, 0, size - 1, 0);
	    _print_lazy_segment_tree(0, 0, size - 1, 0);
	}
};

int main(int argc, char const *argv[])
{
	min_segment_tree<int64_t> sg_t({1,4,7,0});

	std::cout << "BUILDED MINIMUM QUERY VECTOR" << std::endl;
	sg_t.update_range(0, 3, 1);		// update from 0 to 3 with 1
	sg_t.update_range(0, 1, 1); 	// update from 0 to 1 with 1
	// Now array is 3 6 8 1
    DEBUG(sg_t.query(0, 0));
    DEBUG(sg_t.query(1, 1));
    DEBUG(sg_t.query(2, 3));
    DEBUG(sg_t.query(0, 1));
    DEBUG(sg_t.query(2, 2));
	sg_t.print_trees();

	return 0;
}