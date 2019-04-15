/*
** EPITECH PROJECT, 2018
** Parser.cpp
** File description:
** NanoTekSpice
*/

#include "Parser.hpp"

Parser::Parser(std::string fileName) : fileName(fileName), nbInput(0)
{
}

Parser::~Parser()
{
}

std::list<std::string> Parser::getChips() const
{
	return chips;
}

std::list<std::string> Parser::getLinks() const
{
	return links;
}

std::map<std::string, nts::IComponent *> Parser::getMap() const
{
	return Components;
}

Parser::lin_t Parser::fillFirst(std::istringstream &b)
{
	lin_t first;
	
	b >> first.base;
	first.name = first.base.substr(0, first.base.find(":"));
	std::string tmp1 = first.base.substr(first.base.find(":") + 1);
	first.pin = std::stoi(tmp1);
	if (Components.find(first.name) == Components.end())
		throw Errors("Component name " + first.name + " is unknown.");
	if (Components[first.name]->getmaxInputsNb() + 
		Components[first.name]->getmaxOutputsNb() < first.pin)
		throw Errors("requested pin " + first.name + ":"
		+ std::to_string(first.pin) + " does not exist.");
	return first;
}

Parser::lin_t Parser::fillSecond(std::istringstream &b)
{
	lin_t second;
	std::string trash;
	std::string tmp2;

	b >> second.base;
	second.name = second.base.substr(0, second.base.find(":"));
	tmp2 = second.base.substr(second.base.find(":") + 1);
	second.pin = std::stoi(tmp2);
	if (Components.find(second.name) == Components.end())
		throw Errors("Component name " + second.name + " is unknown.");
	if (Components[second.name]->getmaxInputsNb() + 
	Components[second.name]->getmaxOutputsNb() < second.pin)
		throw Errors("requested pin " + second.name + ":"
		+ std::to_string(second.pin) + " does not exist.");
	return second;
}

void Parser::createLinks()
{
	lin_t first;
	lin_t second;
	
	if (chips.size() < 1 || links.size() < 1)
		throw Errors("No links found.");
	for (auto &elem : links) {
		std::istringstream b(elem);
		first = fillFirst(b);
		second = fillSecond(b);
		Components[first.name]->
		setLink(static_cast<std::size_t>(first.pin), *Components[
			second.name], static_cast<std::size_t>(second.pin));
	}
}

int Parser::getNbinput() const
{
	return nbInput;
}

void Parser::createCircuit()
{
	Creation create;
	std::string type;
	std::string name;

	if (chips.size() < 1 || links.size() < 1)
		throw Errors("No Chipset found.");
	for (auto &elem : chips) {
		std::istringstream b(elem);
		b >> type;
		b >> name;
		if (Components.find(name) != Components.end())
			throw Errors(
			"Several Components share the same name.");
		if (type == "input")
			nbInput += 1;
		Components.insert(std::make_pair(name, 
			create.createComponent(type, name)));
	}
}

void Parser::pushFile(int mode, std::string str)
{
	if (mode == 1)
		chips.push_back(str);
	if (mode == 2)
		links.push_back(str);
}

void Parser::pushFileMode(int &mode, std::string &str, std::ifstream &file)
{
	std::regex com("^[ \t]*(#.*|)$"); 
	std::regex chip("(.chipsets:)");
	std::regex link("(.links:)");

	if (std::regex_match(str.begin(), str.end(), chip)) {
		mode = 1;
		std::getline(file, str);	
	}
	if (std::regex_match(str.begin(), str.end(), link)) {
		mode = 2;
		std::getline(file, str);
	}
	if (std::regex_match(str.begin(), str.end(), com)) {
		std::getline(file, str);
	}
}

void Parser::getFile()
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw Errors("Incorrect file.");
	int mode = 0;

	for (std::string str; std::getline(file, str);) {
		pushFileMode(mode, str, file);
		if (mode != 0)
			pushFile(mode, str);
	}
}