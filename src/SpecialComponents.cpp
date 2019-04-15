/*
** EPITECH PROJECT, 2017
** SpecialComponnent.cpp
** File description:
** NanoTekSpice
*/

#include "SpecialComponents.hpp"

//Class Input

Input::Input(const std::string &name) : name(name)
{
	setState(nts::UNDEFINED);
}

std::string Input::getName() const
{
	return this->name;
}

nts::Tristate Input::compute(std::size_t pin)
{
	return this->pin[pin].state;
}

std::string Input::getType() const
{
	return "Input";
}

void Input::setState(nts::Tristate state)
{
	pinState_t newpin;

	if (state != nts::TRUE && state != nts::FALSE)
		state = nts::UNDEFINED;
	newpin.pinType = nts::PinType::OUTPUT;
	newpin.state = state;
	this->pin[1] = newpin;
}

int Input::getmaxInputsNb() const
{
	return 0;
}

int Input::getmaxOutputsNb() const
{
	return 1;
}


//Class Output
Output::Output(const std::string &name) : name(name)
{
}

std::string Output::getType() const
{
	return "Output";
}

void Output::setState(nts::Tristate state)
{
}

std::string Output::getName() const
{
	return this->name;
}


nts::Tristate Output::compute(std::size_t pin)
{
	nts::Tristate state = links[pin].component->compute(links[pin].pin);
	this->pin[pin].state = state;
	return state;
}

int Output::getmaxInputsNb() const
{
	return 1;
}

int Output::getmaxOutputsNb() const
{
	return 0;
}


//Class Clock
Clock::Clock(const std::string &name) : name(name)
{
}

nts::Tristate Clock::compute(std::size_t pin)
{
	nts::Tristate old = this->pin[pin].state;
	this->pin[pin].state = (this->pin[pin].state == nts::TRUE)
				 ? nts::FALSE : nts::TRUE;  
	return old;
}

void Clock::setState(nts::Tristate state)
{
	pinState_t newpin;

	newpin.pinType = nts::PinType::OUTPUT;
	newpin.state = state;
	this->pin[1] = newpin;
}

std::string Clock::getType() const
{
	return "Clock";
}

std::string Clock::getName() const
{
	return this->name;
}

int Clock::getmaxInputsNb() const
{
	return 0;
}

int Clock::getmaxOutputsNb() const
{
	return 1;
}


//Class True
True::True(const std::string &name) : name(name)
{
	setState(nts::TRUE);
}

nts::Tristate True::compute(std::size_t pin)
{
}

void True::setState(nts::Tristate state)
{
	pinState_t newpin;

	newpin.pinType = nts::PinType::OUTPUT;
	newpin.state = state;
	this->pin[1] = newpin;
}

std::string True::getType() const
{
	return "True";
}

std::string True::getName() const
{
	return this->name;
}

int True::getmaxInputsNb() const
{
	return 0;
}

int True::getmaxOutputsNb() const
{
	return 1;
}


//Class False
False::False(const std::string &name) : name(name)
{
	setState(nts::FALSE);
}

nts::Tristate False::compute(std::size_t pin)
{
}

void False::setState(nts::Tristate state)
{
	pinState_t newpin;

	newpin.pinType = nts::PinType::OUTPUT;
	newpin.state = state;
	this->pin[1] = newpin;
}

std::string False::getType() const
{
	return "False";
}

std::string False::getName() const
{
	return this->name;
}

int False::getmaxInputsNb() const
{
	return 0;
}

int False::getmaxOutputsNb() const
{
	return 1;
}


//4081 (Quad 2 Input AND)
comp4081::comp4081(const std::string &name) : name(name), maxInputsNb(8), 
	maxOutputsNb(4)
{
}

std::string comp4081::getType() const
{
	return "4081";
}

std::string comp4081::getName() const
{
	return this->name;
}

int comp4081::getmaxInputsNb() const
{
	return maxInputsNb;
}

int comp4081::getmaxOutputsNb() const
{
	return maxOutputsNb;
}

void comp4081::setState(nts::Tristate state)
{
}

nts::Tristate comp4081::compute(std::size_t pinNb)
{
	nts::Tristate input1, input2;

	if (pinNb == 3 || pinNb == 10) {
		input1 = links[pinNb - 2].component->compute(
			links[pinNb - 2].pin);
		input2 = links[pinNb - 1].component->compute(
			links[pinNb - 1].pin);
	} if (pinNb == 4 || pinNb == 11) {
		input1 = links[pinNb + 1].component->compute(
			links[pinNb + 1].pin);
		input2 = links[pinNb + 2].component->compute(
			links[pinNb - 2].pin);
	}
	pin[pinNb].state = input1 && input2;
	return input1 && input2;
}

//4001 (Quad 2 Input NOR)
comp4001::comp4001(const std::string &name) : name(name), maxInputsNb(8), 
	maxOutputsNb(4) 
{
}

