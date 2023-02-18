// 프로그래머스 120896 [문자열] 한 번만 등장한 문자
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> vec(27);
    
    for (int i = 0; i<s.length(); i++) vec[s[i] - 'a']++;
    
    for (int i = 0; i < 27; i++) if (vec[i] == 1) answer += ('a' + i);
    
    return answer;
}