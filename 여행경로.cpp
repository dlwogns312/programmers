#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> answer;
vector<int>used;
vector<string>temp;
int n;

void dfs(string now, vector<vector<string>> &tickets,int num)
{
    if(num==n)
    {
        if(answer.empty())
            answer=temp;
        else
            answer=min(answer,temp);
        return;
    }    
    
    for(int i=0;i<n;i++)
    {
        if(tickets[i][0]==now&&!used[i])
        {
            used[i]=1;
            temp.push_back(tickets[i][1]);
            dfs(tickets[i][1],tickets,num+1);
            used[i]=0;
            temp.pop_back();
        }
    }
    
    return;
    
}

vector<string> solution(vector<vector<string>> tickets) {
    n=tickets.size();
    used.resize(n);
    used.assign(n,0);
    temp.push_back("ICN");
    
    dfs("ICN",tickets,0);

    return answer;
}