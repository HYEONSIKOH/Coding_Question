#include <string>
#include <vector>
#include <cmath>
using namespace std;

string change_bin (int a) {
    string str = "";

    if (!a) return "0";
    
    while (a) {
        str += a % 2 ? "1" : "0";
        a /= 2;
    }
    
    string str2 = "";
    for (int i = str.length() - 1; i >= 0; i--) str2 += str[i];
    
    return str2;
}

string solution(string bin1, string bin2) {
    
    int bin1_len = bin1.length();
    int bin2_len = bin2.length();
    
    int bin1_int = 0;
    int bin2_int = 0;
    
    int cnt = 0;
    for (int i = bin1_len - 1; i >= 0; i--) {
        if (bin1[i] == '1') bin1_int += pow(2, cnt);
        cnt++;
    }
    
    cnt = 0;
    for (int i = bin2_len - 1; i >= 0; i--) {
        if (bin2[i] == '1') bin2_int += pow(2, cnt);
        cnt++;
    }
    
    return change_bin(bin1_int + bin2_int);
}