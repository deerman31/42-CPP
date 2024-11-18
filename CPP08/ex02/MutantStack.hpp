#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <deque>

/*
T Containerという２つのtemplateパラメータを設定
Containerのdefaultのコンテナの型はstd::dequeである。理由はstd::stackが持つ機能をすべて提供されているから。
Tはコンテナに格納されるの要素の型
*/
template <typename T, typename Container = std::deque<T> >
/*
std::stackを継承したMutantStackを作成、基本的な継承方法を大体一緒
std::stack<T, Container> Tはstackに格納される型、 ContainerはTを格納するコンテナの型である。
std::stackは実際のコンテナではなく、コンレナアダプタであり、既存のコンテナ（std::dequeなど）にstackの機能を追加するラッパーである。
*/
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack(void) {}
		~MutantStack(void) {}
		MutantStack(const MutantStack &src) {
			*this = src;
		}
		MutantStack	&operator=(const MutantStack &obj) {
			if (this == &obj)
				return *this;
			std::stack<T, Container>::operator=(obj);
			return *this;
		}
/*
cはstd::stackの内部のメンバーである。
それを通して、値を操作している。
*/
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		iterator	begin(void) {
			return this->c.begin();
		}
		iterator	end(void) {
			return this->c.end();
		}
		const_iterator	begin(void) const {
			return this->c.begin();
		}
		const_iterator	end(void) const {
			return this->c.end();
		}
};

#endif
