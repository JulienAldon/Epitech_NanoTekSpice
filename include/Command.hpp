/*
** EPITECH PROJECT, 2018
** Command.hpp
** File description:
** 
*/

#ifndef COMMAND_HPP_
	#define COMMAND_HPP_

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <regex>
#include <list>
#include <exception>
#include <unistd.h>
#include "SpecialComponents.hpp"
#include "Parser.hpp"
#include "Creation.hpp"
#include "IComponent.hpp"

class Command {
public:
	Command(char **av);
	~Command();
	void exit();
	void InitTerm(char **av);
	void display();
	int countInputs();
	void setInput(char **av, Parser pars);
	void simulate();
	void loop();
	void dump();
	void select();
	void select_next(std::string com);
	void select_state(std::string com);
protected:
private:
	std::map<std::string, nts::IComponent *> Components;
};

#endif /* !COMMAND_HPP_ */
