#pragma once
#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <stack>
#include <deque>
#include <vector>
#include <iostream>
#include <list>

template <typename T, typename Container = std::deque<T> > 
class MutantStack : public  std::stack<T, Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

        MutantStack() :std::stack<T, Container>(){
            std::cout << "MutantStack default constructor called.\n";
        };
        MutantStack(const MutantStack& copy) :std::stack<T, Container>(copy) {  
            std::cout << "MutantStack copy constructor called.\n";
        };
        MutantStack& operator=(const MutantStack& copy){
            std::cout << "MutantStack copy operator called.\n";
            if(this != &copy){
                std::stack<T, Container>::operator=(copy);
            }
            return *this;

        };
        ~MutantStack(){
            std::cout << "MutantStack destructor called.\n";
        };

        iterator begin(){
            return this->c.begin();
        }
        iterator end(){
            return this->c.end();
        }
        const_iterator cbegin() const{
            return this->c.begin();
        }
        const_iterator cend() const{
            return this->c.end();
        }
        reverse_iterator rbegin(){
            return this->c.rbegin();
        }
        reverse_iterator rend(){
            return this->c.rend();
        }
        const_reverse_iterator crbegin() const{
            return this->rbegin();
        }
        const_reverse_iterator rcend() const{
            return this->rend();
        }
};

#endif // MutantStack_HPP