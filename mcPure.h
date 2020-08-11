#include <iostream> 
#include <iomanip>
#include <vector>
#include <ctime>
#include "gameLogic.h"

#define BOARD_SIZE 8
extern const double MAX_TIMEOUT; // Number of seconds for timeout
extern const int TOTAL_GAMES;
extern int win_points_pure_mc;
extern int lose_points_pure_mc;
extern int draw_points_pure_mc;

using namespace std;


int doRandomMoves(char (&board)[BOARD_SIZE][BOARD_SIZE], char ai){
    
    char human;
    if( ai = 'B'){
        human = 'W';
    }
    else{
        human = 'B';
    }
    char turn = human;
    bool valid_moves[BOARD_SIZE][BOARD_SIZE];
    vector<int> i_mov;
    vector<int> j_mov;
    int b_count = 0;
    int w_count = 0;
    bool last_skip = false;
    updateValidMove(valid_moves,turn,board,i_mov,j_mov);
    while(true){
        
        if(i_mov.size() == 0 && j_mov.size() ==0)
        {
                if(last_skip){
                    
                    break;
                }
                else{
                    last_skip = true;
                }
            continue; 
        }
        else{
            last_skip = false;
        }

        srand((unsigned) time(0));
        int random = (rand()%i_mov.size());
        // cout << "random move is: " << random << "Length is: " << i_mov.size() << endl;
        char input_i = i_mov[random] +49;
        char input_j = j_mov[random] + 97;
        char input[3] = {input_j, input_i, 0};

        updateBoardFromInput(board, input, turn);

        if (turn == human){
            turn = ai;
        }else{
            turn = human;
        }
        // cout <<"I'm Here" << endl;
        updateValidMove(valid_moves, turn, board, i_mov, j_mov);
        // cout <<"I broke after this" << endl;

    }

    pieceCounter(b_count,w_count,board);

    char winner;
    if(b_count > w_count){
        winner = 'B';
    }
    else if (b_count < w_count){
        winner = 'W';
    }
    else{
        winner = ' ';
    }

    if(winner == human){
        return lose_points_pure_mc;
    }
    else if(winner == ai ){
        return win_points_pure_mc;
    }
    else{
        return draw_points_pure_mc;
    }


}

void pureMonteCarloMoves( char (&board)[BOARD_SIZE][BOARD_SIZE], vector<int> i_moves, vector<int> j_moves, char ai){

    vector<int> score;
    int totalScore = 0;
    char boardCopy[BOARD_SIZE][BOARD_SIZE];
    double max_time_per_move = MAX_TIMEOUT/((double)(i_moves.size()));
    
    for(int k = 0; k < i_moves.size(); k++)
    {
        
        for(int i = 0; i < BOARD_SIZE; i++){
            for(int j = 0; j < BOARD_SIZE; j++){
                boardCopy[i][j] = board[i][j];
            }
        }
        char input_i = i_moves[k] + 49;
        char input_j = j_moves[k] + 97;
        char input[3] = {input_j,input_i,0};
        
        updateBoardFromInput(boardCopy, input, ai);
        
        double time_to_compare = 0;
        
        for(int z = 0; z <  TOTAL_GAMES; z++){
            
            if(time_to_compare >= max_time_per_move){
                break;
            }
            clock_t begin = clock();
            char boardCopy2[BOARD_SIZE][BOARD_SIZE];

            for(int i = 0; i < BOARD_SIZE; i++){

                for(int j = 0; j < BOARD_SIZE; j++){
                    
                    boardCopy2[i][j] = boardCopy[i][j]; 
                }          
            }
            
            totalScore+= doRandomMoves(boardCopy2,ai);
            clock_t end = clock();
            time_to_compare += double(end-begin)/CLOCKS_PER_SEC;
                
        }
        score.push_back(totalScore);
        totalScore = 0;
    }
    int indexWinner = 0;
    int maxScore;
    for(int k = 0; k < score.size(); k++ ){
        if (k == 0){
            maxScore = score[k];
            continue;
        }
        if(score[k] > maxScore){
            indexWinner = k;
            maxScore = score[k];
        }
    }

    char input_i = i_moves[indexWinner] + 49;
    char input_j = j_moves[indexWinner] + 97;
    char input[3] = {input_j,input_i,0};

    updateBoardFromInput(board, input, ai);
}


