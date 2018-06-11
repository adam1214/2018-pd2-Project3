#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTimer>
#include<unistd.h>
#include<QObject>
#include<QGraphicsScene>
#include "myitem.h"
#include<QPointF>
#include"player.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "polyitem.h"
#include"super_skill_times.h"

MyItem e;
Player p;
PolyItem *enemy=&e;
PolyItem *player=&p;
//MyItem *enemy=new MyItem();
//Player *player=new Player();

int x,y;
int cnt_R=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 1201, 871))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1201, 871);

    timer=new QTimer(this);
    timer->start(10);
    timer1=new QTimer(this);
    timer1->start(100);
    timer3=new QTimer(this);
    timer3->start(500);
    timer4=new QTimer(this);
    timer4->start(1);


    //player = new QGraphicsPixmapItem(QPixmap(":/res/reimu.jpg").scaled(70, 70));
    scene->addItem(player);
    player->setPos(500, 500);

    scene->addItem(enemy);
    enemy->setPos(enemy_x,enemy_y);

    score = new Score();
    scene->addItem(score);

    Enemy_HP = new Health();
    Enemy_HP->setPos(Enemy_HP->x(),Enemy_HP->y()+25);
    scene->addItem(Enemy_HP);

    player_HP = new Player_HP();
    player_HP->setPos(player_HP->x(),player_HP->y()+50);
    scene->addItem(player_HP);

    s=new Super_skill_times();
    s->setPos(s->x(),s->y()+75);
    scene->addItem(s);

    connect(timer1,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(enemy_shot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        if(player->y()>0)
            player->setPos(player->x(), player->y() - 10);
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if(player->y()<800)
            player->setPos(player->x(), player->y() + 10);
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if(player->x()>0)
            player->setPos(player->x() - 10, player->y());
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if(player->x()<1130)
            player->setPos(player->x() + 10, player->y());
        break;
    case Qt::Key_E:
    {
        bullet *b = new bullet;
        b->setPixmap(QPixmap(":/res/red_bullet.png").scaled(30, 30));
        b->setPos(player->getX()+12,player->getY());
        //b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2, player->y() - b->pixmap().height());
        b->connect(timer, SIGNAL(timeout()), b, SLOT(fly_up()));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
        break;
        //b->setData(x,b->getX());
        //b->setData(y,b->getY());
        //connect(timer4,SIGNAL(timeout()),this,SLOT(enemy_HP()));

    }
    case Qt::Key_R:
    {
        cnt_R++;
        if(cnt_R<=5)
        {
            s->decrease();
            bullet *b1 = new bullet;
            b1->setPixmap(QPixmap(":/res/red_bullet.png").scaled(25, 25));
            b1->setPos(player->getX()+0,player->getY());
            b1->connect(timer, SIGNAL(timeout()), b1, SLOT(fly_left_up()));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b1));

            bullet *b2 = new bullet;
            b2->setPixmap(QPixmap(":/res/red_bullet.png").scaled(25, 25));
            b2->setPos(player->getX()+12.5,player->getY());
            b2->connect(timer, SIGNAL(timeout()), b2, SLOT(fly_up()));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b2));

            bullet *b3 = new bullet;
            b3->setPixmap(QPixmap(":/res/red_bullet.png").scaled(25, 25));
            b3->setPos(player->getX()+25,player->getY());
            b3->connect(timer, SIGNAL(timeout()), b3, SLOT(fly_right_up()));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b3));
        }
    }
    }
}
/*void MainWindow::enemy_HP()
{
    if( enemy->getX() == x && enemy->getY() == y )
    {
        ui->progressBar->setValue(ui->progressBar->value()-1);
    }
}*/
/*void MainWindow::mousePressEvent(QMouseEvent *e)
{
    bullet *b = new bullet;
    b->setPixmap(QPixmap(":/res/red_bullet.png").scaled(50, 50));
    b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2, player->y() - b->pixmap().height());
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly_up()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
}*/

void MainWindow::enemy_shot()
{
    bullet *b = new bullet;
    b->setPixmap(QPixmap(":/res/black_bullet.png").scaled(50, 50));
    b->setPos(enemy->getX()+50,enemy->getY()+100);
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly_down()));
    MainWindow::scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
}




































