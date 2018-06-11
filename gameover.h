#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

namespace Ui {
class Gameover;
}

class Gameover : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gameover(QWidget *parent = 0);
    ~Gameover();

private:
    Ui::Gameover *ui;
};

#endif // GAMEOVER_H
