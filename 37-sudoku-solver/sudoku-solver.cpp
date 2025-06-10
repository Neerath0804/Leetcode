class Solution {
public:
bool isSafe(vector<vector<char>> &board,int row,int col,char dig)
{
    //horizantally
    for(int i = 0; i < 9;i++)
    {
        if(board[row][i] == dig)
        {
            return false;
        }
    }

    //vertically
    for(int j = 0; j<9;j++)
    {
        if(board[j][col] == dig)
        {
            return false;
        }
    }

    //grid
    int strow = (row/3) * 3;
    int stcol = (col/3) * 3;
    for(int i = strow; i<= strow+2 ; i++)
    {
        for(int j = stcol; j <= stcol+2; j++)
        {
            if(board[i][j] == dig)
            return false;
        }
    }
    return true;
}
bool helper(vector<vector<char>> &board,int row,int col)
{
    if(row == 9)
    {
        return true;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if(nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    if(board[row][col] != '.')
    {
        return helper(board,nextRow,nextCol);
    }

    //digits
    for(char dig = '1'; dig<= '9'; dig++)
    {
        if(isSafe(board,row,col,dig))
        {
            board[row][col] = dig;
            if(helper(board,nextRow,nextCol))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};