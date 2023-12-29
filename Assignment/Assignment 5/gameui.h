#ifndef GAMEUI_H
#define GAMEUI_H

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>
#include <QThread>
#include "game/game.h"

class BlockUi : public QLabel //BlockUi 클래스
{
public:
    BlockUi(QGridLayout* _layout, Game* _game); //BLockUi Constructor
    ~BlockUi(); //BlockUi Destructor

private:
    QLabel *block[4][4]; //블럭 칸 Label
};

class GameUi;

class Win : public QThread //Win Thread 클래스
{
    Q_OBJECT

public:
    explicit Win(GameUi* _gameui, QObject* parent = 0); //Win Constructor

private:
    void run(); //Win Thread 실행
    GameUi* gameui; //게임 ui
signals:
    void showWin(); //승리 메시지 출력 신호
};

class GameUi : public QWidget //GameUi 클래스
{
    Q_OBJECT

public:
    GameUi(Game* _game); //GameUi Constructor
    ~GameUi(); //GameUi Destructor
    Game* game; //게임

    void print_block(); //블럭 출력
    void score_update(); //점수 업데이트
    void lose_message(); //패배 메시지 출력

private slots:
    void restore_button_clicked(); //복구 버튼 누른 경우
    void exit_button_clicked(); //나가기 버튼 누른 경우
    void keyPressEvent(QKeyEvent *event); //방향키를 누른 경우
    void win_message(); //승리 메시지 출력


private:
    BlockUi* block_ui; //BlockUi
    QGridLayout *main_layout; //메인 레이아웃
    QGridLayout *block_layout; //블럭 레이아웃
    QGridLayout *other_layout; //여백 레이아웃
    QLabel *score; //점수 Label
    QPushButton *restore_button; //복구 버튼
    QPushButton *exit_button; //나가기 버튼
    Win* _win;
};

#endif // GAMEUI_H
