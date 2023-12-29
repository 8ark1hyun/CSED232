#include "game/game.h"

Block::Block() //Block Constructor
{
    value = 0; //블럭 값 초기화
}

Board::Board() //Board Constructor
{
    board = new Block*[4]; //보드 판 배열 생성
    for(int i = 0; i < 4; i++)
    {
        board[i] = new Block[4]; //보드 판 배열 생성 -> 2차원 배열
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            board[i][j].value = 0; //보드 판 블럭 값 초기화
        }
    }
}

Board::~Board() //Board Destructor
{
    for(int i = 0; i < 4; i++)
    {
        delete[] board[i]; //보드 판 동적 할당 해제
    }

    delete[] board; //보드 판 동적 할당 해제
}

int Board::new_board() //새 보드 판 생성
{
    int num = 0;
    Block* new_board[16]; //새 보드 판 주소 저장 배열

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j].value == 0) //보드 판 블럭 값이 0이면
            {
                new_board[num] = &board[i][j]; //보드 판 주소 저장
                num++;
            }
        }
    }
    srand(time(NULL));
    int k = rand() % num; //0~15 사이의 랜덤 값 생성
    new_board[k]->value = 2; //랜덤한 위치의 블럭 값 2로 설정

    int pos;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(new_board[k] == &board[i][j]) //값이 생성된 블럭이면
            {
                pos = 4 * i + j; //블럭이 생성된 보드 판 위치 저장
            }
        }
    }

    return pos; //위치 반환
}

void Board::new_value(int *arr) //새 값 생성
{
    int num = 0;
    Block* empty[16]; //빈 보드 판 주소 저장 배열

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j].value == 0) //보드 판 블럭 값이 0이면
            {
                empty[num] = &board[i][j]; //보드 판 주소 저장
                num++;
            }
        }
    }
    srand(time(NULL));
    int k = rand() % num; //0~(빈 블럭 개수-1) 사이의 랜덤 값 생성
    int two_or_four = rand() % 100; //2 또는 4 확률 설정
    if(two_or_four < 80) //2가 생성되는 경우
    {
        empty[k]->value = 2; //랜덤한 위치의 블럭 값 2로 설정
        arr[1] = 2; //생성된 값 저장
    }
    else //4가 생성되는 경우
    {
        empty[k]->value = 4; //랜덤한 위치의 블럭 값 4로 설정
        arr[1] = 4; //생성된 값 저장
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(empty[k] == &board[i][j]) //값이 생성된 블럭이면
            {
                arr[0] = 4 * i +j; //블럭이 생성된 보드 판 위치 저장
            }
        }
    }

    return;
}

int Board::left(int arr[][4]) //왼쪽으로 이동
{
    int up_score = 0;
    bool zero = false;
    bool change = false;
    bool check[4][4] = { {false} };

    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            for(int k = j - 1; k >= 0; k--)
            {
                if(board[i][k].value == 0) //블럭 값이 0이면
                {
                    zero = true; //빈 블럭 확인
                    if(board[i][k+1].value == 0) //옆 블럭 값 역시 0이면
                    {
                        continue; //계속 반복 진행
                    }
                    else //옆 블럭 값이 0이 아니면
                    {
                        board[i][k].value = board[i][k+1].value; //옆 블럭에서 현재 블럭으로 값 이동
                        board[i][k+1].value = 0; //옆 블럭 값 0으로 초기화
                        change = true; //변화 확인
                    }
                }
                else //블럭 값이 0이 아니면
                {
                    if(board[i][k+1].value == 0) //옆 블럭 값이 0이면
                    {
                        zero = true; //빈 블럭 확인
                        continue; //계속 반복 진행
                    }
                    else if (board[i][k+1].value != 0 && board[i][k].value != board[i][k+1].value) //옆 블럭 값이 0이 아니지만 옆 블럭과 값이 다르면
                    {
                        continue; //계속 반복 진행
                    }
                    else if(board[i][k].value == board[i][k+1].value) //옆 블럭과 값이 같으면
                    {
                        if(check[i][k] == false && check[i][k+1] == false) //확인을 안 한 블럭이면
                        {
                            board[i][k].value *= 2; //현재 블럭 값 2배 (= 병합)
                            board[i][k+1].value = 0; //옆 블럭 값 0으로 초기화
                            check[i][k] = true; //블럭 확인 기록
                            up_score += board[i][k].value; //생성된 블럭 값만큼 점수 추가
                            change = true; //변화 확인

                            arr[i][k] = 1; //병합된 위치 기록
                        }
                        else //확인을 한 블럭이 있으면
                        {
                            continue; //계속 반복 진행
                        }
                    }
                }
            }
        }
    }

    if(change == false) //변화가 없으면
    {
        if(zero == false) //빈 블럭이 없으면
        {
            return -2; //-2 반환
        }
        else //빈 블럭이 있으면
        {
            return -1; //-1 반환
        }
    }
    else //변화가 있으면
    {
        return up_score; //오른 점수 반환
    }
}

int Board::right(int arr[][4]) //오른쪽으로 이동
{
    int up_score = 0;
    bool zero = false;
    bool change = false;
    bool check[4][4] = { {false} };

    for(int i = 0; i < 4; i++)
    {
        for(int j = 2; j >= 0; j--)
        {
            for(int k = j+1; k < 4; k++)
            {
                if(board[i][k].value == 0) //블럭 값이 0이면
                {
                    zero = true; //빈 블럭 확인
                    if(board[i][k-1].value == 0) //옆 블럭 값 역시 0이면
                    {
                        continue; //계속 반복 진행
                    }
                    else //옆 블럭 값이 0이 아니면
                    {
                        board[i][k].value = board[i][k-1].value; //옆 블럭에서 현재 블럭으로 값 이동
                        board[i][k-1].value = 0; //옆 블럭 값 0으로 초기화
                        change = true; //변화 확인
                    }
                }
                else //블럭 값이 0이 아니면
                {
                    if(board[i][k-1].value == 0) //옆 블럭 값이 0이면
                    {
                        zero = true; //빈 블럭 확인
                        continue; //계속 반복 진행
                    }
                    else if (board[i][k-1].value != 0 && board[i][k].value != board[i][k-1].value) //옆 블럭 값이 0아니지만 옆 블럭과 값이 다르면
                    {
                        continue; //계속 반복 진행
                    }
                    else if(board[i][k].value == board[i][k-1].value) //옆 블럭과 값이 같으면
                    {
                        if(check[i][k] == false && check[i][k-1] == false) //확인을 안 한 블럭이면
                        {
                        board[i][k].value *= 2; //현재 블럭 값 2배 (= 병합)
                        board[i][k-1].value = 0; //옆 블럭 값 0으로 초기화
                        check[i][k] = true; //블럭 확인 기록
                        up_score += board[i][k].value; //생성된 블럭 값만큼 점수 추가
                        change = true; //변화 확인

                        arr[i][k] = 1; //병합된 위치 기록
                        }
                        else //확인을 한 블럭이 있으면
                        {
                            continue; //계속 반복 진행
                        }
                    }
                }
            }
        }
    }

    if(change == false) //변화가 없으면
    {
        if(zero == false) //빈 블럭이 없으면
        {
            return -2; //-2 반환
        }
        else //빈 블럭이 있으면
        {
            return -1; //-1 반환
        }
    }
    else //변화가 있으면
    {
        return up_score; //오른 점수 반환
    }
}

