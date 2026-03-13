class Solution {
public:

bool solve(int h , vector<int>& vec , long long second )
{
    long long cnt = 0 ;
    int n = vec.size() ;

    for(int i=0;i<n;i++)
    {   
        long long tempsecond = 0 ;
        int j = 1;

        while(tempsecond + (long long)j * vec[i] <= second)
        {
            tempsecond += (long long)j * vec[i];
            j++;
        }

        cnt += j - 1;

        if(cnt >= h) return true ;
    }

    return false ;
}

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

    long long l = 1 ;

    long long minimum = *min_element(workerTimes.begin() , workerTimes.end()) ;

    long long h = minimum * (1LL * mountainHeight * (mountainHeight +1 ) / 2) ;

    long long ans = h ;

    while(l <= h)
    {
        long long mid = (l + h) /2 ;

        if(solve(mountainHeight , workerTimes , mid ))
        {
            ans = mid ;
            h = mid -1 ;
        }
        else 
            l = mid + 1;
    }

    return ans ;
}
};