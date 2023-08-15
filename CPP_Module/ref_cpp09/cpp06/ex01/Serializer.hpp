#pragma once
#ifndef Serializer_HPP
# define Serializer_HPP
#include <iostream>

struct Data{
  int age;
  std::string name;

  Data(int age, std::string name): age(age), name(name) {};
};

class Serializer
{
private:
        
public:
        Serializer();
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& copy);
        ~Serializer();

        uintptr_t serialize(Data* ptr); 
        Data* deserialize(uintptr_t raw);

};

#endif // Serializer_HPP