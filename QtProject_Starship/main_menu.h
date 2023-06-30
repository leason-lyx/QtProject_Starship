#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QDialog>
#include "starship.h"
#include "starship.cpp"
#include "game_scene.h"
#include "myScene.h"

namespace Ui {
class main_menu;
}

class main_menu : public QDialog
{
    Q_OBJECT

public:
    explicit main_menu(QWidget *parent = nullptr);
    ~main_menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::main_menu *ui;

private:
    myScene *scene;
//    Starship *ship;
    game_scene *view;
    QTimer *timer;
};

#endif // MAIN_MENU_H
