#include "PmergeMe.hpp"

//Positive integer
// 入力が正の整数であるかどうかをチェックする関数
static bool	is_positive_num(int argc, const char **argv) {
	for (int i = 1; i < argc; i += 1) {
		for (int j = 0; argv[i][j]; j += 1) {
			if (std::isdigit(argv[i][j]) == 0) {
				return false;
			}
		}
	}
	return true;
}

// 値の重複をチェックする関数
static bool	duplicate_check(int argc, const char **argv) {
	int	cnt;

	for (int i = 1; i < argc; i += 1) {
		cnt = 0;
		for (int j = 1; j < argc; j += 1) {
			if (std::strcmp(argv[i], argv[j]) == 0) {
				cnt += 1;
			}
			// cntが2になった時点で重複があるということなので、false
			if (cnt == 2) {
				return false;
			}
		}
	}
	return true;
}

// INT_MAX以上の値が引数にあれば、falseを返す関数
static bool	is_overflow(int argc, const char **argv) {
	for (int i = 1; i < argc; i += 1) {
		// 長さが10を超えている時点でオーバーフローなのでfalse
		if (std::strlen(argv[i]) > 10) {
			return false;
		}
		if (INT_MAX < std::atol(argv[i])) {
			return false;
		}
	}
	return true;
}

// エラーチェックをまとめて行う関数
static bool	error_check(int argc, const char **argv) {
	if (argc < 3 || argc > 3001) {
		std::cerr << "ERROR: The number of integer columns is between 3 and 3000." << std::endl;
		return false;
	}
	if (is_positive_num(argc, argv) == false) {
		std::cerr << "ERROR: Anything other than a positive integer is NG." << std::endl;
		return false;
	}
	if (is_overflow(argc, argv) == false) {
		std::cerr << "ERROR: Values are from 0 to INT_MAX." << std::endl;
		return false;
	}
	if (duplicate_check(argc, argv) == false) {
		std::cerr << "ERROR: There are duplicate values." << std::endl;
		return false;
	}
	return true;
}

int	main(const int argc, const char **argv) {
	if (error_check(argc, argv) == false) {
		return 1;
	}
	PmergeMe	p(argc, argv);

	// MergeInsertionソートアルゴリズムを実行
	p.ford_johnson_algorithm();

	// ソート結果を表示
	p.display_result();

	// std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vec_time << " us" << std::endl;
	// std::cout << "Time to process a range of " << argc - 1 << " elements with std::list :   " << lst_time << " us" << std::endl;
	return 0;
}
