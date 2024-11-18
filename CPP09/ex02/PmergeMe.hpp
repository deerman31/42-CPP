#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <algorithm>


// std::pairの第二要素で比較するためのファンクタ
struct CompareSecond {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second < b.second;
    }
};


class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::list<int>		_lst;
		int					_array[3000];
		size_t				_size;
		double				_vec_time;
		double				_lst_time;

		template<typename T>
		void	sort(T &, double &);
	public:
		PmergeMe(const int, const char **);
		~PmergeMe();
		void	ford_johnson_algorithm();
		void	display_result() const;
};

#endif
