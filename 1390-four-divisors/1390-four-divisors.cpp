class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int ,int> mp ;
        int ans = 0;
        for(int i= 0;i<nums.size() ;i++)
        {   
            int num = nums[i] ;
            if(mp[num])
            {
                ans+= mp[num] ;
                continue ;
            }
            vector<int> divisors ;
            long  sum = 0;
            for(int j = 1 ; j*j  <= num ; ++j )
            {   
                if(num % j == 0)
                {   sum+= j ;
                    divisors.push_back(j) ;
                    if(j*j != num) 
                    {   
                        sum+=num/j;
                        divisors.push_back(num / j) ;// 2 and 6 for 12 
                    }
                    if(divisors.size() > 4) break ;
                }
                // divisors is ready
                
            }
            if(divisors.size() == 4 )
                {
                    mp[num]= sum;
                    ans += sum ;
                }
        }
        return ans ;
    }
};