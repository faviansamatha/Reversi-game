#include <iostream> 
#include <iomanip>
using namespace std;
char board[8][8];
bool valid_moves[8][8];
const int BOARD_SIZE = 8;

void initializeBoard (char (&board)[8][8]) {

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


void printBoard(char (&board)[8][8]){
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



int main(){
    initializeBoard(board);
    printBoard(board);


    return 0;
}