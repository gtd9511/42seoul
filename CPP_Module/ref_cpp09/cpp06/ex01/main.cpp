#include "Serializer.hpp"

int main(){
    Data * originalData = new Data(19, "ebang");
    std::cout << "originalData: " << originalData << std::endl;
    Serializer S;
    uintptr_t serializedData = S.serialize(originalData);
    std::cout << "serializedData: " << serializedData << std::endl;
    Data *deserializedData = S.deserialize(serializedData);
    std::cout << "deserializedData: " << deserializedData << std::endl;
    if(deserializedData == originalData)
        std::cout << "serialization test successful.\n";
    else
        std::cout << "serialization test failed.\n";
    
    delete originalData;

}