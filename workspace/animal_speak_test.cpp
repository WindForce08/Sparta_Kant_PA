#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
    void speak() {
        std::cout << "동물 소리\n";
    }
};

class Dog : public Animal {
public:
    void speak() {
        std::cout << "멍멍\n";
    }
};


int main() {
    Dog dog;
    std::cout << &dog << std::endl; // Dog 객체의 주소 출력

    dog.speak(); // Dog 클래스의 speak() 메서드 호출

    Animal* animal = &dog; // Animal 클래스 포인터에 Dog 객체의 주소를 할당
    animal->speak(); 
    std::cout << &animal << std::endl; // Animal 포인터의 주소 출력
    // Animal 클래스의 speak() 메서드 호출 
    // 동적 바인딩이 아닌 정적 바인딩으로 인해 Animal 클래스의 speak() 메서드가 호출됩니다. 

    return 0;
}

// 이 코드에서는 Animal 클래스와 Dog 클래스가 정의되어 있습니다. Dog 클래스는 Animal 클래스를 상속받고 있으며, speak() 메서드를 오버라이드하고 있습니다.  

