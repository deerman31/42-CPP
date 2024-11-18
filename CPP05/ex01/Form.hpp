#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

# define TOP 1
# define BOTTOM 150

class Bureaucrat;

class Form {
	public:
		class GradeTooHighException : public std::exception {
			virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char	*what() const throw();
		};
		Form(void);
		Form(const std::string name, int sing_grade, int execute_grade);
		Form(const Form &src);
		~Form(void);

		Form	&operator=(const Form &obj);

		const std::string	&getName(void) const;
		int					getsignGrade(void) const;
		int					getexecGrade(void) const;
		bool				getsigned(void) const;
		void				beSigned(const Bureaucrat &obj);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif