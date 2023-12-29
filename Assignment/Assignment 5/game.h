#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

class Block //Block 클래스
{
public:
    int value; //블럭 값

    Block(); //Block Constructor
    ~Block() {} //Block Destructor
};

class Board //Board 클래스
{
public:
    Board(); //Board Costructor
    ~Board(); //Board Destructor
    int new_board(); //새 보드 판 생성
    void new_value(int* arr); //새 값 생성
    int left(int arr[][4]); //왼쪽으로 이동
    int right(int arr[][4]); //오른쪽으로 이동
    int up(int arr[][4]); //위로 이동
    int down(int arr[][4]); //아래로 이동
    int block_value(int i, int j) { return board[i][j].value; } //블럭 값 반환
    void change_value(int i, int j, int value) { board[i][j].value = value; } //블럭 값 변환

private:
    Block** board; //보드 판

};

class Game //Game 클래스
{
public:
    Game(); //Game Contructor
    ~Game(); //Game Destructor
    void game_start(); //게임 시작
    void game_continue(int i); //게임 진행
    int block_value(int i, int j) { return game_board->block_value(i, j); } //블럭 값 반환
    int get_score() { return score; } //점수 반환
    int get_restore_chance() { return restore_chance; } //복구 기회 반환
    void use_chance() { restore_chance--; File << "RESTORE " << restore_chance << std::endl; } //복구 기회 사용
    int continue_or_end_check() { return continue_or_end; } //진행 또는 종료 확인
    int lose_or_win_check() { return lose_or_win; } //패배 또는 승리 확인
    bool check_previous_board() { if(previous_board == nullptr){ return false; } else{ return true; } } //이전 보드 판 확인
    void restore_board(); //보드 판 복구
    void add_score(int i) { score += i; File << "SCORE " << score << std::endl; } //점수 추가
    void subtract_score() { score -= temp_score; temp_score = 0; } //점수 복구
    void restore_state() { continue_or_end = 1; lose_or_win = 0; } //상태 업데이트

private:
    std::ofstream File; //출력 파일

    Board* game_board; //게임 보드 판
    Board* previous_board; //이전 보드 판
    int score; //점수
    int temp_score; //임시 점수
    int restore_chance; //복구 기회
    int continue_or_end; //진행 또는 종료
    int lose_or_win; //패배 또는 승리
};

#endif // GAME_H
