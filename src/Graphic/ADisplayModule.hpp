/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <string>
#include "IDisplayModule.hpp"

/**
 * @brief arcade's objects
 * @class arcade
 * 
 */
namespace arcade {
/**
 * @brief abstraction for display module
 * @class ADisplayModule
 * 
 */
class ADisplayModule : public arcade::IDisplayModule {
public:
    /**
     * @brief Construct a new ADisplayModule object
     * 
     * @param name 
     */
    ADisplayModule(const std::string &name);
    /**
     * @brief Get the Name object
     * 
     * @return const std::string& 
     */
    virtual const std::string &getName() const;

protected:
    /**
     * @brief module's name
     * 
     */
    std::string _name;
};
}
