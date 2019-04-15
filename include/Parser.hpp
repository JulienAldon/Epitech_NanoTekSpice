/*
** EPITECH PROJECT, 2018
** Parser.hpp
** File description:
** NanoTekSpice
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <regex>
#include <list>
#include <exception>
#include <stdexcept>
#include "Circuit.hpp"
#include "Creation.hpp"
#include "Errors.hpp"


class Parser {
	public:
		typedef struct lin_s {
			std::string base;
			std::string name;
			int pin;
		} lin_t;
		Parser(std::string filename);
		~Parser();
		void getFile();
		std::map<std::string, nts::IComponent *> getMap() const;
		std::list<std::string> getChips() const;
		std::list<std::string> getLinks() const;
		int getNbinput() const;
		void pushFile(int mode, std::string str);
		void pushFileMode(int &mode, std::string &str, std::ifstream &file);
		void createCircuit();
		lin_t fillFirst(std::istringstream &b);
		lin_t fillSecond(std::istringstream &b);
		void createLinks();
		std::map<std::string, nts::IComponent *> Components;
	protected:
	private:
	        std::list<std::string> chips;
        	std::list<std::string> links;
		std::string fileName;
		int nbInput;
};


#endif /* !PARSER_HPP_ */
