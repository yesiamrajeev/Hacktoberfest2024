#include <string>
#include <iostream>
using namespace std;

string toHex(int num) {
    if (num == 0) return "0";

    string hexStr;
    string hexChars = "0123456789abcdef";
    for (int i = 0; num != 0 && i < 8; i++) {
        hexStr = hexChars[num & 0xf] + hexStr;  
        num >>= 4;  
    }

    return hexStr;
}

int main() {
    int num1 = 26;
    int num2 = -1;

    cout << "Hexadecimal of " << num1 << " is: " << toHex(num1) << endl;
    cout << "Hexadecimal of " << num2 << " is: " << toHex(num2) << endl;

    return 0;
}
