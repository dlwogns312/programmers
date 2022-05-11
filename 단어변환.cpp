#include <string>
#include <vector>

using namespace std;
vector<int> visited;
int n;
int answer;

int check(string a, string b)
{
    int cnt=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
            cnt++;
        if(cnt>1)
            break;
    }
    return cnt;
}

void dfs(string begin, string target, vector<string> &words,int now)
{
    if(begin==target)
    {
        answer=min(answer,now);
        return;
    }
    if(now>answer)
        return;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&words[i]!=begin&&check(begin,words[i])==1)
        {
            visited[i]=1;
            dfs(words[i],target,words,now+1);
            visited[i]=0;
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    n=words.size();
    visited.resize(n);
    visited.assign(n,0);
    answer=9999;
    
    dfs(begin,target,words,0);
    
    if(answer==9999)
        answer=0;
    return answer;
}