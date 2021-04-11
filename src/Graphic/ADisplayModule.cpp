/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include "ADisplayModule.hpp"

arcade::ADisplayModule::ADisplayModule(const std::string &name) : _name(name)
{
}

std::string const &arcade::ADisplayModule::getName() const
{
    return _name;
}