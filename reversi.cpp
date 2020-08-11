#include <iostream> 
#include <iomanip>
#include <vector>
#include <ctime>
// #include "gameLogic.h"
// #include "mcPure.h"
#include "mcHeur.h"

#define BOARD_SIZE 8
using namespace std;



int win_points_pure_mc = 5;
int lose_points_pure_mc = -1;
int draw_points_pure_mc = 2;
const double MAX_TIMEOUT = 5; // Maximum seconds for AI to be able to move.
const int TOTAL_GAMES = 3000; // Most likely won't reach this


void playerVsPlayer(){
    const int INPUT_SIZE = 3;
    char board[BOARD_SIZE][BOARD_SIZE];
    bool valid_moves[BOARD_SIZE][BOARD_SIZE];
    vector<int> i_moves;
    vector<int> j_moves;
    bool last_skip = false;
    initializeBoard(board);
    char turn = 'W';
    int b_count = 0;
    int w_count = 0;
    bool is_input_not_valid = true;
    while(true){
        char input[INPUT_SIZE];
        if( turn =='W'){
            turn = 'B';
        }
        else{ 
            turn = 'W';
        }
        updateValidMove(valid_moves,turn,board,i_moves,j_moves);
        pieceCounter(b_count,w_count,board);
        printBoard(board,valid_moves);
        cout<<"Black's Pieces: " << b_count << "\t" <<"White's Pieces: " << w_count << endl;
        
        if(i_moves.size() ==0 && j_moves.size() ==0)
        {
            cout << turn << " has no legal moves... skipping turn" << endl << endl;
            if(last_skip){
                cout << endl << endl;
                cout << "The game has ended. The winner is: ";
                if( b_count > w_count){
                    cout <<"Black";
                }
                else if (b_count < w_count){
                    cout <<"White";
                }
                else{
                    cout << "Nobody, it's a tie!";
                }
                cout<<endl << "Ending game..." << endl;
                cout << "-------------------------------------" << endl;
                break;
            }else{
                last_skip = true;
            }

            continue;
        }
        else{
            last_skip = false;
        }
        
        while(is_input_not_valid){
            
            cout << turn << "'s turn, please input a move: ";
            cin.get(input,INPUT_SIZE);
            cin.ignore(1024,'\n');
            cin.clear();
            is_input_not_valid = !isInputValid(input,valid_moves);
            if(is_input_not_valid){

                cout <<"ERROR: Input isn't valid! Try again!" << endl;
            }
        }
        is_input_not_valid = true;
        updateBoardFromInput(board,input,turn);

    }
}

void pureMonteCarlo(bool isPlayerFirst){

    bool is_input_not_valid = true;

    
    const int INPUT_SIZE = 3;
    char board[BOARD_SIZE][BOARD_SIZE];
    bool valid_moves[BOARD_SIZE][BOARD_SIZE];
    vector<int> i_moves;
    vector<int> j_moves;
    bool last_skip = false;
    initializeBoard(board);
    char turn = 'W';
    char ai;
    char human;
    if(isPlayerFirst)
    {
        ai = 'W';
        human = 'B';
    }
    else{

        ai = 'B';
        human = 'W';
    }
    int b_count = 0;
    int w_count = 0;
    is_input_not_valid = true;
    while(true){
        char input[INPUT_SIZE];
        if( turn =='W'){
            turn = 'B';
        }
        else{ 
            turn = 'W';
        }
        updateValidMove(valid_moves,turn,board,i_moves,j_moves);
        pieceCounter(b_count,w_count,board);
        printBoard(board,valid_moves);
        cout<<"Black's Pieces: " << b_count << "\t" <<"White's Pieces: " << w_count << endl;
        
        if(i_moves.size() ==0 && j_moves.size() ==0)
        {
            cout << turn << " has no legal moves... skipping turn" << endl << endl;
            if(last_skip){
                cout << endl << endl;
                cout << "The game has ended. No more legal moves for both players. The winner is: ";
                if( b_count > w_count){
                    if(ai == 'B'){
                        cout<<"AI WINS!!\n";
                    }
                    else{
                        cout << "HUMAN WINS!!\n";
                    }
                }
                else if (b_count < w_count){
                    if(ai == 'W'){
                        cout<<"AI WINS!!\n";
                    }
                    else{
                        cout << "HUMAN WINS!!\n";
                    }
                }
                else{
                    cout << "Nobody, it's a tie!\n";
                }
                cout<<endl << "Ending game..." << endl;
                cout << "-------------------------------------" << endl;
                break;
            }else{
                last_skip = true;
            }

            continue;
        }
        else{
            last_skip = false;
        }

        if (turn == human){
            while(is_input_not_valid){
                
                cout << turn << "'s turn, please input a move: ";
                cin.get(input,INPUT_SIZE);
                cin.ignore(1024,'\n');
                cin.clear();
                is_input_not_valid = !isInputValid(input,valid_moves);
                if(is_input_not_valid){

                    cout <<"ERROR: Input isn't valid! Try again!" << endl;
                }
            }
        is_input_not_valid = true;
        updateBoardFromInput(board,input,turn);
        }
        else{
            cout <<"AI is thinking..."<<endl;
            pureMonteCarloMoves(board,i_moves,j_moves,ai);
        }
    }
}

