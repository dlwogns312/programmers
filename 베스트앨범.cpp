#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> music;
    map<string,map<int,int>> mlist;
    
    for(int i=0;i<genres.size();i++)
    {
        music[genres[i]]+=plays[i];
        mlist[genres[i]][i]=plays[i];
    }
    
    while(music.size()>0)
    {
        string temp;
        int max=0;
        for(auto it:music)
        {
            if(max<it.second)
            {
                max=it.second;
                temp=it.first;
            }
            
        }
        for(int i=0;i<2;i++)
        {
            int val=0,ret=-1;
            
            for(auto it:mlist[temp])
            {
                if(val<it.second)
                {
                    val=it.second;
                    ret=it.first;
                }
            }
            
            if(ret==-1)
                break;
            answer.push_back(ret);
            mlist[temp].erase(ret);
        }
        music.erase(temp);
    }
    return answer;
}