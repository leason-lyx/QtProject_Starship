#ifndef PAGESWITCHER_H
#define PAGESWITCHER_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>

class PageSwitcher : public QWidget {
    Q_OBJECT

public:
    PageSwitcher(QWidget *parent = nullptr);
    void addPage(QWidget *page);

private slots:
    void switchToPrevPage();
    void switchToNextPage();

private:
    void updateButtonStatus();

    QStackedWidget *stackWidget;
    QPushButton *prevButton;
    QPushButton *nextButton;
};

#endif // PAGESWITCHER_H
