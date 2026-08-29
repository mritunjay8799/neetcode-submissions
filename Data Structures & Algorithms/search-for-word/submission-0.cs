public class Solution {
    public bool Exist(char[][] board, string word) {
        int rows = board.Length;
        int cols = board[0].Length;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(backtrack(r, c, 0, ref board, ref word))
                    return true;
            }
        }
        return false;
    }

    public bool backtrack(int row, int col, int idx, ref char[][] board, ref string word)
    {
        if(idx == word.Length)
            return true;

        int rows = board.Length;
        int cols = board[0].Length;

        if(row < 0 || row >= rows || col < 0 || col >= cols || idx >= word.Length || board[row][col] != word[idx])
                return false;
        char temp = board[row][col];
        board[row][col] = '#';
        bool validPath = backtrack(row+1, col, idx+1, ref board, ref word) 
                      || backtrack(row-1, col, idx+1, ref board, ref word) 
                      || backtrack(row, col+1, idx+1, ref board, ref word)
                      || backtrack(row, col-1, idx+1, ref board, ref word);
        board[row][col] = temp;
        return validPath;     
    }
}
