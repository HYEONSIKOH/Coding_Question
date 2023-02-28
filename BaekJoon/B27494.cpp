#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int N, ans = 0;
    int A = 0;
    string year = "2023";
    cin >> N;

    if (N < 2023) {
        cout << 0;
        return 0;
    }

    for (int I = 2023; I <= N; I++) {
        string str = to_string(I);
        int len = str.length();
        int cnt = 0;
        int idx = 0;

        for (int i = 0; i < len; i++) {
            if (str[i] == year[idx]) idx ++;
            else cnt++;

            if (cnt == 5) i = len + 1;
            else if (cnt < 5 && idx == 4){
                i = len + 1;
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}