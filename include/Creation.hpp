/*
** EPITECH PROJECT, 2018
** NanoTekSpice
** File description:
** Creation
*/

#ifndef CREATION_HPP_
	#define CREATION_HPP_

#include "IComponent.hpp"
#include "SpecialComponents.hpp"
#include "Errors.hpp"

class Creation {
	public:
		typedef nts::IComponent *(Creation::*func_ptr)(const std::string &value) const;
	public:
		Creation();
		~Creation();
		
		nts::IComponent	*createComponent(const std::string &type, const std::string &value);
	private:
		std::map<std::string, Creation::func_ptr> comp;

		nts::IComponent *createInput(const std::string &value) const;
		nts::IComponent *createOutput(const std::string &value) const;
		nts::IComponent *createFalse(const std::string &value) const;
		nts::IComponent *createClock(const std::string &value) const;
		nts::IComponent *createTrue(const std::string &value) const;
		nts::IComponent *create4081(const std::string &value) const;
		nts::IComponent *create4001(const std::string &value) const;
		nts::IComponent *create4011(const std::string &value) const;
		nts::IComponent *create4071(const std::string &value) const;
		nts::IComponent *create4030(const std::string &value) const;
	protected:
};

#endif /* !CREATION_HPP_ */
