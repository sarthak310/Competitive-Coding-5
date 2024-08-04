//time: O(n2)
//space: O(n2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return rowCheck(board) && colCheck(board) && boxCheck(board);
    }
private:
    bool rowCheck(vector<vector<char>>& board) {  
        for(int i = 0; i < 9; i++) {
            unordered_set<char> uset;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.' && board[i][j] != ',') {
                    cout<<board[i][j]<<endl;
                    if(uset.count(board[i][j]) == 1) {
                        return false;
                    }
                    uset.insert(board[i][j]);
                }
            }
        }
        return true;
    }

    bool colCheck(vector<vector<char>>& board) {  
        for(int i = 0; i < 9; i++) {
            unordered_set<char> uset;
            for(int j = 0; j < 9; j++) {
                if(board[j][i] != '.' && board[j][i] != ',') {
                    cout<<board[j][i]<<endl;
                    if(uset.count(board[j][i]) == 1) {
                        return false;
                    }
                    uset.insert(board[j][i]);
                }
            }
        }
        return true;
    }

    bool boxCheck(vector<vector<char>>& board) {
        int arr[9][9] = {0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.' && board[i][j] != ',') {
                    cout<<board[i][j]<<endl;    
                    int x = (i/3)*3 + (j/3);
                    int y = board[i][j] - '0' - 1;
                    if(arr[x][y] == 1) {
                        return false;
                    }
                    arr[x][y] = 1;
                }    
            }
        }
        return true;
    }
};