int Board::up(int arr[][4]) //위로 이동
{
    int up_score = 0;
    bool zero = false;
    bool change = false;
    bool check[4][4] = { {false} };

    for(int j = 0; j < 4; j++)
    {
        for(int i = 1; i < 4; i++)
        {
            for(int k = i-1; k >=0; k--)
            {
                if(board[k][j].value == 0) //블럭 값이 0이면
                {
                    zero = true; //빈 블럭 확인
                    if(board[k+1][j].value == 0) //아래 블럭 값 역시 0이면
                    {
                        continue; //계속 반복 진행
                    }
                    else //아래 블럭 값이 0이 아니면
                    {
                        board[k][j].value = board[k+1][j].value; //아래 블럭에서 현재 블럭으로 값 이동
                        board[k+1][j].value = 0; //아래 블럭 값 0으로 초기화
                        change = true; //변화 확인
                    }
                }
                else //블럭 값이 0이 아니면
                {
                    if(board[k+1][j].value == 0) //아래 블럭 값이 0이면
                    {
                        zero = true; //빈 블럭 확인
                        continue; //계속 반복 진행
                    }
                    else if (board[k+1][j].value != 0 && board[k][j].value != board[k+1][j].value) //아래 블럭 값이 0이 아니지만 아래 블럭과 값이 다르면
                    {
                        continue; //계속 반복 진행
                    }
                    else if(board[k][j].value == board[k+1][j].value) //아래 블럭과 값이 같으면
                    {
                        if(check[k][j] == false && check[k+1][j] == false) //확인을 안 한 블럭이면
                        {
                            board[k][j].value *= 2; //현재 블럭 값 2배 (= 병합)
                            board[k+1][j].value = 0; //아래 블럭 값 0으로 초기화
                            check[k][j] = true; //블럭 확인 기록
                            up_score += board[k][j].value; //생성된 블럭 값만큼 점수 추가
                            change = true; //변화 확인

                            arr[k][j] = 1; //병합된 위치 기록
                        }
                        else //확인을 한 블럭이 있으면
                        {
                            continue; //계속 반복 진행
                        }
                    }
                }
            }
        }
    }

    if(change == false) //변화가 없으면
    {
        if(zero == false) //빈 블럭이 없으면
        {
            return -2; //-2 반환
        }
        else //빈 블럭이 있으면
        {
            return -1; //-1 반환
        }
    }
    else //변화가 있으면
    {
        return up_score; //오른 점수 반환
    }
}

int Board::down(int arr[][4]) //아래로 이동
{
    int up_score = 0;
    bool zero = false;
    bool change = false;
    bool check[4][4] = { {false} };

    for(int j = 0; j < 4; j++)
    {
        for(int i = 2; i >= 0; i--)
        {
            for(int k = i + 1; k < 4; k++)
            {
                if(board[k][j].value == 0) //블럭 값이 0이면
                {
                    zero = true; //빈 블럭 확인
                    if(board[k-1][j].value == 0) //위 블럭 값 역시 0이면
                    {
                        continue; //계속 반복 진행
                    }
                    else //위 블럭 값이 0이 아니면
                    {
                        board[k][j].value = board[k-1][j].value; //위 블럭에서 현재 블럭으로 값 이동
                        board[k-1][j].value = 0; //위 블럭 값 0으로 초기화
                        change = true; //변화 확인
                    }
                }
                else //블럭 값이 0이 아니면
                {
                    if(board[k-1][j].value == 0) //위 블럭 값이 0이면
                    {
                        zero = true; //빈 블럭 확인
                        continue; //계속 반복 진행
                    }
                    else if (board[k-1][j].value != 0 && board[k][j].value != board[k-1][j].value) //위 블럭 값이 0이 아니지만 위 블럭과 같이 다르면
                    {
                        continue; //계속 반복 진행
                    }
                    else if(board[k][j].value == board[k-1][j].value) //위 블럭과 값이 같으면
                    {
                        if(check[k][j] == false && check[k-1][j] == false) //확인을 안 한 블럭이면
                        {
                            board[k][j].value *= 2; //현재 블럭 값 2배 (= 병합)
                            board[k-1][j].value = 0; //위 블럭 값 0으로 초기화
                            check[k][j] = true; //블럭 확인 기록
                            up_score += board[k][j].value; //생성된 블럭 값만큼 점수 추가
                            change = true; //변화 확인

                            arr[k][j] = 1; //병합된 위치 기록
                        }
                        else //확인을 한 블럭이 있으면
                        {
                            continue; //계속 반복 진행
                        }
                    }
                }
            }
        }
    }

    if(change == false) //변화가 없으면
    {
        if(zero == false) //빈 블럭이 없으면
        {
            return -2; //-2 반환
        }
        else //빈 블럭이 있으면
        {
            return -1; //-1 반환
        }
    }
    else //변화가 있으면
    {
        return up_score; //오른 점수 반환
    }
}


