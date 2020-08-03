#include <iostream> 
#include <iomanip>
#define BOARD_SIZE 8
using namespace std;
char board[8][8];
bool valid_moves[8][8];


void initializeBoard (char (&board)[BOARD_SIZE][BOARD_SIZE]) {

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++){
            
            if(i ==3 && j == 3)
            {
                board[i][j] = 'W';
            }
            else if(i ==3 && j == 4)
            {
                board[i][j] = 'B';
            }
            else if(i ==4 && j == 4)
            {
                board[i][j] = 'W';
            }
            else if(i ==4 && j == 3)
            {
                board[i][j] = 'B';
            }
            else{
                board[i][j] = ' ';
            }
        }
    }

}


void printBoard(char (&board)[BOARD_SIZE][BOARD_SIZE]){
    const int num_rows = 17;
    const int num_cols = 34;
    char row_cnt = '1';
    char col_cnt = 'a';
    int board_row = 0;
    int board_col = 0;
    for (int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            if(j == 0 && i %2 !=0){
                cout << row_cnt;
                row_cnt++;
            }
            else if(j ==0 && i%2 ==0){
                cout <<" ";
            }
            else if( (j-1) %4 == 0 && i %2 == 0){
                cout<<"+";
            }
            else if (i%2==0){
                cout<<"-";
            }
            else if( (j-1) %4 == 0 && i %2 != 0){
                cout<<"|";

            }
            else if( j >2 && (j-3) % 4 ==0 && i %2 !=0 ){
                cout << board[board_row][board_col];
                board_col++;
            }
            else if( (j-1) %4 != 0 && i %2 != 0){
                cout<<" ";

            }
        }
        cout << "\n";
        if (i %2 != 0){
            board_row ++;
            board_col =0;
        }
        
    }
    for (int j = 0; j < num_cols; j++){

        if( j>2 && (j-3)%4 == 0){
            cout << col_cnt;
            col_cnt++;
        }
        else{
            cout<<" ";
        }
    }
    cout << endl;


}

void updateValidMove (bool (&valid_moves)[BOARD_SIZE][BOARD_SIZE], char turn, char board[BOARD_SIZE][BOARD_SIZE]){

    char opponent;
    if( turn == 'B'){
        opponent = 'W';
    } else{
        opponent = 'B';
    }
}

//This function checks if the position is empty and if there are adjacent pieces
bool checkEmptyAndAdjPiece(char board[BOARD_SIZE][BOARD_SIZE], int i, int j){
    
    if(board[i][j] != ' '){
        cout<< "I'm here!"<< endl;
        return false;
    }
    //Check top-left corner
    else if(i == 0 && j ==0){
        if( board[i][j+1] == ' ' &&
            board[i+1][j] == ' ' &&
            board[i+1][j+1] == ' ' ){
            return false;
        } else{ 
            return true;
        }
    }
    //Check top-right corner
    else if(i==0 && j ==7){
        if( board[i+1][j]==' ' &&
            board[i][j-1] == ' ' &&
            board[i+1][j-1] == ' '
        ){
            return false;
        } else{
            return true;
        }
    }
    //Check bottom-left corner
    else if(i == 7 && j == 0){
        if( board[i-1][j]==' ' &&
            board[i][j+1] == ' ' &&
            board[i-1][j+1] == ' '
        ){
            return false;
        } else{
            return true;
        }
    }
    //Check bottom-right corner
    else if(i == 7 && j == 7){
        if( board[i-1][j]==' ' &&
            board[i][j-1] == ' ' &&
            board[i-1][j-1] == ' '
        ){
            return false;
        } else{
            return true;
        }
    }
    //Check the top row not including the corner
    else if( i == 0)
    {
        if( board[i][j-1]==' ' &&
            board[i][j+1] == ' ' &&
            board[i+1][j-1] == ' ' &&
            board[i+1][j] == ' ' &&
            board[i+1][j+1] == ' '

        ){
            return false;
        } else{
            return true;
        }
    }
    //Checks the bottom row not including the corner
    else if( i == 7)
    {
        if( board[i][j-1]==' ' &&
            board[i][j+1] == ' ' &&
            board[i-1][j-1] == ' ' &&
            board[i-1][j] == ' ' &&
            board[i-1][j+1] == ' '

        ){
            return false;
        } else{
            return true;
        }
    }
    //Checks the most left column not including the corner
    else if (j == 0)
    {
        if( board[i-1][j]==' ' &&
            board[i+1][j] == ' ' &&
            board[i][j+1] == ' ' &&
            board[i+1][j+1] == ' ' &&
            board[i-1][j+1] == ' '

        ){
            return false;
        } else{
            return true;
        }
    }
    //Checks the most right column not including the corner
    else if (j == 7)
    {
        if( board[i-1][j]==' ' &&
            board[i+1][j] == ' ' &&
            board[i][j-1] == ' ' &&
            board[i+1][j-1] == ' ' &&
            board[i-1][j-1] == ' '

        ){
            return false;
        } else{
            return true;
        }
    }
    //Check everywhere else
    else{
 
        if( board[i+1][j]==' ' &&
            board[i-1][j] == ' ' &&
            board[i][j+1] == ' ' &&
            board[i][j-1] == ' ' &&
            board[i+1][j+1] == ' ' &&
            board[i+1][j-1] == ' ' &&
            board[i-1][j+1] == ' ' &&
            board[i-1][j-1] == ' '

        ){
            return false;
        } else{
            return true;
        }
    }
}


int main(){
    initializeBoard(board);
    printBoard(board);
    bool testPrint = checkEmptyAndAdjPiece(board,2,5);
    cout << testPrint << endl;

    return 0;
}