#include <iostream> 
#include <iomanip>
#include <vector>
#define BOARD_SIZE 8
using namespace std;



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

//This function checks if the position is empty and if there are adjacent pieces
bool checkEmptyAndAdjPiece(char board[BOARD_SIZE][BOARD_SIZE], int i, int j){
    
    if(board[i][j] != ' '){
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

//This function checks if there is a possible flip 
bool checkPossibleFlip(char board[BOARD_SIZE][BOARD_SIZE], int i, int j, char player,bool print){
    // int test_i = i;
    // int test_j = j;
    char opponent;
    if( player == 'B'){
        opponent = 'W';
    } else{
        opponent = 'B';
    }
    bool check_opponent= false;
    // bool check_piece = false;
    // if (print && i == 5 && j ==3){
    //     cout << "Error here";
    // }
    //check from current all the way right
    for (int test_j = j+1; test_j < BOARD_SIZE; test_j++) {

        if (board[i][test_j] == ' '){
            break;
        }
        else if (board[i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
    }
    check_opponent= false;

    //check from current all the way left
    for (int test_j = j-1; test_j > 0; test_j--) {

        if (board[i][test_j] == ' '){
            break;
        }
        else if (board[i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
    }
    check_opponent= false;


    //check from current all the way down
    for (int test_i = i+1; test_i < BOARD_SIZE; test_i++) {

        if (board[test_i][j] == ' '){
            break;
        }
        else if (board[test_i][j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
    }
    check_opponent= false;

    //check from current all the way up
    for (int test_i = i-1; test_i > 0; test_i--) {
       
        if (board[test_i][j] == ' '){
            break;
        }
        else if (board[test_i][j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
    }
    check_opponent= false;

    //check from current all the way top-right
    int test_i = i-1;
    int test_j = j+1;

    while (test_i >0 && test_j < BOARD_SIZE){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
        test_i--;
        test_j++;
    }
    check_opponent= false;

    //check from current all the way top-left
    test_i = i-1;
    test_j = j-1;

    while (test_i >0 && test_j > 0){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
        test_i--;
        test_j--;
    }
    check_opponent= false;

    //check from current all the way bottom-right
    test_i = i+1;
    test_j = j+1;

    while (test_i < BOARD_SIZE && test_j < BOARD_SIZE){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
        test_i++;
        test_j++;
    }
    check_opponent= false;


    //check from current all the way bottom-left

    test_i = i+1;
    test_j = j-1;

    while (test_i < BOARD_SIZE && test_j > 0){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            return true;
        }
        test_i++;
        test_j--;
    }

    return false;

}

void updateValidMove (bool (&valid_moves)[BOARD_SIZE][BOARD_SIZE], char turn, char board[BOARD_SIZE][BOARD_SIZE],vector<int> &i_moves, vector<int> &j_moves){

    i_moves.clear();
    j_moves.clear();
    for (int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if( checkEmptyAndAdjPiece(board,i,j)){
                if ( checkPossibleFlip(board,i,j,turn,false)){
                    // cout << i << " " << j;
                    // checkPossibleFlip(board,i,j,turn,true);
                    // cout << endl;
                    // cout << endl;
                    valid_moves[i][j] = true;
                    i_moves.push_back(i);
                    j_moves.push_back(j);
                }
                else{
                    valid_moves[i][j] = false;
                }
            }
            else{
                valid_moves[i][j] = false;
            }
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE], bool valid_moves[BOARD_SIZE][BOARD_SIZE]){
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

                if(board[board_row][board_col] != ' ')
                {
                    cout << board[board_row][board_col];
                }
                else if (valid_moves[board_row][board_col]){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
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

void updateBoardFromInput(char (&board)[BOARD_SIZE][BOARD_SIZE],char input[], char player){

    int i = input[1] - 49; 
    int j = input[0] - 97;
    board[i][j] = player;

    char opponent;
    if( player == 'B'){
        opponent = 'W';
    } else{
        opponent = 'B';
    }
    bool check_opponent= false;
    bool should_flip = false;
    //Flip right if possible
    for (int test_j = j+1; test_j < BOARD_SIZE; test_j++) {

        if (board[i][test_j] == ' '){
            break;
        }
        else if (board[i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip = true;
        }
    }
    //Flip all piece right 
    if (should_flip){
        int test_i = i;
        int test_j = j+1;
        while(board[test_i][test_j] == opponent && j < BOARD_SIZE)
        {
            board[test_i][test_j] = player;
            test_j++;

        }
    }
    
    check_opponent = false;
    should_flip = false;
    //Flip left if possible
    for (int test_j = j-1; test_j > 0; test_j--) {

        if (board[i][test_j] == ' '){
            break;
        }
        else if (board[i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip = true;
        }
    }
    if (should_flip){
        int test_i = i;
        int test_j = j-1;
        while(board[test_i][test_j] == opponent && j > 0)
        {
            board[test_i][test_j] = player;
            test_j--;

        }
    }

    check_opponent = false;
    should_flip = false;
    //Flip down if possible
    for (int test_i = i+1; test_i < BOARD_SIZE; test_i++) {

        if (board[test_i][j] == ' '){
            break;
        }
        else if (board[test_i][j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip = true;
        }
    }

    if (should_flip){
        int test_i = i+1;
        int test_j = j;
        while(board[test_i][test_j] == opponent && test_i < BOARD_SIZE)
        {
            board[test_i][test_j] = player;
            test_i++;

        }
    }
    check_opponent = false;
    should_flip = false;

    //Flip up if possible

    for (int test_i = i-1; test_i > 0; test_i--) {
       
        if (board[test_i][j] == ' '){
            break;
        }
        else if (board[test_i][j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip = true;
        }
    }

    if (should_flip){
        int test_i = i-1;
        int test_j = j;
        while(board[test_i][test_j] == opponent && test_i > 0)
        {
            board[test_i][test_j] = player;
            test_i--;

        }
    }
    check_opponent = false;
    should_flip = false;

    //Flip top-right if possible
    int test_i = i-1;
    int test_j = j+1;

    while (test_i >0 && test_j < BOARD_SIZE){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip = true;
        }
        test_i--;
        test_j++;
    }

    if (should_flip){
        test_i = i-1;
        test_j = j+1;
        while(board[test_i][test_j] == opponent && test_i > 0 && test_j < BOARD_SIZE)
        {
            board[test_i][test_j] = player;
            test_i--;
            test_j++;

        }
    }
    check_opponent = false;
    should_flip = false;

    //Flip top-left

    test_i = i-1;
    test_j = j-1;

    while (test_i >0 && test_j > 0){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip = true;
        }
        test_i--;
        test_j--;
    }
    if (should_flip){
        test_i = i-1;
        test_j = j-1;
        while(board[test_i][test_j] == opponent && test_i > 0 && test_j > 0)
        {
            board[test_i][test_j] = player;
            test_i--;
            test_j--;

        }
    }
    check_opponent = false;
    should_flip = false;

    //Flip bottom-right if possible

    test_i = i+1;
    test_j = j+1;

    while (test_i < BOARD_SIZE && test_j < BOARD_SIZE){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip = true;
        }
        test_i++;
        test_j++;
    }

    if (should_flip){
        test_i = i+1;
        test_j = j+1;
        while(board[test_i][test_j] == opponent && test_i < BOARD_SIZE && test_j < BOARD_SIZE)
        {
            board[test_i][test_j] = player;
            test_i++;
            test_j++;

        }
    }
    check_opponent = false;
    should_flip = false;

    //Flip bottom-right if possible
    test_i = i+1;
    test_j = j-1;

    while (test_i < BOARD_SIZE && test_j > 0){
        if (board[test_i][test_j] == ' '){
            break;
        }
        else if (board[test_i][test_j] == player && !(check_opponent)){
            break;
        }
        else if (board[test_i][test_j] == opponent){
            
            check_opponent =true;
        }
        else if (board[test_i][test_j] == player && check_opponent){

            //Returnt true since you would have succesfully flipped atleast one thing
            should_flip =true;
        }
        test_i++;
        test_j--;
    }

    if (should_flip){
        test_i = i+1;
        test_j = j-1;
        while(board[test_i][test_j] == opponent && test_i < BOARD_SIZE && test_j > 0)
        {
            board[test_i][test_j] = player;
            test_i++;
            test_j--;

        }
    }
    check_opponent = false;
    should_flip = false;

}

bool isInputValid(char input[],bool valid_moves[BOARD_SIZE][BOARD_SIZE]){
    
    cout << input[0];
    cout << input[1];
    bool test = input[1] <= 56 ;
    cout << "       " << test << endl;
    bool charCheck = false;
    bool numCheck = false;
    
    if(input[0] >= 97 && input[0] <= 104 ){

        charCheck = true;
    }

    if(input[1] > 48 && input[1] <= 56){

        numCheck = true;
    }

    if (!(numCheck && charCheck)){
        cout<<"ERROR, not a valid move on the board\n";
       
        return false;
    }
    int i = input[1] - 49; 
    int j = input[0] - 97;
    cout << i << endl;
    if(!valid_moves[i][j]){
        cout<<"ERROR, not a valid move on the board\n";
        return false;
    }

    return true;
}

void pieceCounter(int &black, int &white, char board[BOARD_SIZE][BOARD_SIZE]){

    black = 0;
    white = 0;
    for (int i = 0; i < BOARD_SIZE; i++){

        for (int j = 0; j < BOARD_SIZE; j++){
                if(board[i][j] == 'W'){
                    white++;
                }
                else if(board[i][j] == 'B'){
                    black++;
                }
        }
    }
}


void playerVsPlayer(){
    char board[BOARD_SIZE][BOARD_SIZE];
    bool valid_moves[BOARD_SIZE][BOARD_SIZE];
    vector<int> i_moves;
    vector<int> j_moves;
    bool last_skip = true;
    initializeBoard(board);
    char turn = 'W';
    int bCount = 0;
    int wCount = 0;
    while(true){


        if( turn =='W'){
            turn = 'B';
        }
        else{ 
            turn = 'W';
        }
        updateValidMove(valid_moves,turn,board,i_moves,j_moves);




    
    }


}

void mainMenu(){
    const int INPUT_SIZE = 2;
    bool is_input_valid = false;
    char input[INPUT_SIZE];
    do{
        cout<<"Hello there, please enter the game mode you want to play" << endl;
        cout<< "[1] Player vs. Player (human vs human)" << endl;
        cout << "[2] Player vs Ai1 (Pure Monte Carlo)" << endl;
        cout << "[3] Player vs Ai2 (Monte Carlo with Heuristics)" << endl;
        cout << "[4] Ai1 vs Ai2 (Pure VS Non-pure Monte Carlo)" << endl;
        cout <<"Note: only your first character will be captured as input" << endl << endl;
        cin.get(input,INPUT_SIZE);
        cin.ignore(1024, '\n');
        cin.clear();
        if(input[0] == '1'){
            cout <<"Starting Player vs player...";
            cout <<"--------------------------------------" << endl << endl;
            playerVsPlayer();
            is_input_valid = true;
        }
        else if(input[0] =='2'){
            cout <<"This version is not supported yet" << endl << endl;
            is_input_valid = true;

        }
        else if(input[0] =='3'){
            cout <<"This version is not supported yet" << endl << endl;
            is_input_valid = true;
        }
        else if(input[0] =='4'){
            cout <<"This version is not supported yet" << endl << endl;
            is_input_valid = true;
        }
        else{
            cout <<"ERROR: Invalid input, please try again" << endl << endl;
        }
    } while(!is_input_valid);
}

int main(){
    
    mainMenu();
    // char board[8][8];
    // bool valid_moves[8][8];
    // vector<int> i_moves;
    // vector<int> j_moves;
    // initializeBoard(board);
    // updateValidMove(valid_moves,'B',board,i_moves,j_moves);
    // printBoard(board,valid_moves);
    // char input[2] = {'c','4'};
    // // bool tester = isInputValid(input, valid_moves);
    // updateBoardFromInput(board,input, 'B');
    // // cout << tester;

    // updateValidMove(valid_moves,'W',board,i_moves,j_moves);
    // printBoard(board,valid_moves);
    // input[1] = '3';
    // updateBoardFromInput(board,input,'W');
    // updateValidMove(valid_moves,'B',board,i_moves,j_moves);
    // printBoard(board,valid_moves);



    return 0;
}