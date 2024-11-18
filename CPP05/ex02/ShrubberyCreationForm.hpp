#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);

		const std::string		&getTarget(void) const;

		virtual void			execute(Bureaucrat const & executor) const;

		class executeFailure : public std::exception {
			virtual const char	*what() const throw();
		};

	private:
		const std::string	_target;
		static const int	sign = 143;
		static const int	exec = 137;


};

#endif