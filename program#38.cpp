#include<iostream>


class TicTacToe{
    private:

        char **board;
        int row,col;
        char turn = 'X';
        

    public:

        TicTacToe(int row_in, int col_in, char (&board_in)[3][3])
                :
            row(row_in),
            col(col_in)
            
        {
            board = new char*[row] {&board_in[0][0], &board_in[1][0], &board_in[2][0]};
        };
        
        void setTurn(char turn_in){
            turn = turn_in;
        }

        char getTurn(){
            return turn;
        }


        void player_Turn();
        void Draw_board();
        bool game_State();
        void GameLoop();

};

void TicTacToe::Draw_board(){

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
    char user_Turn;
    if(turn == 'X'){
        std::cout << "Player 1's Turn: ";
    }else{
        std::cout << "Players 2's Turn: ";
    }
    
    std::cin >> user_Turn;

    switch(user_Turn){
        case '1':
            row = 0;
            col = 0;
            break;
        case '2':
            row = 0;
            col = 1;
            break;
        case '3':
            row = 0;
            col = 2;
            break;
        case '4':
            row = 1;
            col = 0;
            break;
        case '5':
            row = 1;
            col = 1;
            break;
        case '6':
            row = 1;
            col = 2;
            break;
        case '7':
            row = 2;
            col = 0;
            break;
        case '8':
            row = 2;
            col = 1;
            break;
        case '9':
            row = 2;
            col = 2;
            break;
        default:
            std::cout << "Invalid Move\n";
    }

    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = turn;
        if(turn == 'X'){
            turn ='O';
        }else {
            turn = 'X';
        }
        
    }else{
        std::cout << "Illegal Move!";
    }
    Draw_board();
    
}



bool TicTacToe::game_State(){
    bool draw = false;
    bool winner_found = false;
    //rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            winner_found =  true;
            break;
        }
    }

    //columns
    if(!winner_found){
        for(int i = 0; i < 3; i++){
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                winner_found = true;
                break;
            }
        }
    }
    

    //diagonals    
    if(!winner_found && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        winner_found = true;
    }

    if(!winner_found && board[0][2] == board[1][1] && board [1][1] == board[2][0]){
        winner_found = true;
    }
    
    if(!winner_found){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != 'X' && board[i][j] != 'O'){
                    draw = false;
                    break;
                }
            }
            if(!draw) break;
        }
    }
    if(winner_found){
        if(turn == 'O'){
            std::cout << "Player 1 Wins";
        }else if(turn == 'X'){
            std::cout << "Player 2 Wins";
        }
    } else if(draw){
        std::cout << "Draw!!";
    }
    
    
    
    return !(winner_found || draw);              
}


void TicTacToe::GameLoop(){
    while(game_State()){
        Draw_board();
        player_Turn();

    }
   
}


int main(){
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    TicTacToe gameObj(3,3,board);
    TicTacToe* gameStart = &gameObj;
    gameStart->GameLoop();
    
    
    
    return 0;

};