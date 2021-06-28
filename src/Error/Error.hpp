/*
** EPITECH PROJECT, 2021
** Error.hpp.h
** File description:
** Error.hpp.h
*/

#pragma once

#include <exception>
#include <string>
/**
 * @brief error class
 * @class Error
 * 
 */
class Error : public std::exception {
public:
    /**
     * @brief Construct a new Error object
     * 
     * @param txt 
     */
    Error(const std::string txt) throw();
    /**
     * @brief Destroy the Error object
     * 
     */
    virtual ~Error() throw();
    /**
     * @brief what error appened
     * 
     * @return const char* 
     */
    const char *what() const throw();

private:
    /**
     * @brief error's description
     * 
     */
    std::string _description;
};