Game::Game() //Game Constructor
{
    File.open("progress.txt"); //파일 열기

    game_board = new Board; //새 게임 보드 판 생성
    previous_board = nullptr; //이전 보드 판 nullptr로 초기화
    score = 0; //점수 초기화
    temp_score = 0; //임시 점수 초기화
    restore_chance = 3; //복구 기록 3으로 초기화
    continue_or_end = 1; //진행 또는 종료 1(진행)로 설정
    lose_or_win = 0; //패배 또는 승리 0(미정)으로 설정
}

Game::~Game() //Game Desturctor
{
    delete game_board; //게임 보드 판 동적 할당 해제
    delete previous_board; //이전 보드 판 동적 할당 해제

    File.close(); //파일 닫기
}

void Game::game_start() //게임 시작
{
    File << "INITIAL "; //파일에 "INITIAL" 출력

    int a = game_board->new_board(); //새 블럭 값 생성 (a = 블럭이 생성된 보드 판 위치)
    int b = game_board->new_board(); //새 블럭 값 생성 (b = 블럭이 생성된 보드 판 위치)

    if(a / 4 < b / 4) //행이 작은 것 먼저 기록
    {
        File << a / 4 + 1 << " " << a % 4 + 1 << " " << b / 4 + 1 << " " << b % 4 + 1 << std::endl; //블럭이 생성된 보드 판 위치 출력
    }
    else if (a / 4 == b / 4) //행이 같으면
    {
        if(a % 4 < b % 4) //열이 작은 것 먼저 기록
        {
            File << a / 4 + 1 << " " << a % 4 + 1 << " " << b / 4 + 1 << " " << b % 4 + 1 << std::endl; //블럭이 생성된 보드 판 위치 출력
        }
        else //열이 작은 것 먼저 기록
        {
            File << b / 4 + 1 << " " << b % 4 + 1 << " " << a / 4 + 1 << " " << a % 4 + 1 << std::endl; //블럭이 생성된 보드 판 위치 출력
        }
    }
    else //행이 작은 것 먼저 기록
    {
        File << b / 4 + 1 << " " << b % 4 + 1 << " " << a / 4 + 1 << " " << a % 4 + 1 << std::endl; //블럭이 생성된 보드 판 위치 출력
    }
}

