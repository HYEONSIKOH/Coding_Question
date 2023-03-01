#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    string str;
    cin >> str;

    if (N <= 25) {
        cout << str;
        return 0;
    }
    
    bool sentence = true;

    for (int i = 11; i < N - 12; i++) {
        if (str[i] == '.'){
            sentence = false;
            i = N - 10;
        }
    }

    if (sentence) {
        for (int i = 0; i < 11; i++) cout << str[i];
        cout << "...";
        for (int i = N - 11; i < N; i++ ) cout << str[i];
    }
    else {
        for (int i = 0; i < 9; i++) cout << str[i];
        cout << "......";
        for (int i = N - 10; i < N; i++ ) cout << str[i];
    }
    
    return 0;
}