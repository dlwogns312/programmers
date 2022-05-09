#include <string>
#include <vector>

using namespace std;
int answer=0;
int num_size,target;
vector <int> numbers;

void dfs(int now_size,int now_result)
{
    if(now_size>=num_size)
    {
        if(now_result==target)
            answer++;
        return;
    }
    
    dfs(now_size+1,now_result+ numbers[now_size]);
    dfs(now_size+1,now_result+(-1)*numbers[now_size]);
    
    return;
}
int solution(vector<int> _numbers, int _target) {
    numbers=_numbers;
    target=_target;
    num_size=_numbers.size();
    
    dfs(0,0);
    return answer;
}