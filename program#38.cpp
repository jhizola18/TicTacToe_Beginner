#include<iostream>

class TicTacToe{
    private:
        char board[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
        int row,col;
        char turn = 'X';

    public:

        TicTacToe(int row_in, int col_in)
                :
            row(row_in),
            col(col_in)
        {};
        
        void setBoard(char B){
            B = board[3][3];
        };

        void getBoard(){
            return B;
        };
        
        void Draw_board();
        bool game_Over();

};

void TicTacToe::Draw_board(){
    

};

int main(){

};