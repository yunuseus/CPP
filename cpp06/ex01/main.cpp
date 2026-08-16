#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    std::cout << "===== Exercise 01: Serialization Test =====" << std::endl;

    Data data1;
    data1.id = 42;
    data1.name = "42 Student Project";
    data1.value = 3.14159;
    data1.active = true;

    std::cout << "\n[Original Data Object]" << std::endl;
    std::cout << "Address: " << &data1 << std::endl;
    std::cout << "ID:      " << data1.id << std::endl;
    std::cout << "Name:    " << data1.name << std::endl;
    std::cout << "Value:   " << data1.value << std::endl;
    std::cout << "Active:  " << (data1.active ? "true" : "false") << std::endl;

    uintptr_t raw = Serializer::serialize(&data1);
    std::cout << "\n[Serialized Value]" << std::endl;
    std::cout << "Raw uintptr_t (dec): " << raw << std::endl;
    std::cout << "Raw uintptr_t (hex): 0x" << std::hex << raw << std::dec << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "\n[Deserialized Data Pointer]" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID:      " << deserialized->id << std::endl;
    std::cout << "Name:    " << deserialized->name << std::endl;
    std::cout << "Value:   " << deserialized->value << std::endl;
    std::cout << "Active:  " << (deserialized->active ? "true" : "false") << std::endl;

    std::cout << "\n[Verification]" << std::endl;
    if (deserialized == &data1) {
        std::cout << "SUCCESS: deserialized pointer matches original pointer!" << std::endl;
    } else {
        std::cout << "FAILURE: pointers do not match!" << std::endl;
    }

    if (deserialized->id == data1.id &&
        deserialized->name == data1.name &&
        deserialized->value == data1.value &&
        deserialized->active == data1.active) {
        std::cout << "SUCCESS: all data members match perfectly!" << std::endl;
    } else {
        std::cout << "FAILURE: data corrupted during serialization!" << std::endl;
    }

    return 0;
}
