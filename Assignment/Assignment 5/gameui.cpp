#include "ui/gameui.h"

BlockUi::BlockUi(QGridLayout* _layout, Game* _game) //BlockUi Constructor
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            block[i][j] = new QLabel; //블럭 칸 Label 생성
            block[i][j]->setFixedSize(250, 250); //블럭 칸 크기 설정
            if(_game->block_value(i, j) == 2) //블럭 값이 2이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(187, 173, 160); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("2"); //블럭 텍스트 2 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 4) //블럭 값이 4이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(237, 224, 200); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("4"); //블럭 텍스트 4 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 8) //블럭 값이 8이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(242, 177, 121); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("8"); //블럭 텍스트 8 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 16) //블럭 값이 16이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(245, 149, 99); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("16"); //블럭 텍스트 16 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 32) //블럭 값이 32이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(246, 126, 95); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("32"); //블럭 텍스트 32 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 64) //블럭 값이 64이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(246, 94, 59); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("64"); //블럭 텍스트 64 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 128) //블럭 값이 128이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(237, 207, 114); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("128"); //블럭 텍스트 128 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 256) //블럭 값이 256이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(237, 204, 97); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("256"); //블럭 텍스트 256 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 512) //블럭 값이 512이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(237, 200, 80); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("512"); //블럭 텍스트 512 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 1024) //블럭 값이 1024이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(237, 197, 63); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("1024"); //블럭 텍스트 1024 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 2048) //블럭 값이 2048이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(237, 194, 46); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
                block[i][j]->setText("2048"); //블럭 텍스트 2048 설정
                block[i][j]->setAlignment(Qt::AlignCenter); //중앙 정렬
            }
            else if(_game->block_value(i, j) == 0) //블럭 값이 0이면
            {
                block[i][j]->setStyleSheet("QLabel { background: rgb(255, 255, 255); border-style: solid; font: 70pt; font: bold; }"); //블럭 스타일 값에 따라 설정
            }

            _layout->addWidget(block[i][j], i, j, Qt::AlignCenter); //레이아웃에 블럭 위젯 추가
        }
    }
}

BlockUi::~BlockUi() //BlockUi Destructor
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            delete block[i][j]; //블럭 칸 Label 동적 할당 해제
        }
    }
}

Win::Win(GameUi* _gameui, QObject* parent) : QThread(parent) //Win Constructor
{
    gameui = _gameui; //gameui 연결
}

void Win::run() //Win Thread run
{
    if(gameui->game->continue_or_end_check() == 0 && gameui->game->lose_or_win_check() == 1) //승리한 경우
    {
        sleep(1); //1초 지연
        emit showWin(); //signal 전달
    }
}

GameUi::GameUi(Game* _game)
{
    game = _game; //진행 되는 게임 연결

    main_layout = new QGridLayout(this); //메인 레이아웃 생성
    main_layout->setSpacing(10); //레이아웃 간격 10 설정
    block_layout = new QGridLayout(this); //블럭 레이아웃 생성
    other_layout = new QGridLayout(this); //여백 레이아웃 생성
    main_layout->addLayout(block_layout, 0, 0); //메인 레이아웃에 블럭 레이아웃 추가
    main_layout->addLayout(other_layout, 0, 1); //메인 레이아웃에 여백 레이아웃 추가
    this->setWindowTitle("2048 Puzzle Game"); //창 제목 "2048 Puzzle Game"으로 설정
    QWidget::resize(1300, 1000); //위젯 크기 설정
    score = new QLabel("Score: " + QString::number(game->get_score()), this); //점수 Label 생성
    score->setAlignment(Qt::AlignHCenter); //점수 Label 높이 중앙 정렬
    score->setFixedSize(300, 200); //점수 Label 크기 설정
    QFont score_font = score->font(); //점수 Label 폰트 설정
    score_font.setPointSize(30); //점수 Label 폰트 크기 30으로 설정
    score->setFont(score_font); //점수 Label과 점수 Label 폰트 연결
    other_layout->addWidget(score, 0, 0, 3, 1, Qt::AlignTop); //여백 레이아웃 내의 점수 Label 위젯 추가

    restore_button = new QPushButton("Restore", this); //복구 버튼 생성
    exit_button = new QPushButton("Exit", this); //나가기 버튼 생성
    restore_button->setFixedSize(300, 200); //복구 버튼 크기 설정
    exit_button->setFixedSize(300, 200); //나가기 버튼 크기 설정
    QFont restore_font = restore_button->font(); //복구 버튼 폰트 설정
    QFont exit_font = exit_button->font(); //나가기 버튼 폰트 설정
    restore_font.setPointSize(20); //복구 버튼 폰트 크기 20으로 설정
    exit_font.setPointSize(20); //나가기 버튼 폰트 크기 20으로 설정
    restore_button->setFont(restore_font); //복구 버튼과 복구 버튼 폰트 연결
    exit_button->setFont(exit_font); //나가기 버튼과 나가기 버튼 폰트 연결

    connect(restore_button, SIGNAL(clicked()), this, SLOT(restore_button_clicked())); //복구 버튼과 복구 버튼을 눌렀을 때의 신호 연결
    connect(exit_button, SIGNAL(clicked()), this, SLOT(exit_button_clicked())); //나가기 버튼과 나가기 버튼을 눌렀을 때의 신호 연결

    other_layout->addWidget(restore_button, 4, 0, 1, 1, Qt::AlignBottom); //여백 레이아웃에 복구 버튼 위젯 추가
    other_layout->addWidget(exit_button, 5, 0, 1, 1, Qt::AlignBottom); //여백 레이아웃에 나가기 버튼 위젯 추가

    _win = new Win(this, this); //Win Thread 생성
    connect(_win, SIGNAL(showWin()), this, SLOT(win_message())); //승리했을 때와 승리 메시지 출력 신호 연결

    game->game_start(); //게임 시작
    print_block(); //블럭 출력
}

