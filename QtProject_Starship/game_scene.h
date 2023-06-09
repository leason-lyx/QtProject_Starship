#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include <QTime>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>

class game_scene: public QGraphicsView
{
public:
    game_scene(QGraphicsScene* scene);
    QTime stopTime;
public slots:
    void Stop();
protected:
    void showEvent(QShowEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
};

#endif // GAME_SCENE_H
