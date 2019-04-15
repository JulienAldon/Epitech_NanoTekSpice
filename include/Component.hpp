/*
** EPITECH PROJECT, 2018
** Component.hpp
** File description:
** NanoTekSpice
*/

#ifndef COMPONENT_HPP_
	#define COMPONENT_HPP_

#include <iostream>
#include <map>
#include "IComponent.hpp"

typedef struct compLink_s {
	nts::IComponent *component;
	size_t pin;
} compLink_t;

typedef struct pinState_s {
	nts::Tristate state;
	nts::PinType pinType;
} pinState_t;

class Component: public nts::IComponent {
	public:
		virtual nts::Tristate compute(std::size_t pin = 0) = 0;
		void setLinkReverse(std::size_t pin, nts::IComponent &other,
			std::size_t otherPin) override;
		void setLink(std::size_t pin, nts::IComponent &other, 
			std::size_t otherPin) override;
		void dump() const override;
	protected:
		std::map<std::size_t, compLink_t> links;
		std::map<std::size_t, pinState_t> pin;
	private:
};

nts::Tristate operator&&(nts::Tristate left, nts::Tristate right);
nts::Tristate operator||(nts::Tristate left, nts::Tristate right);
nts::Tristate operator!(nts::Tristate main);

#endif /* !COMPONENT_HPP_ */