GameUi::~GameUi()
{
    delete block_ui; //BlockUi 동적 할당 해제
    delete block_layout; //블럭 레이아웃 동적 할당 해제
    delete other_layout; //여백 레이아웃 동적 할당 해제
    delete main_layout; //메인 레이아웃 동적 할당 해제
    delete score; //점수 Label 동적 할당 해제
    delete restore_button; //복구 버튼 동적 할당 해제
    delete exit_button; //나가기 버튼 동적 할당 해제
    delete _win; //Win Thread 동적 할당 해제
}

void GameUi::print_block() //블럭 출력
{
    block_ui = new BlockUi(block_layout, game); //새 BlockUi 생성
}

void GameUi::score_update() //점수 업데이트
{
    score->setText("Score: " + QString::number(game->get_score())); //점수 Label 점수 업데이트
}

void GameUi::lose_message() //패배 메시지 출력
{
    QMessageBox* lose_box = new QMessageBox(this); //패배 메시지 박스 생성
    lose_box->resize(300, 200); //패배 메시지 박스 크기 설정
    lose_box->setWindowTitle("Lose"); //패배 메시지 박스 창 제목 설정
    lose_box->setText("You lose..."); //패배 메시지 설정
    lose_box->setInformativeText("Score: " + QString::number(game->get_score())); //점수 출력
    lose_box->setStandardButtons(QMessageBox::Ok); //Ok 버튼 설정
    if(lose_box->exec() == QMessageBox::Ok) //Ok 버튼을 누를 경우
    {
        exit(0); //종료
    }
}

void GameUi::win_message() //승리 메시지 출력
{
    QMessageBox* win_box = new QMessageBox(this); //승리 메시지 박스 생성
    win_box->resize(300, 200); //승리 메시지 박스 크기 설정
    win_box->setWindowTitle("Win"); //승리 메시지 박스 창 제목 설정
    win_box->setText("Congratulation!"); //승리 메시지 설정
    win_box->setInformativeText("Score: " + QString::number(game->get_score())); //점수 출력
    win_box->setStandardButtons(QMessageBox::Ok); //Ok 버튼 설정
    if(win_box->exec() == QMessageBox::Ok) //Ok 버튼을 누를 경우
    {
        exit(0); //종료
    }
}

