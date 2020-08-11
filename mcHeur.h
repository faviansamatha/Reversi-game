#include <iostream> 
#include <iomanip>
#include <vector>
#include <ctime>
#include "mcPure.h"
using namespace std;
#define BOARD_SIZE 8
extern const double MAX_TIMEOUT; // Number of seconds for timeout
extern const int TOTAL_GAMES;
extern int win_points_pure_mc;
extern int lose_points_pure_mc;
extern int draw_points_pure_mc;

int heurRandomMoves(char (&board)[BOARD_SIZE][BOARD_SIZE], char ai){
    
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
        bool check_buffer = true;
        //if there is a possible "powerspot" in reversi, alter the i_moves and j_moves
        //to only include these powerspots.
        for(int k = 0; k < i_mov.size(); k++){
            if(i_mov[k] == 0 && j_mov[k] == 0
            || i_mov[k] == 0 && j_mov[k] == 7 
            || i_mov[k] == 7 && j_mov[k] == 0
            || i_mov[k] == 7 && j_mov[k] == 7
            || i_mov[k] == 0 && j_mov[k] == 2
            || i_mov[k] == 0 && j_mov[k] == 5
            || i_mov[k] == 2 && j_mov[k] == 0
            || i_mov[k] == 2 && j_mov[k] == 2
            || i_mov[k] == 2 && j_mov[k] == 5
            || i_mov[k] == 2 && j_mov[k] == 7
            || i_mov[k] == 5 && j_mov[k] == 0
            || i_mov[k] == 5 && j_mov[k] == 2
            || i_mov[k] == 5 && j_mov[k] == 5
            || i_mov[k] == 5 && j_mov[k] == 7
            || i_mov[k] == 7 && j_mov[k] == 2
            || i_mov[k] == 7 && j_mov[k] == 5
            ){
                check_buffer = false; //Don't need to check buffer since it'll be discarded
                vector<int> temp_i(i_mov);
                vector<int> temp_j(j_mov);

                i_mov.clear();
                j_mov.clear();
                for(int z = 0; z< temp_i.size(); z++){
                    if(temp_i[k] == 0 && temp_j[k] == 0
                    || temp_i[k] == 0 && temp_j[k] == 7 
                    || temp_i[k] == 7 && temp_j[k] == 0
                    || temp_i[k] == 7 && temp_j[k] == 7
                    || temp_i[k] == 0 && temp_j[k] == 2
                    || temp_i[k] == 0 && temp_j[k] == 5
                    || temp_i[k] == 2 && temp_j[k] == 0
                    || temp_i[k] == 2 && temp_j[k] == 2
                    || temp_i[k] == 2 && temp_j[k] == 5
                    || temp_i[k] == 2 && temp_j[k] == 7
                    || temp_i[k] == 5 && temp_j[k] == 0
                    || temp_i[k] == 5 && temp_j[k] == 2
                    || temp_i[k] == 5 && temp_j[k] == 5
                    || temp_i[k] == 5 && temp_j[k] == 7
                    || temp_i[k] == 7 && temp_j[k] == 2
                    || temp_i[k] == 7 && temp_j[k] == 5
                    ){
                        i_mov.push_back(temp_i[k]);
                        j_mov.push_back(temp_j[k]);
                    }
                }
                break;
            }   
        }

        //If there are "buffer" corner moves, remove if possible since there is a potential the other player could take the corner piece
        if(check_buffer){
            int counter = 0;
            for(int k = 0; k < i_mov.size(); k++)
            {
                if(i_mov[k] == 0 && j_mov[k] == 1
                || i_mov[k] == 0 && j_mov[k] == 6
                || i_mov[k] == 1 && j_mov[k] == 0
                || i_mov[k] == 1 && j_mov[k] == 1
                || i_mov[k] == 1 && j_mov[k] == 6
                || i_mov[k] == 1 && j_mov[k] == 7
                || i_mov[k] == 7 && j_mov[k] == 1
                || i_mov[k] == 7 && j_mov[k] == 6
                || i_mov[k] == 6 && j_mov[k] == 0
                || i_mov[k] == 6 && j_mov[k] == 1
                || i_mov[k] == 6 && j_mov[k] == 6
                || i_mov[k] == 6 && j_mov[k] == 7
                ){
                    counter++;
                }
            }

            if ( counter < i_mov.size() && counter >0)
            {
                vector<int> temp_i(i_mov);
                vector<int> temp_j(j_mov);

                i_mov.clear();
                j_mov.clear();
                for(int k = 0; k < temp_i.size(); k++){

                    if(temp_i[k] == 0 && temp_j[k] == 1
                    || temp_i[k] == 0 && temp_j[k] == 6
                    || temp_i[k] == 1 && temp_j[k] == 0
                    || temp_i[k] == 1 && temp_j[k] == 1
                    || temp_i[k] == 1 && temp_j[k] == 6
                    || temp_i[k] == 1 && temp_j[k] == 7
                    || temp_i[k] == 7 && temp_j[k] == 1
                    || temp_i[k] == 7 && temp_j[k] == 6
                    || temp_i[k] == 6 && temp_j[k] == 0
                    || temp_i[k] == 6 && temp_j[k] == 1
                    || temp_i[k] == 6 && temp_j[k] == 6
                    || temp_i[k] == 6 && temp_j[k] == 7
                    ){
                        continue;
                    }   
                    else{
                        i_mov.push_back(temp_i[k]);
                        j_mov.push_back(temp_j[k]);
                    }
            
                }

            }
        }
        
                
        
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

void heurMonteCarloMoves( char (&board)[BOARD_SIZE][BOARD_SIZE], vector<int> i_moves, vector<int> j_moves, char ai){

    vector<int> score;
    int totalScore = 0;
    char boardCopy[BOARD_SIZE][BOARD_SIZE];
    double max_time_per_move = MAX_TIMEOUT/((double)(i_moves.size()));
    bool is_corner = false;

    //if a corner move is available, always take it and skip the plays.
    for(int k = 0; k < i_moves.size(); k++){
        if(i_moves[k] == 0 && j_moves[k] == 0
        || i_moves[k] == 0 && j_moves[k] == 7 
        || i_moves[k] == 7 && j_moves[k] == 0
        || i_moves[k] == 7 && j_moves[k] == 7)
        {
            char input_i = i_moves[k] + 49;
            char input_j = j_moves[k] + 97;
            char input[3] = {input_j,input_i,0};

            updateBoardFromInput(board, input, ai);
            return;
        }

    }

    // Will try to remove any of the available moves that surround the corner (buffer corners)
    int counter = 0;
    for(int k = 0; k < i_moves.size(); k++)
    {
        if(i_moves[k] == 0 && j_moves[k] == 1
        || i_moves[k] == 0 && j_moves[k] == 6
        || i_moves[k] == 1 && j_moves[k] == 0
        || i_moves[k] == 1 && j_moves[k] == 1
        || i_moves[k] == 1 && j_moves[k] == 6
        || i_moves[k] == 1 && j_moves[k] == 7
        || i_moves[k] == 7 && j_moves[k] == 1
        || i_moves[k] == 7 && j_moves[k] == 6
        || i_moves[k] == 6 && j_moves[k] == 0
        || i_moves[k] == 6 && j_moves[k] == 1
        || i_moves[k] == 6 && j_moves[k] == 6
        || i_moves[k] == 6 && j_moves[k] == 7
        ){
            counter++;
        }
    }

    if ( counter < i_moves.size() && counter >0)
    {
        vector<int> temp_i(i_moves);
        vector<int> temp_j(j_moves);

        i_moves.clear();
        j_moves.clear();
        for(int k = 0; k < temp_i.size(); k++){

            if(temp_i[k] == 0 && temp_j[k] == 1
            || temp_i[k] == 0 && temp_j[k] == 6
            || temp_i[k] == 1 && temp_j[k] == 0
            || temp_i[k] == 1 && temp_j[k] == 1
            || temp_i[k] == 1 && temp_j[k] == 6
            || temp_i[k] == 1 && temp_j[k] == 7
            || temp_i[k] == 7 && temp_j[k] == 1
            || temp_i[k] == 7 && temp_j[k] == 6
            || temp_i[k] == 6 && temp_j[k] == 0
            || temp_i[k] == 6 && temp_j[k] == 1
            || temp_i[k] == 6 && temp_j[k] == 6
            || temp_i[k] == 6 && temp_j[k] == 7
            ){
                continue;
            }   
            else{
                i_moves.push_back(temp_i[k]);
                j_moves.push_back(temp_j[k]);
            }
        }
    }

    
    
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

            
            totalScore+= heurRandomMoves(boardCopy2,ai);
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


