#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define NUM_IDEAS 100

class Brain {
	private:
		std::string	_ideas[NUM_IDEAS];
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &src);
		Brain	&operator=(const Brain &obj);

		void	set_Ideas(std::string idea, int i);
        const std::string    &get_Ideas(int i) const;
};

#endif
