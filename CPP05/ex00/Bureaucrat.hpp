#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

# define TOP 1
# define BOTTOM 150

class Bureaucrat{
	public:
		class GradeTooHighException : public std::exception {
			virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char	*what() const throw();
		};

		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &obj);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				upGrade(void);
		void				downGrade(void);
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
