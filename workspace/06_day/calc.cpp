#include <iostream>
#include <cmath>

int sub();
int sub2();
int sub3();

int main() 
{
    int a = 7, b = 3;
    int sum = a + b; // a와 b를 더한 값을 sum에 대입. 미리 값을 저장해두느 습관 기르기
    printf("sum = %d\n", sum); // printf는 c언어에서 사용되는 출력함수. c++에서는 std::cout을 사용
    std::cout << "a + b = " << sum << std::endl;

    float c = 98, d = 3.14;
    float sum2 = c + d;
    std::cout << "c + d = " << sum2 << std::endl;
    float diff = c - d;
    std::cout << "c - d = " << diff << std::endl;
    float product = c * d;
    std::cout << "c * d = " << product << std::endl;
    float quotient = c / d;
    std::cout << "c / d = " << quotient << std::endl;

    int count = 3247;
    count += 50; //100에 50을 더한 값을 count에 대입
    std::cout << "count: " << count << std::endl;
    count -= 50; //100에 50을 뺀 값을 count에 대입
    std::cout << "count: " << count << std::endl;


    sub(); // sub() 함수를 호출하여 실행
    sub2(); // sub2() 함수를 호출하여 실행
    sub3(); // sub3() 함수를 호출하여 실행

    return 0;

}

int sub()
{
    double batteryVoltage = 3.7;
    bool lidar_isOn = true, imu_isOn = true;
    std::cout << "battey < 50 = " << std::boolalpha << (batteryVoltage < 50) << std::endl; // std::boolalpha를 사용하면 true, false로 출력됨

    return 0;

}

int sub2() {
    int number = 0;
    while (1){
        std::cout << "Hello, World!:  " << number << std::endl;
        number++;
        if (number > 10) {
             break; // number가 10보다 크면 while문을 빠져나감
        }
    }
    return 0;
}
