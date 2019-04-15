/*
** EPITECH PROJECT, 2017
** IComponent.hpp
** File description:
** NanoTekSpice
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

#include <cstddef>
#include <string>
#include <ostream>

namespace nts
{
	enum Tristate {
		TRUE = true,
		FALSE = false,
		UNDEFINED = (-true),
	};
	enum PinType {
		INPUT,
		OUTPUT,
	};
	class IComponent {
		public:
			virtual ~IComponent() = default;
			virtual nts::Tristate compute(std::size_t pin = 1) = 0;
			virtual void setLinkReverse(std::size_t pin,
			nts::IComponent &other, std::size_t otherPin) = 0;
			virtual void setLink(std::size_t pin,
			nts::IComponent &other, std::size_t otherPin) = 0;
			virtual void dump() const = 0;
			virtual void setState(nts::Tristate) = 0;
			virtual std::string getName() const = 0;
			virtual std::string getType() const = 0;
			virtual int getmaxInputsNb() const = 0;
			virtual int getmaxOutputsNb() const = 0;
		protected:
		private:
	};
}
std::ostream &operator<<(std::ostream &stream, nts::Tristate state);

#endif /* !ICOMPONENT_HPP_ */