void GameUi::restore_button_clicked() //복구 버튼을 누른 경우
{
    QMessageBox* restore_box = new QMessageBox(this); //복구 메시지 박스 생성
    restore_box->resize(300, 200); //복구 메시지 박스 크기 설정
    restore_box->setWindowTitle("Restore"); //복구 메시지 박스 창 제목 설정
    restore_box->setText("Restore the game board to its previous state?"); //복구 여부 메시지 설정
    restore_box->setInformativeText("Remaining chances: " + QString::number(game->get_restore_chance())); //남은 복구 기회 출력
    restore_box->setStandardButtons(QMessageBox::Yes | QMessageBox::No); //Yes 버튼, No 버튼 설정
    restore_box->setDefaultButton(QMessageBox::No); //No 버튼을 기본값으로 설정
    if(restore_box->exec() == QMessageBox::Yes) //Yes 버튼을 누를 경우
    {
        if(game->check_previous_board() == false) //이전 보드 판이 비어 있는 경우
        {
            QMessageBox* no_restore = new QMessageBox(this); //복구 불가 메시지 박스 생성
            no_restore->resize(300, 200); //복구 불가 메시지 박스 크기 설정
            no_restore->setWindowTitle("Restore"); //복구 불가 메시지 박스 창 제목 설정
            no_restore->setText("There is no previously saved board in the buffer."); //복구 불가 메시지 설정
            no_restore->setStandardButtons(QMessageBox::Ok); //Ok 버튼 설정
            if(no_restore->exec() == QMessageBox::Ok) //Ok 버튼을 누를 경우
            {
                setFocus(); //창 Focus 설정
                return;
            }
        }
        else //이전 보드 판이 존재하는 경우
        {
            if(game->get_restore_chance() == 0) //복구 기회가 0인 경우
            {
                QMessageBox* restore_fail = new QMessageBox(this); //복구 실패 메시지 박스 생성
                restore_fail->resize(300, 200); //복구 실패 메시지 박스 크기 설정
                restore_fail->setWindowTitle("Restore"); //복구 실패 메시지 박스 창 제목 설정
                restore_fail->setText("No more chance to restore the board to its previous state."); //복구 실패 메시지 설정
                restore_fail->setStandardButtons(QMessageBox::Ok); //Ok 버튼 설정
                if(restore_fail->exec() == QMessageBox::Ok) //Ok 버튼을 누를 경우
                {
                    setFocus(); //창 Focus 설정
                    return;
                }
            }
            else //복구 기회가 있는 경우
            {
                game->use_chance(); //복구 기회 사용
                game->restore_board(); //보드 판 복구
                game->subtract_score(); //점수 복구
                game->restore_state(); //상태 업데이트
                print_block(); //블럭 출력
                score_update(); //점수 업데이트
                QMessageBox* restore_complete = new QMessageBox(this); //복구 성공 메시지 박스 생성
                restore_complete->resize(300, 200); //복구 성공 메시지 박스 크기 설정
                restore_complete->setWindowTitle("Restore"); //복구 성공 메시지 박스 창 제목 설정
                restore_complete->setText("The board has been restored to its previous state!"); //복구 성공 메시지 설정
                restore_complete->setStandardButtons(QMessageBox::Ok); //Ok 버튼 설정
                if(restore_complete->exec() == QMessageBox::Ok) //Ok 버튼을 누를 경우
                {
                    setFocus(); //창 Focus 설정
                    return;
                }
            }
        }
    }
    else //No 버튼을 누를 경우
    {
        setFocus(); //창 Focus 설정
        return;
    }
}

void GameUi::exit_button_clicked() //나가기 버튼을 누른 경우
{
    QMessageBox* exit_box = new QMessageBox(this); //나가기 메시지 박스 생성
    exit_box->resize(300, 200); //나가기 메시지 박스 크기 설정
    exit_box->setWindowTitle("Exit"); //나가기 메시지 박스 창 제목 설정
    exit_box->setText("Are you sure to quit?"); //나가기 여부 메시지 설정
    exit_box->setStandardButtons(QMessageBox::Yes | QMessageBox::No); //Yes 버튼, No 버튼 설정
    exit_box->setDefaultButton(QMessageBox::No); //No 버튼을 기본값으로 설정
    if(exit_box->exec() == QMessageBox::Yes) //Yes 버튼을 누를 경우
    {
        exit(0); //종료
    }
    else //No 버튼을 누를 경우
    {
        setFocus(); //창 Focus 설정
        return;
    }
}

void GameUi::keyPressEvent(QKeyEvent *event) //방향키를 누른 경우
{
    if(event->type() == QEvent::KeyPress) //방향키를 누른 경우
    {
        if(game->continue_or_end_check() == 0 && game->lose_or_win_check() == -1) //게임 종료 및 패배한 경우
        {
            lose_message(); //패배 메시지 출력
        }

        QKeyEvent *key = event;

        if(key->key() == Qt::Key_Left) //왼쪽 방향키를 누른 경우
        {
            game->game_continue(75); //왼쪽으로 이동 진행
        }
        else if(key->key() == Qt::Key_Right) //오른쪽 방향키를 누른 경우
        {
            game->game_continue(77); //오른쪽으로 이동 진행
        }
        else if(key->key() == Qt::Key_Up) //위쪽 방향키를 누른 경우
        {
            game->game_continue(72); //위쪽으로 이동 진행
        }
        else if(key->key() == Qt::Key_Down) //아래쪽 방향키를 누른 경우
        {
            game->game_continue(80); //아래쪽으로 이동 진행
        }
        print_block(); //블럭 출력
        score_update(); //점수 업데이트

        _win->start(); //승리 메시지 출력 확인
    }
}
