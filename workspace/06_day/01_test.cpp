#include <iostream>
#include <string>

int sub();
int sub2();
int sub3();

int main()
{
   short count = 10;    // 음수도 바로 입력하면 가능
   int num = 98;        
   unsigned int unum = 98; // 음수는 바로 입력 불가. 언제 사용하나??
   
   std::cout << "count: " << count << std::endl;
   std::cout << "num: " << num << std::endl;
   std::cout << "unum: " << unum << std::endl;  

   float fnumber = 3.14f; // float형은 뒤에 f를 붙여야 함
   double dnumber = 2.718281828459045; // double형은 뒤에 f를 붙이지 않아도 됨
   long double ldnumber = 3.14L; // long double형은 뒤에 L을 붙여야 함
   std::cout << "fnumber: " << fnumber << std::endl;  
   std::cout << "dnumber: " << dnumber << std::endl;
   std::cout << "ldnumber: " << ldnumber << std::endl;

   bool robotstate = true; // true, false
   char sensor = 'A';
   std::string message = "Hello, World!"; // 문자열은 큰따옴표로 묶어야 함

   std::cout << "robotstate: " << robotstate << std::endl;
   std::cout << "sensor: " << sensor << std::endl;
   std::cout << "message: " << message << std::endl;

   int array[7] = {1, 2, 3, 4, 5, 6, 7}; // 배열은 중괄호로 초기화 길이를 먼저 정하고, 요소들의 값을 중괄호로 묶어 초기화
   std::cout << "Array Size: " << array[0] << ", " << array[1] << ", " << array[2] << ", " << array[3] << ", " << array[4] << ", " << array[5] << ", " << array[6] << std::endl;

   std::cout << "array: ";
   for(int i = 0; i < 7; i++) {
      std::cout << array[i] << " ";
   }
   std::cout << std::endl;      

   sub();
   sub2();
   sub3();
}


int sub()
{
    int batteryLevel = 40;

    std::cout << "batteryLevel: if / elseif else (battery = 100)" << batteryLevel << std::endl;

    if (batteryLevel == 100) {
        std::cout << "Battery is full." << std::endl;
    } 

    else if (batteryLevel >= 50) {
        std::cout << "Battery is more than half." << std::endl;
    } 

    else if (batteryLevel > 0) {
        std::cout << "Battery is low." << std::endl;
    }

    else {
        std::cout << "Battery is dead." << std::endl;
    }   

    return 0;
}

int sub2()
{
    char lidar_code ='F';
    std::cout << "lidar_code = ";
    switch (lidar_code) {
        case 'F':
            std::cout << "Lidar is in mode F." << std::endl;
            break;
        case 'J':
            std::cout << "Lidar is in mode J." << std::endl;
            break;
        case 'B':
            std::cout << "Lidar is in mode B." << std::endl;
            break;
        case 'C':
            std::cout << "Lidar is in mode C." << std::endl;
            break;
        default:
            break;
    }

    return 0;

}

// int sub3()
// {
//     int readings[5] = {10, 20, 30, 40, 50};
//     for (int )
// }