nts::Tristate comp4001::compute(std::size_t pinNb)
{
	nts::Tristate input1, input2;

	if (pinNb == 3 || pinNb == 10) {
		input1 = links[pinNb - 2].component->compute(
			links[pinNb - 2].pin);
		input2 = links[pinNb - 1].component->compute(
			links[pinNb - 1].pin);
	} if (pinNb == 4 || pinNb == 11) {
		input1 = links[pinNb + 1].component->compute(
			links[pinNb + 1].pin);
		input2 = links[pinNb + 2].component->compute(
			links[pinNb - 2].pin);
	}
	pin[pinNb].state = !(input1 || input2);	
	return !(input1 || input2);
}

std::string comp4001::getName() const
{
	return name;
}

std::string comp4001::getType() const 
{
	return "4001";
}

int comp4001::getmaxInputsNb() const
{
	return maxInputsNb;
}

int comp4001::getmaxOutputsNb() const
{
	return maxOutputsNb;
}

void comp4001::setState(nts::Tristate state)
{
}

//4011 (Quad 2 Input CMOS NAND gates)
comp4011::comp4011(const std::string &name) : name(name), maxInputsNb(8), 
	maxOutputsNb(4) 
{
}

nts::Tristate comp4011::compute(std::size_t pinNb)
{
	nts::Tristate input1, input2;

	if (pinNb == 3 || pinNb == 10) {
		input1 = links[pinNb - 2].component->compute(
			links[pinNb - 2].pin);
		input2 = links[pinNb - 1].component->compute(
			links[pinNb - 1].pin);
	} if (pinNb == 4 || pinNb == 11) {
		input1 = links[pinNb + 1].component->compute(
			links[pinNb + 1].pin);
		input2 = links[pinNb + 2].component->compute(
			links[pinNb - 2].pin);
	}
	pin[pinNb].state = !(input1 && input2);	
	return !(input1 && input2);
}

std::string comp4011::getName() const
{
	return name;
}

std::string comp4011::getType() const 
{
	return "4011";
}

int comp4011::getmaxInputsNb() const
{
	return maxInputsNb;
}

int comp4011::getmaxOutputsNb() const
{
	return maxOutputsNb;
}


void comp4011::setState(nts::Tristate state)
{
}

//comp4071
comp4071::comp4071(const std::string &name) : name(name), maxInputsNb(8), 
	maxOutputsNb(4) 
{
}

nts::Tristate comp4071::compute(std::size_t pinNb)
{
	nts::Tristate input1, input2;

	if (pinNb == 3 || pinNb == 10) {
		input1 = links[pinNb - 2].component->compute(
			links[pinNb - 2].pin);
		input2 = links[pinNb - 1].component->compute(
			links[pinNb - 1].pin);
	} if (pinNb == 4 || pinNb == 11) {
		input1 = links[pinNb + 1].component->compute(
			links[pinNb + 1].pin);
		input2 = links[pinNb + 2].component->compute(
			links[pinNb - 2].pin);
	}
	pin[pinNb].state = input1 || input2;
	return input1 || input2;
}

std::string comp4071::getName() const
{
	return name;
}

std::string comp4071::getType() const 
{
	return "4071";
}

int comp4071::getmaxInputsNb() const
{
	return maxInputsNb;
}

int comp4071::getmaxOutputsNb() const
{
	return maxOutputsNb;
}

void comp4071::setState(nts::Tristate state)
{
}

//4030 (Quad EXCLUSIVE-OR Gate)
comp4030::comp4030(const std::string &name) : name(name), maxInputsNb(8), 
	maxOutputsNb(4) 
{
}

nts::Tristate comp4030::compute(std::size_t pinNb)
{
	nts::Tristate input1, input2, tmp;

	if (pinNb == 3 || pinNb == 10) {
		input1 = links[pinNb - 2].component->compute(
			links[pinNb - 2].pin);
		input2 = links[pinNb - 1].component->compute(
			links[pinNb - 1].pin);
	} if (pinNb == 4 || pinNb == 11) {
		input1 = links[pinNb + 1].component->compute(
			links[pinNb + 1].pin);
		input2 = links[pinNb + 2].component->compute(
			links[pinNb - 2].pin);
	}
	if ((input1 == nts::Tristate::TRUE && input2 == nts::Tristate::TRUE) ||
	(input1 == nts::Tristate::FALSE && input2 == nts::Tristate::FALSE))
		tmp = nts::Tristate::FALSE;
	else if (input1 == nts::Tristate::UNDEFINED
	|| input2 == nts::Tristate::UNDEFINED)
		tmp = nts::Tristate::UNDEFINED;
	pin[pinNb].state = tmp;
	return tmp;
}

std::string comp4030::getName() const
{
	return name;
}

std::string comp4030::getType() const 
{
	return "4030";
}

int comp4030::getmaxInputsNb() const
{
	return maxInputsNb;
}

int comp4030::getmaxOutputsNb() const
{
	return maxOutputsNb;
}


void comp4030::setState(nts::Tristate state)
{
}