#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);

		const std::string		&getTarget(void) const;

		virtual void			execute(Bureaucrat const & executor) const;

		class executeFailure : public std::exception {
			virtual const char	*what() const throw();
		};

	private:
		const std::string	_target;
		static const int	sign = 72;
		static const int	exec = 45;
};

#endif