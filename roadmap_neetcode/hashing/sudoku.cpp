//Problem: Validate Sudoku
//Soltion: use hashmaps to check if a nmber is already present in row, column or square

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            unordered_map<int, unordered_set<char>> rows;
            unordered_map<int, unordered_set<char>> columns;
            unordered_map<int, unordered_set<char>> squares;
    
            int curr_row=0;
            int curr_column=0;
            int curr_square=0;

            bool valid = true;
            for (int i=0; i<9; i++) {
                for (int j=0; j<9; j++) {
                    curr_row = i;
                    curr_column = j;
                    curr_square = (curr_row/3)*3 + (curr_column/3);
                    char input = board[i][j];
                    if (input != '.') { //it is a number between 1 and 9
                        if (rows[curr_row].count(input) ==  1 || columns[curr_column].count(input) == 1 || squares[curr_square].count(input) == 1) { //if it is not already in row
                            valid = 0;
                            break;
                        }
                        else {
                            rows[curr_row].insert(input);
                            columns[curr_column].insert(input);
                            squares[curr_square].insert(input);
                        }
                    }
                }
            }
            return valid;
        }
};
