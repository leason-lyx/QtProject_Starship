#ifndef WALKTHROUGH_PAGE1_H
#define WALKTHROUGH_PAGE1_H

#include <QWidget>

namespace Ui {
class Walkthrough_page1;
}

class Walkthrough_page1 : public QWidget
{
    Q_OBJECT

public:
    explicit Walkthrough_page1(QWidget *parent = nullptr);
    ~Walkthrough_page1();

private:
    Ui::Walkthrough_page1 *ui;
};

#endif // WALKTHROUGH_PAGE1_H
