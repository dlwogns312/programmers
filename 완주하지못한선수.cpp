#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    string answer = "";
    int i, j;
    for (i = 0, j = 0; j < completion.size(); i++, j++)
    {
        if (participant[i] != completion[j])
        {
            answer = participant[i];
            break;
        }
    }
    if (answer == "")
        answer = participant[i];
    return answer;
}