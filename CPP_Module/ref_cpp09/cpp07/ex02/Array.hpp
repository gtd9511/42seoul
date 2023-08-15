#pragma once
#ifndef Array_HPP
# define Array_HPP
#include <iostream>

template <typename T>
class Array {
private:
    T *elements;
    unsigned int len;

public:

    Array() : len(0){
        this->elements = new T[len];
        std::cout << "Array default constructor called.\n";
    };

    Array(unsigned int n) : len(n) {
        this->elements = new T[n];
        std::cout << "Array parameter constructor called.\n";
    };

    Array(const Array &copy) : len(copy.size()){
        this->elements = new T[copy.size()];
        for(unsigned int i = 0; i < copy.size(); i++){
            this->elements[i] = copy.elements[i];
        }
        std::cout << "Array copy constructor called.\n";
    };

    Array &operator=(const Array &copy){
        
        if(this != &copy)
        {
            if(this->elements)
               delete this->elements;
            this->len = copy.size();
            this->elements = new T[this->len];
            for(unsigned int  i = 0; i < copy.size(); i++){
                this->elements[i] = copy.elements[i];
            }    
        }
        std::cout << "Array copy operator called.\n";
        return *this;
    };

    ~Array(){
        if(this->elements)
            delete []this->elements;
        this->elements = NULL;
        this->len = 0;
        std::cout << "Array default destructor called.\n";
    };

    size_t size() const{
        return this->len;
    };

    T &operator[](unsigned int idx) {
        if(idx < 0 || idx >= this->len){
            throw OutOfBoundException();
        }
        return elements[idx];
    };

    const T &operator[](unsigned int idx) const {
        std::cout << "operator[] with const \n";
        if(idx >= this->len){
            throw OutOfBoundException();
        }
        return elements[idx];
    };

    class OutOfBoundException: public std::exception{
                virtual const char *what(void) const throw(){
                    return "Error: invalid index\n";
                }
    };
};

#endif // Array_HPP