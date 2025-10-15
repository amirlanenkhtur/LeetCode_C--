#include <iostream>
using namespace std;
int Reverse(int x);
int main(){
    int num = 1563847412;
    cout << Reverse(num);
}

int Reverse(int x) {
        int reversedInt = 0, digit = 0;

        while(x/10 != 0){
            digit = x%10;
            x = x/10;
            reversedInt = reversedInt*10 + digit;
        }

        if (((2147483637-x)/10+1 < reversedInt) || ((-2147483638 - x)/10 - 1 > reversedInt)){
            return 0;
        }

        reversedInt = reversedInt*10 + x;
        return reversedInt;
    }