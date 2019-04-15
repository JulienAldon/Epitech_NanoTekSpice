/*
** EPITECH PROJECT, 2018
** NanotekSpice
** File description:
** Creation
*/

#include "Creation.hpp"

Creation::Creation()
{
	comp["input"] = &Creation::createInput;
	comp["output"] = &Creation::createOutput;
	comp["clock"] = &Creation::createClock;
	comp["true"] = &Creation::createTrue;
	comp["false"] = &Creation::createFalse;
	// comp["2716"] = &Creation::create2716;
	comp["4001"] = &Creation::create4001;
	// comp["4008"] = &Creation::create4008;
	comp["4011"] = &Creation::create4011;
	// comp["4013"] = &Creation::create4013;
	// comp["4017"] = &Creation::create4017;
	comp["4030"] = &Creation::create4030;
	// comp["4040"] = &Creation::create4040;
	// comp["4069"] = &Creation::create4069;
	comp["4071"] = &Creation::create4071;
	comp["4081"] = &Creation::create4081;	
	// comp["4094"] = &Creation::create4094;
	// comp["4512"] = &Creation::create4512
	// comp["4514"] = &Creation::create4514;
	// comp["i4004"] = &Creation::createi4004;
	// comp["mk4801"] = &Creation::createmk4801:
}

Creation::~Creation()
{
}

nts::IComponent	*Creation::createComponent(const std::string &type, const std::string &value)
{
	if (comp.find(type) == comp.end()) {
		throw Errors("Component type " + type + " is unknown");
	}
	return (this->*comp[type])(value);
}

nts::IComponent *Creation::createInput(const std::string &value) const
{
	return new Input(value);
}

nts::IComponent *Creation::createOutput(const std::string &value) const
{
	return new Output(value);
}

nts::IComponent *Creation::createClock(const std::string &value) const
{
	return new Clock(value);
}


nts::IComponent *Creation::createTrue(const std::string &value) const
{
	return new True(value);
}


nts::IComponent *Creation::createFalse(const std::string &value) const
{
	return new False(value);
}


// nts::IComponent *Creation::create2716(const string &value) const
// {
// 	return (new 2716(value));
// }


nts::IComponent *Creation::create4001(const std::string &value) const
{
	return new comp4001(value);
}


// nts::IComponent *Creation::create4008(const string &value) const
// {
// 	return (new 4008(value));
// }


nts::IComponent *Creation::create4011(const std::string &value) const
{
	return new comp4011(value);
}


// nts::IComponent *Creation::create4013(const string &value) const
// {
// 	return (new 4013(value));
// }


// nts::IComponent *Creation::create4017(const string &value) const
// {
// 	return (new 4017(value));
// }


nts::IComponent *Creation::create4030(const std::string &value) const
{
	return new comp4030(value);
}


// nts::IComponent *Creation::create4040(const string &value) const
// {
// 	return (new 4040(value));
// }


// nts::IComponent *Creation::create4069(const string &value) const
// {
// 	return (new 4069(value));
// }


nts::IComponent *Creation::create4071(const std::string &value) const
{
	return new comp4071(value);
}

nts::IComponent *Creation::create4081(const std::string &value) const
{
	return new comp4081(value);
}

// nts::IComponent *Creation::create4094(const string &value) const
// {
// 	return (new 4094(value));
// }

// nts::IComponent *Creation::create4503(const string &value) const
// {
// 	return (new 4503(value));
// }

// nts::IComponent *Creation::create4512(const string &value) const
// {
// 	return (new 4512(value));
// }

// nts::IComponent *Creation::create4514(const string &value) const
// {
// 	return (new 4514(value));
// }

// nts::IComponent *Creation::createi4004(const string &value) const
// {
// 	return (new i4004(value));
// }

// nts::IComponent *Creation::createmk4801(const string &value) const
// {
// 	return (new mk4801(value));
// }