/*
** EPITECH PROJECT, 2021
** LoadLib.hpp.h
** File description:
** LoadLib.hpp.h
*/

#pragma once

#include <string>
#include <iostream>
#include <dlfcn.h>
#include <exception>
#include <functional>
#include <type_traits>
#include <iterator>
#include <vector>

/**
 * @brief load .so file
 * @class LoadLib
 * 
 */
class LoadLib {
public:
    /**
     * @brief Construct a new Load Lib object
     * 
     */
    LoadLib() = default;
    /**
     * @brief Destroy the Load Lib object
     * 
     */
    ~LoadLib() = default;
    /**
     * @brief open .so
     * 
     * @param libName 
     */
    void initHandler(const std::string &libName);
    /**
     * @brief close .so file
     * 
     */
    void destroyOpenFile();
    /**
     * @brief load symbols
     * 
     * @tparam T template
     * @param functionName 
     * @return std::function<T> 
     */
    template<typename T>
    std::function<T> loadingLib(const std::string &functionName) const
    {

        T *p = (T *)(dlsym(_openFile[(_openFile.size() - 1)],
            functionName.c_str()));
        if (!p)
            throw std::runtime_error(dlerror());
        return std::function<T>(p);
    }

private:
    /**
     * @brief store handlers
     * 
     */
    std::vector<void *> _openFile;
};