void heurMonteCarlo(bool isPlayerFirst){

    bool is_input_not_valid = true;

    
    const int INPUT_SIZE = 3;
    char board[BOARD_SIZE][BOARD_SIZE];
    bool valid_moves[BOARD_SIZE][BOARD_SIZE];
    vector<int> i_moves;
    vector<int> j_moves;
    bool last_skip = false;
    initializeBoard(board);
    char turn = 'W';
    char ai;
    char human;
    if(isPlayerFirst)
    {
        ai = 'W';
        human = 'B';
    }
    else{

        ai = 'B';
        human = 'W';
    }
    
    int b_count = 0;
    int w_count = 0;
    is_input_not_valid = true;
    while(true){
        char input[INPUT_SIZE];
        if( turn =='W'){
            turn = 'B';
        }
        else{ 
            turn = 'W';
        }
        updateValidMove(valid_moves,turn,board,i_moves,j_moves);
        pieceCounter(b_count,w_count,board);
        printBoard(board,valid_moves);
        cout<<"Black's Pieces: " << b_count << "\t" <<"White's Pieces: " << w_count << endl;
        
        if(i_moves.size() ==0 && j_moves.size() ==0)
        {
            cout << turn << " has no legal moves... skipping turn" << endl << endl;
            if(last_skip){
                cout << endl << endl;
                cout << "The game has ended. No more legal moves for both players. The winner is: ";
                if( b_count > w_count){
                    if(ai == 'B'){
                        cout<<"AI WINS!!\n";
                    }
                    else{
                        cout << "HUMAN WINS!!\n";
                    }
                }
                else if (b_count < w_count){
                    if(ai == 'W'){
                        cout<<"AI WINS!!\n";
                    }
                    else{
                        cout << "HUMAN WINS!!\n";
                    }
                }
                else{
                    cout << "Nobody, it's a tie!\n";
                }
                cout<<endl << "Ending game..." << endl;
                cout << "-------------------------------------" << endl;
                break;
            }else{
                last_skip = true;
            }

            continue;
        }
        else{
            last_skip = false;
        }

        if (turn == human){
            while(is_input_not_valid){
                
                cout << turn << "'s turn, please input a move: ";
                cin.get(input,INPUT_SIZE);
                cin.ignore(1024,'\n');
                cin.clear();
                is_input_not_valid = !isInputValid(input,valid_moves);
                if(is_input_not_valid){

                    cout <<"ERROR: Input isn't valid! Try again!" << endl;
                }
            }
        is_input_not_valid = true;
        updateBoardFromInput(board,input,turn);
        }
        else{
            cout <<"AI is thinking..."<<endl;
            heurMonteCarloMoves(board,i_moves,j_moves,ai);
        }
    }
}

//ai is pure, and ai2 is heuristics
char aiVsAi(char ai, char ai2){

    bool is_input_not_valid = true;
    
    const int INPUT_SIZE = 3;
    char board[BOARD_SIZE][BOARD_SIZE];
    bool valid_moves[BOARD_SIZE][BOARD_SIZE];
    vector<int> i_moves;
    vector<int> j_moves;
    bool last_skip = false;
    initializeBoard(board);
    char turn = 'W';
    // char ai2 = 'W';
    // char ai = 'B';
    int b_count = 0;
    int w_count = 0;
    is_input_not_valid = true;
    while(true){
        char input[INPUT_SIZE];
        if( turn =='W'){
            turn = 'B';
        }
        else{ 
            turn = 'W';
        }
        updateValidMove(valid_moves,turn,board,i_moves,j_moves);
        pieceCounter(b_count,w_count,board);
        printBoard(board,valid_moves);
        cout<<"Black's Pieces: " << b_count << "\t" <<"White's Pieces: " << w_count << endl;
        
        if(i_moves.size() ==0 && j_moves.size() ==0)
        {
            cout << turn << " has no legal moves... skipping turn" << endl << endl;
            if(last_skip){
                cout << endl << endl;
                cout << "The game has ended. No more legal moves for both players. The winner is: ";
                if( b_count > w_count){
                    if(ai == 'B'){
                        cout<<"Pure WINS!!\n";
                        return 'P';
                    }
                    else{
                        cout << "Heuristic WINS!!\n";
                        return 'H';
                    }
                }
                else if (b_count < w_count){
                    if(ai == 'W'){
                        cout<<"Pure WINS!!\n";
                        return 'P';
                    }
                    else{
                        cout << "Heuristic WINS!!\n";
                        return 'H';
                    }
                }
                else{
                    cout << "Nobody, it's a tie!\n";
                    return ' ';
                }
                cout<<endl << "Ending game..." << endl;
                cout << "-------------------------------------" << endl;
                break;
            }else{
                last_skip = true;
            }

            continue;
        }
        else{
            last_skip = false;
        }

        if (turn == ai){
            cout <<"Pure is " << ai << " and thinking..." << endl;
            pureMonteCarloMoves(board, i_moves, j_moves,ai);
        }
        else{
            cout <<"Heuristics is " << ai2 << " and thinking..."<<endl;
            heurMonteCarloMoves(board,i_moves,j_moves,ai2);
        }
    }
    return ' ';
}

