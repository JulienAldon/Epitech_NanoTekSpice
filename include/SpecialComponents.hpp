/*
** EPITECH PROJECT, 2017
** SpecialComponent.hpp
** File description:
** NanoTekSpice
*/

#ifndef SPECIALCOMPONENTS_HPP_
	#define SPECIALCOMPONENTS_HPP_

#include <iostream>
#include <string>
#include "Component.hpp"

class Input : public Component {
public:
	Input(const std::string &value);
	nts::Tristate compute(std::size_t pin = 0) override;
	void setState(nts::Tristate state) override;
	std::string getName() const;
	std::string getType() const override;
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
};

class Output : public Component {
public:
	Output(const std::string &value);
	nts::Tristate compute(std::size_t pin = 0) override;
	void setState(nts::Tristate state);
	std::string getName() const;
	std::string getType() const override;
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
};


class Clock : public Component {
public:
	Clock(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	void setState(nts::Tristate state);
	std::string getName() const;
	std::string getType() const override;
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
};

class True : public Component {
public:
	True(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	void setState(nts::Tristate state);
	std::string getName() const;
	std::string getType() const override;
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
};

class False : public Component {
public:
	False(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	void setState(nts::Tristate state);
	std::string getName() const;
	std::string getType() const override;
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
};

class comp4081 : public Component {
public:
	comp4081(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	std::string getType() const override;
	std::string getName() const;
	void setState(nts::Tristate state);
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
	int maxInputsNb;
	int maxOutputsNb;
};


class comp4001 : public Component {
public:
	comp4001(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	std::string getName() const;
	std::string getType() const;
	void setState(nts::Tristate state);
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
	int maxInputsNb;
	int maxOutputsNb;
};

class comp4011 : public Component {
public:
	comp4011(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	std::string getName() const;
	std::string getType() const;
	void setState(nts::Tristate state);
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
	int maxInputsNb;
	int maxOutputsNb;
};

class comp4071 : public Component {
public:
	comp4071(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	std::string getName() const;
	std::string getType() const;
	void setState(nts::Tristate state);
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
	int maxInputsNb;
	int maxOutputsNb;
};

class comp4030 : public Component {
public:
	comp4030(const std::string &name);
	nts::Tristate compute(std::size_t pin = 0) override;
	std::string getName() const;
	std::string getType() const;
	void setState(nts::Tristate state);
	int getmaxInputsNb() const override;
	int getmaxOutputsNb() const override;
protected:
	const std::string name;
private:
	int maxInputsNb;
	int maxOutputsNb;
};

#endif /* !SPECIALCOMPONENTS_HPP_ */
