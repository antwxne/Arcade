/*
** EPITECH PROJECT, 2021
** main.cpp.c
** File description:
** main.cpp.c
*/

#include <iostream>
#include "dynamicFile.hpp"
#include "Error/Error.hpp"
#include "LoadLib/LoadLib.hpp"
#include "Core/Core.hpp"

int main([[maybe_unused]] int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Arguments must be only two" << std::endl;
        return 84;
    }
    std::string tmp = std::string(argv[1]);
    DynamicFile a;
    arcade::Core core;
    LoadLib ldb;
    try {
        a.VerifyArg(tmp);
        core.OpenFirstLibs(tmp, ldb);
        core.gameLoop();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    core.clearLibs();
    ldb.destroyOpenFile();
    return 0;
}