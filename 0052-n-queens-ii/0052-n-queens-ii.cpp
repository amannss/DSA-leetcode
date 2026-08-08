class Solution {
public:
    bool isSafe(int row ,int col ,vector<string>&board)
    {   
        int n = board.size() ;
        int r = row ;int c = col ;
        // check left up  diagonal
        while(r>=0 && c>=0)
        {
            if(board[r][c] == 'Q') return false ;
            r-- ;c-- ;
        }
        r = row ; c= col ;
        // check left horizontal 
        while(c>= 0)
        {
            if(board[r][c]=='Q') return false ;
            c-- ;
        }
        r = row ; c = col ;
        // check left down diagonal
        while(c>= 0 && r<n)
        {
            if(board[r][c] == 'Q') return false ;
            c-- ; r++ ;
        }
        return true ; 

    }
    void solve(int col , vector<vector<string>>&result , vector<string> board)
    {   
        int n = board.size() ;
        if(col == n)
        {
            result.push_back(board) ;
            return ;
        }
        for(int row = 0 ;row < n ;row++)
        {
            
            if(isSafe(row , col, board)) 
            {   
                board[row][col] = 'Q' ;
                solve(col+1 , result ,board) ;
                board[row][col] = '.' ;
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result ;
        string s(n ,'.') ;
        vector<string> board(n) ;
        for(int i = 0 ; i< n;i++) board[i] = s ;
        solve(0 , result , board) ;
        return result ;
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans = solveNQueens(n) ;
        return ans.size() ;
    }
};