#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QFont>
#include <QVBoxLayout>

class ScoreWindow : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int currentScore READ getCurrentScore WRITE setCurrentScore NOTIFY currentScoreChanged)

public:
    explicit ScoreWindow(QWidget *parent = nullptr);

    int getCurrentScore() const;
    void setCurrentScore(int score);
    void animateScore(int finalScore);

signals:
    void currentScoreChanged(int currentScore);

public slots:
    void gameOver(int finalScore);

private:
    QLabel *m_scoreLabel;
    QLabel *m_textLabel;  // 新添加的QLabel
    QPropertyAnimation *m_animation;
    int m_currentScore;
};

#endif // SCOREWINDOW_H
