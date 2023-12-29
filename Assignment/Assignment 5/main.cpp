#include "ui/gameui.h" //"gameui" header file
#include "game/game.h" //"game" header file

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game; //게임 생성
    GameUi w(&game); //게임 UI 생성
    w.setFocus(); //창 Focus 설정
    w.show(); //창 show

    return a.exec(); //실행
}
