/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <memory>
#include <vector>
#include "Object/IObject.hpp"
#include "Graphic/IDisplayModule.hpp"

/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief interface for games
 * @class IGame
 * 
 */
class IGame {
public:
    /**
     * @brief Destroy the IGame object
     * 
     */
    virtual ~IGame() = default;
    /**
     * @brief game instruction
     * 
     * @return const std::vector<std::shared_ptr<IObject>> 
     */
    virtual const std::vector<std::shared_ptr<IObject>> play(arcade::events_e
    ) = 0;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    virtual const std::string &getName() const = 0;
    /**
     * @brief check if the game if lost
     * 
     * @return true 
     * @return false 
     */
    virtual bool isLost() = 0;
};
}

extern "C" std::string getType();

