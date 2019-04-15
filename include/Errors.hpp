#ifndef ERRORS_HPP_
	#define ERRORS_HPP_

#include <string>
#include <exception>

class Errors : public std::exception {
	public:
		Errors(std::string const &message);
		~Errors();
		const char *what() const noexcept override;

	protected:
	        std::string message;
	private:
};



#endif /* !ERRORS_HPP_ */