void experiment(){

    int totalGamesFirst = 0;
    int totalGamesSecond = 0;
    int first_HeurWins = 0;
    int first_PureWins = 0;
    int first_ties = 0;
    int second_PureWins = 0;
    int second_HeurWins = 0;
    int second_ties = 0;
    char result = ' ';
    int totalGames = 50;
    // When heuristics is black (goes first)
    for(int i = 0; i < totalGames; i++){
        
        result = aiVsAi('W','B');
        if(result == 'H'){
            first_HeurWins++;
        }
        else if (result == 'P'){
            first_PureWins++;
        }
        else{
            first_ties++;
        }

        totalGamesFirst++;
        cout << endl << "-----------------------"<< endl;
        cout << "A game ended. So far for heuristics as black:\n";
        cout << "Heuristics won " << first_HeurWins <<"/" << totalGamesFirst<< " games" << endl;
        cout << "Pure won " << first_PureWins <<"/" << totalGamesFirst<< " games" << endl;
        cout << "Number of ties " << first_ties << "/" << totalGamesFirst << " games" << endl;
        cout << endl << "-----------------------"<< endl;
    }

    // When heuristics is white (goes second)
    for(int i = 0; i < totalGames; i++){

        result = aiVsAi('B','W');
        if(result == 'H'){
            second_HeurWins++;
        }
        else if (result == 'P'){
            second_PureWins++;
        }
        else{
            second_ties++;
        }
        totalGamesSecond++;
        cout << endl << "-----------------------"<< endl;
        cout << "A game ended. So far heuristics as white:\n";
        cout << "Heuristics won " << second_HeurWins <<"/" << totalGamesSecond<< " games" << endl;
        cout << "Pure won " << second_PureWins <<"/" << totalGamesSecond<< " games" << endl;
        cout << "Number of ties " << second_ties << "/" << totalGamesSecond << " games" << endl;
        cout << endl << "-----------------------"<< endl;

        
    }

    cout << endl << "-----------------------"<< endl;
    cout << "EXPERIMENT DONE";
    cout << "When heuristics went first as black, it won: " << first_HeurWins <<"/" << totalGamesFirst << ".";
    cout << " and tied " << first_ties << "/"<< totalGamesFirst <<"." << endl;
    cout << "When heuristics went second as white, it won: " << second_HeurWins <<"/" << totalGamesSecond << ".";
    cout << " and tied " << second_ties << "/"<< totalGamesSecond <<"." << endl;
    cout << endl << "-----------------------"<< endl;




}

void mainMenu(){
    const int INPUT_SIZE = 2;
    bool is_input_valid = false;
    char input[INPUT_SIZE];
    do{
        cout <<"Hello there, please enter the game mode you want to play" << endl;
        cout << "[1] Player vs. Player (human vs human)" << endl;
        cout << "[2] Player vs Ai1 (Pure Monte Carlo), player goes first." << endl;
        cout << "[3] Player vs Ai1 (Pure Monte Carlo), Ai1 goes first." << endl;
        cout << "[4] Player vs Ai2 (Monte Carlo with Heuristics), player goes first" << endl;
        cout << "[5] Player vs Ai2 (Monte Carlo with Heuristics), player goes second" << endl;
        cout << "[6] Ai1 vs Ai2 (Pure VS Non-pure Monte Carlo)" << endl;
        cout << "[7] Experiments and statistics with Ai1 and Ai2" << endl;
        cout <<"Note: only your first character will be captured as input" << endl << endl;
        cin.get(input,INPUT_SIZE);
        cin.ignore(1024, '\n');
        cin.clear();
        if(input[0] == '1'){
            cout <<"Starting Player vs player..."<< endl;
            cout <<"--------------------------------------" << endl << endl;
            playerVsPlayer();
            is_input_valid = true;
        }
        else if(input[0] =='2'){
            pureMonteCarlo(true);
            is_input_valid = true;

        }
        else if(input[0] =='3'){
            pureMonteCarlo(false);
            is_input_valid = true;

        }
        else if(input[0] =='4'){
            heurMonteCarlo(true);
            is_input_valid = true;
        }
        else if(input[0] =='5'){
            heurMonteCarlo(false);
            is_input_valid = true;
        }
        else if(input[0] =='6'){

            cout << endl << aiVsAi('B','W') << endl;
            is_input_valid = true;

        }
        else if(input[0] =='7'){

            experiment();
            is_input_valid = true;

        }
        else{
            cout <<"ERROR: Invalid input, please try again" << endl << endl;
        }
    } while(!is_input_valid);
}

int main(){
    
    mainMenu();

    return 0;
}

