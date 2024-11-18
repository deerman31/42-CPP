#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

# define TOP 1
# define BOTTOM 150

class Bureaucrat;

class AForm {
	public:
		class GradeTooHighException : public std::exception {
			virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char	*what() const throw();
		};
		class IsSignedException : public std::exception {
			virtual const char	*what() const throw();
		};
		AForm(void);
		AForm(const std::string name, int sing_grade, int execute_grade);
		AForm(const AForm &src);
		virtual ~AForm(void);

		AForm	&operator=(const AForm &obj);

		const std::string	&getName(void) const;
		int					getsignGrade(void) const;
		int					getexecGrade(void) const;
		bool				getsigned(void) const;
		void				beSigned(const Bureaucrat &obj);

		virtual void		execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif