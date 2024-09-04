#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

struct mathVec {
    double x;
    double y;
};
bool answerCheck(const std::string& answer) {
    return (answer == "add" || answer == "sub" || answer == "scale" || answer == "length" || answer == "norm");
}

void addOper(mathVec& v1, mathVec& v2, mathVec& result) {
    std::cout << "Please input values x and y for first vector: " << std::endl;
    std::cin >> v1.x >> v1.y;
    std::cout << "Please input values x and y for second vector: " << std::endl;
    std::cin >> v2.x >> v2.y;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    std::cout << "(" << result.x << ", " << result.y << ")" << std::endl;
}
void subOper(mathVec& v1, mathVec& v2, mathVec& result) {
    std::cout << "Please input values x and y for first vector: " << std::endl;
    std::cin >> v1.x >> v1.y;
    std::cout << "Please input values x and y for second vector: " << std::endl;
    std::cin >> v2.x >> v2.y;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    std::cout << "(" << result.x << ", " << result.y << ")" << std::endl;
}
void scaleOper(mathVec& v1, mathVec& result) {
    double scale;
    std::cout << "Please, input scale size: " << std::endl;
    std::cin >> scale;
    std::cout << "Please input values x and y for vector: " << std::endl;
    std::cin >> v1.x >> v1.y;
    result.x = (scale * v1.x);
    result.y = (scale * v1.y);
    std::cout << "(" << result.x << ", " << result.y << ")" << std::endl;
}
double lenOper(mathVec& v1) {
    double length = 0.0;
    length = std::sqrt(v1.x * v1.x + v1.y * v1.y);
    std::cout << "length of vector is (" << length << ")" << std::endl;
    return length;
}
void normOper(mathVec& v1, mathVec& result) {
    double length = lenOper(v1);
    result.x = v1.x / length;
    result.y = v1.y / length;
    std::cout << "(" << result.x << ", " << result.y << ")" << std::endl;
}

int main()
{
    mathVec result = { 0, 0 };
    mathVec v1 = { 0, 0 };
    mathVec v2 = { 0, 0 };

    std::string answer;
    std::cout << "Hello. This is commands to do:" << "\n" << "(add-addition, sub-substraction, scale-multiplication,"
        "length-to found lengthm,norm-normalize or q-to exit porgramm)" << std::endl;


    while (answer != "q") {
        std::cout << "Type a command:";
        std::cin >> answer;
        if (answer == "q") {
            std::cout << "Finishing programm.";
            break;
        }
        while (!answerCheck(answer)) {
            std::cerr << "Wrong comman! Input again" << std::endl;
            std::cin >> answer;
        }
        if (answer == "add") {
            addOper(v1, v2, result);
        }

        else if (answer == "sub") {
            subOper(v1, v2, result);
        }
        else if (answer == "scale") {
            scaleOper(v1, result);
        }
        else if (answer == "length") {
            std::cout << "Please input values x and y for vector: " << std::endl;
            std::cin >> v1.x >> v1.y;
            lenOper(v1);
        }
        else if (answer == "norm") {
            std::cout << "Please input values x and y for vector: " << std::endl;
            std::cin >> v1.x >> v1.y;
            normOper(v1, result);
        }
    }


    return  0;
}