void Game::game_continue(int i) //게임 진행
{
    int k;
    bool over_check = false;

    Board* temp_board = new Board; //임시 보드 판 생성
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            temp_board->change_value(i, j, game_board->block_value(i, j)); //임시 보드 판에 현재 보드 판 블럭 값 기록
        }
    }

    int merge[4][4] = { { 0 } };
    if(i == 75) //왼쪽 방향키를 누른 경우
    {
        File << "LEFT" << std::endl; //"LEFT" 출력
        k = game_board->left(merge); //왼쪽으로 이동
    }
    else if (i == 77) //오른쪽 방향키를 누른 경우
    {
        File << "RIGHT" << std::endl; //"RIGHT" 출력
        k = game_board->right(merge); //오른쪽으로 이동
    }
    else if (i == 72) //위쪽 방향키를 누른 경우
    {
        File << "UP" << std::endl; //"UP" 출력
        k = game_board->up(merge); //위로 이동
    }
    else if (i == 80) //아래쪽 방향키를 누른 경우
    {
        File << "DOWN" << std::endl; //"DOWN" 출력
        k = game_board->down(merge); //아래로 이동
    }
    else //방향키 입력이 아닌 경우
    {
        return; //입력 받는 곳으로 돌아감
    }

    if(k == -2) //이동 후 반환 값이 -2이면
    {
        over_check = true; //게임을 종료할지 확인
    }
    else if(k == -1) //-1이면
    {
        return; //입력 받는 곳으로 돌아감
    }
    else
    {
        previous_board = new Board; //이전 보드 판 생성
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                previous_board->change_value(i, j, temp_board->block_value(i, j)); //이전 보드 판에 임시 보드 판에 저장했던 값으로 저장
            }
        }
        delete temp_board; //임시 보드 판 동적 할당 해제
        temp_board = nullptr; //임시 보드 판 nullptr로 초기화

        if(k != 0) //0이 아니면
        {

            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(merge[i][j] == 1) //병합된 위치 탐색
                    {
                        File << "MERGE "; //"MERGE" 출력
                        File << i + 1 << " " << j + 1 << " " << game_board->block_value(i, j) << std::endl; //병합된 블럭 위치와 블럭 값 출력
                    }
                }
            }
        }

        over_check = true; //게임을 종료할지 확인

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(game_board->block_value(i, j) == 2048) //생성된 블럭 값이 2048이면
                {
                    continue_or_end = 0; //게임 종료 표시
                    lose_or_win = 1; //승리 표시
                    over_check = false;
                }
            }
        }
        int generate[2];
        game_board->new_value(generate); //보드 판에 새 블럭 생성
        File << "GENERATE "; //"GENERATE" 출력
        File << generate[0] / 4 + 1 << " " << generate[0] % 4 + 1 << " " << generate[1] << std::endl; //새로 생성된 블럭 위치와 블럭 값 출력

        add_score(k); //병합된 블럭 값만큼 점수 추가
        temp_score = k; //임시 점수에 현재 점수 저장
    }

    if(over_check == true) //게임을 종료할지 확인
    {
        bool change = false;
        bool zero = false;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(game_board->block_value(i, j) == game_board->block_value(i, j+1) || game_board->block_value(i, j) == game_board->block_value(i+1, j)) //병합 가능한 블럭이 있으면
                {
                    change = true; //변화 가능 확인
                }
                if(game_board->block_value(i, j) == 0) //0인 블럭이 있으면
                {
                    zero = true; //빈 블럭 확인
                }
            }
        }
        for(int i = 0; i < 3; i++)
        {
            if(game_board->block_value(i, 3) == game_board->block_value(i+1, 3)) //병합 가능한 블럭이 있으면
            {
                change = true; //변화 가능 확인
            }
            if(game_board->block_value(i, 3) == 0) //0인 블럭이 있으면
            {
                zero = true; //빈 블럭 확인
            }
        }
        for(int j = 0; j < 3; j++)
        {
            if(game_board->block_value(3, j) == game_board->block_value(3, j+1)) //병합 가능한 블럭이 있으면
            {
                change = true; //변화 가능 확인
            }
            if(game_board->block_value(3, j) == 0) //0인 블럭이 있으면
            {
                zero = true; //빈 블럭 확인
            }
        }
        if(game_board->block_value(3, 3) == 0) //0인 블럭이 있으면
        {
            zero = true; //빈 블럭 확인
        }

        if(zero == false && change == false) //빈 블럭이 없고 변화가 불가능하면
        {
            continue_or_end = 0; //게임 종료 표시
            lose_or_win = -1; //패배 표시
        }
    }

    return;
}

void Game::restore_board() //보드 판 복구
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            game_board->change_value(i, j, previous_board->block_value(i, j)); //게임 보드 판 블럭 값 복구
        }
    }

    delete previous_board; //이전 보드 판 동적 할당 해제
    previous_board = nullptr; //이전 보드 판 nullptr로 초기화
}
