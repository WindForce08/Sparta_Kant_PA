#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "동물 소리\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "멍멍\n";
    }
};

int main() {
    Dog dog;

    Animal* animal = &dog;

    std::cout << "dog의 주소: " << &dog << '\n';
    std::cout << "animal이 저장한 주소: " << animal << '\n';
    std::cout << "animal 포인터 변수의 주소: " << &animal << '\n';

    dog.speak();
    animal->speak();
}