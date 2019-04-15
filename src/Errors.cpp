/*
** EPITECH PROJECT, 2018
** Nanotekspice
** File description:
** Errors
*/

#include "Errors.hpp"

Errors::Errors(std::string const &message) : message(message)
{
}

Errors::~Errors()
{
}

const char *Errors::what() const noexcept
{
        return &message[0];
}