#include<iostream>

class TicTacToe{
    private:

        char (*board)[3];
        
        int row,col;
        char turn = 'X';

    public:

        TicTacToe(int row_in, int col_in, char (&board_in)[3][3])
                :
            board(&board_in[0]),
            row(row_in),
            col(col_in)
        {};
        
        
        void player_Turn();
        void Draw_board();
        bool game_Over();

};

void TicTacToe::Draw_board(){
    board[3][3];

    std::cout<<"PLAYER - 1 [X]t PLAYER - 2 [O]" << std::endl;
    std::cout<<"\t\t     |     |     \n";
    std::cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    std::cout<<"\t\t_____|_____|_____\n";
    std::cout<<"\t\t     |     |     \n";
    std::cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    std::cout<<"\t\t_____|_____|_____\n";
    std::cout<<"\t\t     |     |     \n";
    std::cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    std::cout<<"\t\t     |     |     \n";
};

//create a logic for player turn
void TicTacToe::player_Turn(){
    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col];
        if(turn == 'X'){
            std::cout << "Player 1 Turn: " << std::endl;
            turn ='O';
        }else{
            std::cout << "Player 2 Turn: " << std::endl;
            turn = 'X';
        }

    }


};

int main(){

    TicTacToe Tic;
    Tic.Draw_board();

    return 0;

};