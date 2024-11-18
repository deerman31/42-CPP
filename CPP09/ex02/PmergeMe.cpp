#include "PmergeMe.hpp"

// コンストラクタ 引数から配列を初期化
PmergeMe::PmergeMe(const int argc, const char **argv) : _size((size_t)(argc - 1)), _vec_time(0), _lst_time(0) {
	for (int i = 1; i < argc; i += 1) {
		// この段階ですでに引数のチェックは終わっているので素直にatoiで変換し、配列に代入する
		_array[i - 1] = std::atoi(argv[i]);
	}
}

PmergeMe::~PmergeMe() {}

// バイナリー挿入ソートを行う関数
template<typename T>
static void	binary_insert(T &sorted_container, const T &insert_container) {
	for (typename T::const_iterator value = insert_container.begin();
	value != insert_container.end(); ++value) {
		typename T::iterator position = std::lower_bound(sorted_container.begin(), sorted_container.end(), *value);
		sorted_container.insert(position, *value);
	}

}

// コンテナを small と big にグループ分けする関数
// この時点では大小では分けない。あとのpair_sortで大小に分ける
// 奇数の場合はsmallのほうの個数が一つだけ数が大きくなる
template<typename T>
static void	divide_groups(const T &c, T &small, T &big) {
	typename T::const_iterator it = c.begin();
	while (it != c.end()) {
		small.push_back(*it);
		++it;
		if (it != c.end()) {
			big.push_back(*it);
			++it;
		}
	}
}

// small と big のペアをソートする関数
template<typename T>
static void	pair_sort(T &small, T &big) {
	typename T::iterator s = small.begin();
	typename T::iterator b = big.begin();

	while (s != small.end()) {
		if (b == big.end()) {
			break;
		}
		if (*s > *b) {
			std::swap(*s, *b);
		}
		++s;
		++b;
	}
}

// restore_sort関数は、二つのint型のコンテナを受け取り、それらを組み合わせてソートします。
template<typename T>
static void restore_sort(T &small, T &big) {
	std::pair<int, int> combined[1500];
    typename T::iterator itSmall = small.begin();
    typename T::iterator itBig = big.begin();
	size_t size = 0;
    for (; itSmall != small.end() && itBig != big.end(); ++itSmall, ++itBig) {
		combined[size] = std::make_pair(*itSmall, *itBig);
		size += 1;
    }

    std::sort(combined, combined + size, CompareSecond());

    itSmall = small.begin();
    itBig = big.begin();
	for (size_t i = 0; i < size; i += 1, ++itSmall, ++itBig) {
		*itSmall = combined[i].first;
		*itBig = combined[i].second;
	}
}


// MergeInsertionソートのメイン処理
template<typename T>
static void	merge_insert(T &c) {
	if (c.size() <= 1) { return; }

	T	small;
	T	big;

	// 一個のリストから2個のリストに分割する
	divide_groups(c, small, big);
	// pairをソートする
	pair_sort(small, big);

	// bigをソートする。それと同時にペアリングしたsmallも同じように動かす
	restore_sort(small, big);

	// 再帰的にソートする
	merge_insert(big);

	// typename T::const_iterator b = big.begin();
	// for (typename T::const_iterator s = small.begin(); s != small.end(); ++s) {
	// 	if (b != big.end()) {
	// 		std::cout << "s: [" << *s << "] b: [" << *b << "]" << std::endl;
	// 		++b;
	// 	} else {
	// 		std::cout << "s: [" << *s << "]" << std::endl;
	// 	}
	// }
	// std::cout << "---------------------\n";

	// バイナリーインサートソートを行う
	binary_insert(big, small);

	// bigにソートされたリストが入っているのでswapし、cにbigの値を入れる
	c.swap(big);
}

// コンテナがソートされているかを確認する関数
template<typename T>
static bool	is_sorted(const T &c) {
	typename T::const_iterator it = c.begin();
	while (it != c.end()) {
		typename T::const_iterator tmp = it;
		++it;
		if (it != c.end()) {
			if (*tmp > *it) {
				return false;
			}
		}
	}
	return true;
}

template<typename T>
static void	print_container(const T &c) {
	for (typename T::const_iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout <<  "\n---------------\n\n";
}


// コンテナの内容を表示する関数
template<typename T>
void	PmergeMe::sort(T &c, double &time) {


	clock_t	start = clock();
	for (size_t i = 0; i < _size; i += 1) {
		c.push_back(_array[i]);
	}

	merge_insert(c);

	time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;
}

void	PmergeMe::ford_johnson_algorithm() {
	sort(_vec, _vec_time);
	if (is_sorted(_vec) == false) {
		std::cout << "FAIL: vector" << std::endl;
		std::exit(1);
	}

/*
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n------------------\n";
*/

	sort(_lst, _lst_time);
	if (is_sorted(_lst) == false) {
		std::cout << "FAIL: list" << std::endl;
		std::exit(1);
	}

/*
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n------------------\n";
*/
}

// ソートの結果について、出力する関数
void	PmergeMe::display_result() const {
	std::cout << "Before: ";
	for (size_t i = 0; i < _size; i += 1) {
		if (i == 4 && 5 != _size) {
			std::cout << "[...]";
			break;
		} else {
			std::cout << _array[i] << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "After:  ";
	for (size_t i = 0; i < _size; i += 1) {
		if (i == 4 && 5 != _size) {
			std::cout << "[...]";
			break;
		} else {
			std::cout << _vec[i] << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::vector : " << _vec_time << " us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::list :   " << _lst_time << " us" << std::endl;
}