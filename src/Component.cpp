/*
** EPITECH PROJECT, 2018
** Component.cpp
** File description:
** 
*/

#include "Component.hpp"

void Component::setLinkReverse(std::size_t pin, nts::IComponent &other,
			       std::size_t otherPin)
{
	compLink_t newLink;

	newLink.component = &other;
	newLink.pin = otherPin;
	links[pin] = newLink;
}

void Component::setLink(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin)
{
	compLink_t newLink;
	
	newLink.component = &other;
	newLink.pin = otherPin;
	links[pin] = newLink;
	other.setLinkReverse(otherPin, *this, pin);
}

void Component::dump() const
{
	std::cout << this->getName() << ":" << std::endl;
	for (auto &elem : pin) {
		std::cout << std::get<1>(elem).state << std::endl;
	}
}

nts::Tristate operator&&(nts::Tristate left, nts::Tristate right)
{
	if (left == nts::Tristate::TRUE && right == nts::Tristate::TRUE)
		return nts::Tristate::TRUE;
	else
		return nts::Tristate::FALSE;
}

nts::Tristate operator||(nts::Tristate left, nts::Tristate right)
{
	if (left == nts::Tristate::TRUE || right == nts::Tristate::TRUE)
		return nts::Tristate::TRUE;
	else
		return nts::Tristate::FALSE;
}

nts::Tristate operator!(nts::Tristate main)
{
	if (main == nts::Tristate::TRUE)
		return nts::Tristate::FALSE;
	if (main == nts::Tristate::FALSE)
		return nts::Tristate::TRUE;
	else
		return nts::Tristate::UNDEFINED;
}

std::ostream &operator<<(std::ostream &stream, nts::Tristate state)
{
	if (state == nts::FALSE)
		stream << "0";
	else if (state == nts::TRUE)
		stream << "1";
	else
		stream << "U";
	return stream;
}