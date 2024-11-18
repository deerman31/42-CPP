#include "MutantStack.hpp"
#include <list>

int main() {
	// 基本操作のテスト
	MutantStack<int> mstack;
	std::cout << "Pushing elements onto the stack..." << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Current top: " << mstack.top() << std::endl; // 期待される出力: 17

	mstack.pop();
	std::cout << "After popping, current size: " << mstack.size() << std::endl; // 期待される出力: 1

	// イテレータを使用した走査のテスト
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterating through stack elements..." << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}
	// 期待される出力: スタックにプッシュした順番での値

	// コピー構築子と代入演算子のテスト
	MutantStack<int> copiedStack(mstack);
	std::cout << "\n-------------------" << std::endl;
	std::cout << "Testing copy..." << std::endl;
	// コピーされたスタックと代入されたスタックで、同様にイテレートして、
	// 元のスタックと同じ順番と値が得られることを確認します。

	std::cout << "Iterating through stack elements..." << std::endl;
	for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << "\n-------------------" << std::endl;
	std::cout << "Testing assignment..." << std::endl;

	std::cout << "Iterating through stack elements..." << std::endl;
	for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
		std::cout << *it << std::endl;
	}


	std::cout << "--------------------------------------\n\n";
	std::cout << "list" << std::endl;
	std::list<int> lst;
	std::cout << "Pushing elements onto the list..." << std::endl;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Current top: " << lst.back() << std::endl; // 期待される出力: 17

	lst.pop_back();
	// lst.pop(); // std::listには直接popメソッドがないため、pop_frontやpop_backを使用する必要がある
	std::cout << "After popping, current size: " << lst.size() << std::endl; // 期待される出力: 1

	// イテレータを使用した走査のテスト
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Iterating through list elements..." << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << std::endl;
	}


	return 0;
}

