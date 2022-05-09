#include <string>
#include <vector>

using namespace std;
vector<int> visited;
int answer=0;

void dfs(vector<vector<int>> &computers,int &n,  int now_i)
{
    visited[now_i]=1;
    
    for(int j=0;j<n;j++)
    {
        if(now_i==j)
            continue;
        if(!visited[j]&&computers[now_i][j])
            dfs(computers,n,j);
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    visited.resize(n);
    visited.assign(n,0);
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            answer++;
            dfs(computers,n,i);
        }
    }
    return answer;
}