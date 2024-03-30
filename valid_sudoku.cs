public class Solution {
    public bool IsValidSudoku(char[][] board) {
        // hashmaps for each cols, rows, grids
        var rows = new Dictionary<int, HashSet<char>>();
        var cols = new Dictionary<int, HashSet<char>>();
        var squares = new Dictionary<(int, int), HashSet<char>>();
    
        // iterate through the whole board
        for(int r = 0; r < 9; r++){
            rows[r] = new HashSet<char>();
            for(int c = 0; c < 9; c++){
                if(!cols.ContainsKey(c)) cols[c] = new HashSet<char>();
                if(!squares.ContainsKey((r/3, c/3))) squares[(r/3, c/3)] = new HashSet<char>();
                
                // if dupli values present in the hashmaps
                if(rows[r].Contains(board[r][c]) || 
                    cols[c].Contains(board[r][c]) ||
                    squares[(r/3, c/3)].Contains(board[r][c])
                )
                return false;

                // for empty chars
                if(board[r][c] == '.') continue;

                // add values to the map
                rows[r].Add(board[r][c]);
                cols[c].Add(board[r][c]);
                squares[(r/3, c/3)].Add(board[r][c]);
            }
            
        }
        return true;
    
    }
}

// TC: O(n^2) as accessing and adding to hashmap takes only O(1)
// SC: for r: O(n), for c: O(n), for squares: O(n): Total 3*O(n) or O(n) 