/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <map>
#include "Graphic/IDisplayModule.hpp"
#include "Game/IGame.hpp"
#include "LoadLib/LoadLib.hpp"
/**
 * @brief namespace for arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief core class
 * @class Core
 * 
 */
class Core {
public:
    /**
     * @brief Construct a new Core object
     * 
     */
    Core() = default;
    /**
     * @brief Destroy the Core object
     * 
     */
    ~Core() = default;
    /**
     * @brief Open shared library and load games
     * 
     * @param ldb 
     * @param s 
     */
    void OpenGame(const LoadLib &ldb, const std::string &s);
    /**
     * @brief open first shared library
     * 
     * @param s 
     * @param ldb 
     */
    void OpenFirstLibs(std::string &s, LoadLib &ldb);
    /**
     * @brief open multiple libs
     * 
     * @param ldb 
     * @param name 
     */
    void OpenLibsInLibs(const LoadLib &ldb, const std::string &name);
    /**
     * @brief game loop
     * 
     */
    void gameLoop();
    /**
     * @brief Get the Types object
     * 
     * @param s 
     * @param b 
     */
    void getTypes(const std::string &s, LoadLib &b);
    /**
     * @brief play game
     * 
     * @param gaming 
     * @param event 
     * @param libs 
     */
    void game(IGame *gaming, events_e event, IDisplayModule *libs);
    /**
     * @brief clear all loaded libs
     * 
     */
    void clearLibs()
    {
        _loadGames.clear();
        _loadLibs.clear();
    }

protected:
    /**
     * @brief loaded games
     * 
     */
    std::vector<std::pair<std::string, IGame *>> _loadGames;
    /**
     * @brief loaded libs
     * 
     */
    std::vector<std::pair<std::string, IDisplayModule *>> _loadLibs;
};
}