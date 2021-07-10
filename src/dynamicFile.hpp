/*
** EPITECH PROJECT, 2021
** dynamicFile.hpp.h
** File description:
** dynamicFile.hpp.h
*/

#pragma once

#include <string>
/**
 * @brief DynamicFile
 * @class DynamicFile
 * 
 */
class DynamicFile {
public:
    /**
     * @brief Construct a new Dynamic File object
     * 
     */
    DynamicFile();
    /**
     * @brief Destroy the Dynamic File object
     * 
     */
    ~DynamicFile();
    /**
     * @brief 
     * 
     * @param s args
     */
    void VerifyArg(std::string &s) const;
};
