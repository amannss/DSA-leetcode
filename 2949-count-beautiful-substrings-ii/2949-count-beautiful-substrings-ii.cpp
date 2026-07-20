class Solution {
public:
    bool isvowel(char ch)
    {
        return ch=='a' || ch=='e' ||   ch=='i' ||  ch=='o' || ch=='u' ;
    }
    #define ll long long 
    
    long long beautifulSubstrings(string s, int k)
    {
        ll vowel=0;
        ll consonants=0;
        ll result=0;
        unordered_map<ll ,unordered_map<ll,ll>>mp;
        mp[0][0]=1;
        for(char &ch:s)
        {
            if(isvowel(ch)) vowel++;
            else consonants++;
    
           ll psum=(vowel - consonants);
           for(auto &[pastvowelcount,count] :mp[psum])
           {
              ll count_vowel=vowel;
              ll past_vowel=pastvowelcount;
              ll curr_sub_vowel_count=count_vowel - past_vowel;
              if((vowel%k - pastvowelcount) * (vowel%k - pastvowelcount) %  k ==0)
              {
                result+=count;
              }
           }
           mp[psum][vowel%k]++;
        }
        return result;
    }
    
};