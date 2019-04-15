/*
** EPITECH PROJECT, 2018
** Command.cpp
** File description:
** 
*/
#include "Errors.hpp"

#include "Command.hpp"

Command::Command(char **av)
{
	InitTerm(av);
}

void Command::InitTerm(char **av)
{
	Parser pars(av[1]);

	try {
		pars.getFile();
		pars.createCircuit();
		pars.createLinks();
	} catch (Errors const &err) {
		std::cout << "Error Config: " << err.what() << std::endl;
		std::exit(84);
	}
	this->Components = pars.Components;
	try {
		setInput(av, pars);
	} catch (Errors const &err) {
		std::cout << "Error Input: " << err.what() << std::endl;
		std::exit(84);
	}
}

Command::~Command()
{
}

int Command::countInputs()
{	
	int a = 2;
	
	for (auto &elem : Components) {
		if (std::get<1>(elem)->getType() == "Input")
			a++;
	}
	return a;
}
void Command::setInput(char **av, Parser pars)
{
	nts::Tristate state;
	int i = 1;

	while (++i, av[i]) {
		try {
			state = static_cast<nts::Tristate>(std::stoi(static_cast
			<std::string>(av[i]).substr(static_cast<std::string>
			(av[i]).find("=") + 1)));
		} catch (std::invalid_argument const &e) {
			throw Errors("A provided input is unknown.");
		}
		std::string tmp2 = static_cast<std::string>(av[i]).substr(
			0, static_cast<std::string>(av[i]).find("="));
		if (pars.Components.find(tmp2) == pars.Components.end())
			throw Errors("A provided input is unknown.");
		pars.Components[tmp2]->setState(state);
	}
	if (countInputs() != i)
		throw Errors(
		"no input values for inputs provided in the command line.");
}

void Command::exit()
{
	std::exit(0);
}

void Command::display()
{
	for (auto &elem : Components) {
		if (std::get<1>(elem)->getType() == "Output")
			std::cout << std::get<1>(elem)->getName() << "=" 
			<< std::get<1>(elem)->compute(1) << std::endl;
	}
}

void Command::select_state(std::string com)
{
	std::string name;
	std::string value;

	if (com.find("=") == com.npos)
		return;
	name = com.substr(0, com.find("="));
	value = com.substr(com.find("=") + 1);

	Components[name]->setState(static_cast<nts::Tristate>(stoi(value)));
	//POTENTIAL ERROR
}

void Command::select_next(std::string com)
{
	if (com == "loop")
		loop();
	else if (com == "dump")
		dump();
	else
		select_state(com);
}

void Command::select()
{
	if (isatty(0) == 1)
	       	std::cout << "> ";
	for (std::string com; std::cin >> com;) {
		if (com == "display")
			display();
		else if (com == "exit")
			exit();
		else if (com == "simulate")
			simulate();
		else
			select_next(com);
		if (isatty(0) == 1)
		       	std::cout << "> ";	
	}
}

void Command::simulate()
{
	for (auto &elem : Components) {
		if (std::get<1>(elem)->getType() == "Output")
			std::get<1>(elem)->compute(1);
	}
}

void Command::loop()
{
	while (42) {
		display();
	}
}

void Command::dump()
{
	for (auto &elem : Components) {
		std::get<1>(elem)->dump();
	}
}