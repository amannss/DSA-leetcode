class Solution {
public:
    int mm;

    string solve(int i, int j, int eachgadhaspace, int extragadhaspace,
                 vector<string>& words, bool lastLine)
    {
        string line = "";

        if(lastLine)
        {
            for(int k = i; k < j; k++)
            {
                line += words[k];
                if(k != j - 1)
                    line += " ";
            }

            while(line.length() < mm)
                line += " ";

            return line;
        }

        for(int k = i; k < j; k++)
        {
            line += words[k];

            if(k != j - 1)
            {
                for(int z = 0; z < eachgadhaspace; z++)
                    line += " ";

                if(extragadhaspace > 0)
                {
                    line += " ";
                    extragadhaspace--;
                }
            }
        }

        while(line.length() < mm)
            line += " ";

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        mm = maxWidth;
        int n = words.size();

        vector<string> result;

        int i = 0;

        while(i < n)
        {
            int j = i + 1;
            int gadhe = 0;
            int lettercount = words[i].length();

            while(j < n &&
                  lettercount + words[j].length() + gadhe + 1 <= maxWidth)
            {
                lettercount += words[j].length();
                gadhe++;
                j++;
            }

            int remainingspace = maxWidth - lettercount;

            int eachgadhaspace, extragadhaspace;

            if(gadhe == 0)
            {
                eachgadhaspace = 0;
                extragadhaspace = 0;
            }
            else
            {
                eachgadhaspace = remainingspace / gadhe;
                extragadhaspace = remainingspace % gadhe;
            }

            bool lastLine = (j == n);

            result.push_back(
                solve(i, j, eachgadhaspace, extragadhaspace, words, lastLine)
            );

            i = j;
        }

        return result;
    }
};