/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include "IObject.hpp"
/**
 * @brief arcade's objects
 * @namespace arcade
 * 
 */
namespace arcade {
/**
 * @brief objects that can't move
 * @class StaticObject
 * 
 */
class StaticObject : public IObject {
public:
    /**
     * @brief Construct a new Static Object object
     * 
     */
    StaticObject(const std::string &,
        const std::vector<std::shared_ptr<IDrawable>> &, std::pair<int, int>
    );
    /**
     * @brief Destroy the Static Object object
     * 
     */
    ~StaticObject() = default;
    /**
     * @brief Set the Drawables object
     * 
     */
    void setDrawables(std::vector<std::shared_ptr<IDrawable>>);
    /**
     * @brief Set the Name object
     * 
     */
    void setName(std::string &);
    /**
     * @brief Get the Position object
     * 
     * @return const std::pair<int, int> 
     */
    const std::pair<int, int> getPosition() const override;
    /**
     * @brief Get the Drawables object
     * 
     * @return const std::vector<std::shared_ptr<IDrawable>> 
     */
    const std::vector<std::shared_ptr<IDrawable>> getDrawables() const override;
    /**
     * @brief Get the Name object
     * 
     * @return const std::string 
     */
    const std::string getName() const override;

protected:
    /**
     * @brief object name
     * 
     */
    std::string _name;
    /**
     * @brief drawables associated to the object
     * 
     */
    std::vector<std::shared_ptr<IDrawable>> _drawables;
    /**
     * @brief position
     * 
     */
    std::pair<int, int> _position;
};
}