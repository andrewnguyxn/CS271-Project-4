#ifndef CUSTOMEXCEPTION_HPP
#define CUSTOMEXCEPTION_HPP

#include <iostream>
#include <exception>
#pragma once

using namespace std;

class edge_exception: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: No such edge exists.";
        }
};

class vertex_exception: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: No such vertex exists.";
        }
};

#endif