#include<poly/poly.h>
#include<iostream>
#include<sstream>
int main()
{ 
    // begin
    int comand;
    int grade;
    Poly first;
    Poly temp;
    Poly z = Poly();
    std::cout << "Enter the polynom" << std::endl;
    std::cin >> first;
    std::cout << "====================================" << std::endl;
    std::cout << first ;
    std::cout << "====================================" << std::endl;
    // firts
    std::cout << "Choose operation" << std::endl;
    std::cout << "1 - plus  by smth" << std::endl;
    std::cout << "2 - minus by smth" << std::endl;
    std::cout << "3 - myltiply by smth" << std::endl;
    std::cout << "4 - division my by smth" << std::endl;
    std::cout << "5 - grade up" << std::endl;
    std::cout << "6 - get rank" << std::endl;
    std::cout << "7 - get routs" << std::endl;
    std::cout << "0 - stop" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cin >> comand;
    while (comand != 0)
    {
        switch (comand)
        {
        case 1:
            std::cout << "Enter the polynom" << std::endl;
            std::cin >> temp;
            first += temp;
            std::cout << "====================================" << std::endl;
            std::cout << "Result" << std::endl;
            std::cout << first;
            temp.~Poly();
            break;
        case 2:
            std::cout << "Enter the polynom" << std::endl;
            std::cin >> temp;
            first -= temp;
            std::cout << "====================================" << std::endl;
            std::cout << "Result" << std::endl;
            std::cout << first;
            temp.~Poly();
            break;
        case 3:
            std::cout << "Enter the polynom" << std::endl;
            std::cin >> temp;
            first *= temp;
            std::cout << "====================================" << std::endl;
            std::cout << "Result" << std::endl;
            std::cout << first;
            temp.~Poly();
            break;
        case 4:
            std::cout << "Enter the polynom" << std::endl;
            std::cin >> temp;
            first /= temp;
            std::cout << "====================================" << std::endl;
            std::cout << "Result" << std::endl;
            std::cout << first;
            temp.~Poly();
            break;
        case 5:
            std::cout << "Enter the grade" << std::endl;
            std::cin >> grade;
            first.GradeUp(grade);
            std::cout << "====================================" << std::endl;
            std::cout << "Result" << std::endl;
            std::cout << first;
            grade = 0;
            break;
        case 6:
            std::cout << "====================================" << std::endl;
            std::cout << "Result" << std::endl;
            std::cout << first.GetRank() << std::endl;
            break;
        case 7:
            std::cout << "====================================" << std::endl;
            std::cout << "Result" << std::endl;
            z=first;
            z.PrintSolve(); std::cout << std::endl;
            break;
        }
        std::cout << "====================================" << std::endl;
        std::cout << "1 - plus  by smth" << std::endl;
        std::cout << "2 - minus by smth" << std::endl;
        std::cout << "3 - myltiply by smth" << std::endl;
        std::cout << "4 - division my by smth" << std::endl;
        std::cout << "5 - grade up" << std::endl;
        std::cout << "6 - get rank" << std::endl;
        std::cout << "7 - get routs" << std::endl;
        std::cout << "0 - stop" << std::endl;
        std::cout << "====================================" << std::endl;
        std::cin >> comand;
    }
    system("pause");
}
