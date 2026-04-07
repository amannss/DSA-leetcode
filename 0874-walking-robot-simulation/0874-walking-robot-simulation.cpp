class Solution {
public:
    

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int i=0 , j=0 ;
        set<pair<int,int>> st ;
        pair<int ,int> dir = {0, 1 } ; 
        for(int i=0;i<obstacles.size() ;i++)
        {
            int u = obstacles[i][0] ;
            int v = obstacles[i][1] ;
            st.insert({u,v}) ;
        }
        int ans = 0 ;
        for(int k=0;k<commands.size() ; k++)
        {
            if(commands[k] == -2 ) // turn left 
            {
                dir = { -dir.second , dir.first } ;
            }
            else if(commands[k] == -1)
            {
                dir = { dir.second , -dir.first } ;
            }
            else
            {
                int nums  = commands[k] ; 
                while(nums--)
                {
                    int newi = i+ dir.first ;
                    int newj = j+ dir.second ;
                    if(st.find({newi,newj}) != st.end() ) break ;
                    i+= dir.first ;
                    j+= dir.second ;
                }
            }
                    ans = max(ans , i*i + j*j ) ;
        }
        return ans ;
    }
};