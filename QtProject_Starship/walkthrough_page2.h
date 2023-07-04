#ifndef WALKTHROUGH_PAGE2_H
#define WALKTHROUGH_PAGE2_H

#include <QWidget>

namespace Ui {
class Walkthrough_page2;
}

class Walkthrough_page2 : public QWidget
{
    Q_OBJECT

public:
    explicit Walkthrough_page2(QWidget *parent = nullptr);
    ~Walkthrough_page2();

private:
    Ui::Walkthrough_page2 *ui;
};

#endif // WALKTHROUGH_PAGE2_H
