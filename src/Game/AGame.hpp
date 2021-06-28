/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include "IGame.hpp"
#include "Object/IObject.hpp"
/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
    /**
     * @brief abstract class for games
     * @class AGame
     * 
     */
    class AGame: public IGame {
    public:
        /**
         * @brief Construct a new AGame object
         * 
         * @param name 
         */
        AGame(std::string const &name);
        /**
         * @brief Destroy the AGame object
         * 
         */
        virtual ~AGame();

    protected:
        /**
         * @brief player's position
         * 
         */
        std::pair<float, float> _playerPosition;
        /**
         * @brief objects needed to be displayed
         * 
         */
        std::vector<std::shared_ptr<IObject>> _objects;
        /**
         * @brief game's name
         * 
         */
        std::string _name;
    };
}
