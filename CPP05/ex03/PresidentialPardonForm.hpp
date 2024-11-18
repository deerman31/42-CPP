#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm  &operator=(const PresidentialPardonForm &obj);

		const std::string		&getTarget(void) const;

		virtual void			execute(Bureaucrat const & executor) const;

		class executeFailure : public std::exception {
			virtual const char	*what() const throw();
		};

	private:
		const std::string	_target;
		static const int	sign = 25;
		static const int	exec = 5;

};

#endif