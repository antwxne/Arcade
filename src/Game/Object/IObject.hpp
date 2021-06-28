/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <vector>
#include <memory>
#include "Graphic/IDrawable.hpp"

/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief Objects interface
 * @class IObject
 * 
 */
class IObject {
public:
    /**
     * @brief Destroy the IObject object
     * 
     */
    virtual ~IObject() = default;
    /**
     * @brief Get the Position object
     * 
     * @return const std::pair<int, int> 
     */
    virtual const std::pair<int, int> getPosition() const = 0;
    /**
     * @brief Get the Drawables object
     * 
     * @return const std::vector<std::shared_ptr<IDrawable>> 
     */
    virtual const std::vector<std::shared_ptr<IDrawable>> getDrawables() const = 0;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string 
     */
    virtual const std::string getName() const = 0;
};
}