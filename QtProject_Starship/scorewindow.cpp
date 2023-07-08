#include "scorewindow.h"
#include "qlabel.h"

ScoreWindow::ScoreWindow(QWidget *parent) :
    QWidget(parent),
    m_currentScore(0)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    m_textLabel = new QLabel("你的得分是：", this);
    m_textLabel->setAlignment(Qt::AlignCenter);
    QFont textFont = m_textLabel->font();
    textFont.setPointSize(24);  // 设置字体大小为20点
    m_textLabel->setFont(textFont);

    m_scoreLabel = new QLabel(this);
    QFont font = m_scoreLabel->font();
    font.setPointSize(30);  // 设置字体大小为24点
    m_scoreLabel->setFont(font);
    m_scoreLabel->setAlignment(Qt::AlignCenter);
    m_scoreLabel->setNum(m_currentScore);

    layout->setSpacing(10);  // 设置间距为10像素
    layout->addWidget(m_textLabel);  // 把新的QLabel添加到布局中
    layout->addWidget(m_scoreLabel);

    m_animation = new QPropertyAnimation(this, "currentScore");
    m_animation->setDuration(2000); // 动画持续2秒
    m_animation->setStartValue(m_currentScore);
    m_animation->setEndValue(0);

    connect(m_animation, &QPropertyAnimation::valueChanged, [this](const QVariant &value){
        m_scoreLabel->setNum(value.toInt());
    });
}

void ScoreWindow::gameOver(int finalScore) {
    m_animation->setEndValue(finalScore);
    m_animation->start();
    this->show();
}

int ScoreWindow::getCurrentScore() const {
    return m_currentScore;
}

void ScoreWindow::setCurrentScore(int score) {
    if (m_currentScore != score) {
        m_currentScore = score;
        emit currentScoreChanged(m_currentScore);
    }
}

void ScoreWindow::animateScore(int finalScore) {
    m_animation->setStartValue(m_currentScore);
    m_animation->setEndValue(finalScore);
    m_animation->start();
}
