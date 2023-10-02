#include <string>
#include <iostream>
#include <vector>
// #include <quanternaryConversion> // for programs that are written in binary
// quanternary operators:
// *|
// *&
// *==

// Voltage levels
// 0: 0.8V
// 1: 1.0V
// 2: 1.2V
// 3: 1.4V

using namespace std;

// Advantages of quanternary

// Disadvantages of quanternary

string quanternary_to_binary(string quanternary) {
    register string binary;
    register string bufferStr;

    for (int i = 0; i < quanternary.size(); i++) {
        bufferStr.clear();
        register char pt1 = quanternary[i] % 2;
        register char pt2 = (quanternary[i] / 2) % 2;
        bufferStr.push_back(pt1);
        bufferStr.push_back(pt2);
        binary.append(bufferStr);
    }

    return binary;
}

string binary_to_quanternary(string binary) { // 0 to 3
    string quanternary;

    register int reset = 0;
    register string bufferStr;
    register int bufferInt = 0;
    for (int i = 0; i < binary.size(); i++) {
        reset++;
        bufferStr.push_back(binary[i]);
        if (reset >= 2) {
            bufferInt = bufferStr[0] + (bufferStr[1] * 2);
            quanternary.push_back(bufferInt);
            bufferStr.clear();
            reset = 0;
        }
    }

    return quanternary;
}

int main(int argc, char *argv[]) {
    string binary = "00100111";
    string quanternary = "0123";
    for (int i = 0; i < binary.size(); i++) {
        binary[i] -= 48;
    }
    for (int i = 0; i < quanternary.size(); i++) {
        quanternary[i] -= 48;
    }
    string to_Binary = quanternary_to_binary(quanternary);
    string to_Quanternary = binary_to_quanternary(binary);

    cout << "\nBinary:";
    for (auto z : to_Binary) {
        cout << char(z + 48) << ",";
    }

    cout << "\nQuanternary:";
    for (auto z : to_Quanternary) {
        cout << char(z + 48) << ",";
    }
}