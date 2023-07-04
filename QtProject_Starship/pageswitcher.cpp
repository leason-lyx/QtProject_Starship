#include "PageSwitcher.h"
#include <QVBoxLayout>

PageSwitcher::PageSwitcher(QWidget *parent)
    : QWidget(parent),
      stackWidget(new QStackedWidget(this)),
      prevButton(new QPushButton("上一页", this)),
      nextButton(new QPushButton("下一页", this)) {

    connect(prevButton, &QPushButton::clicked, this, &PageSwitcher::switchToPrevPage);
    connect(nextButton, &QPushButton::clicked, this, &PageSwitcher::switchToNextPage);

    prevButton->setFixedSize(150, 100);  // 设置按钮大小为100x50
    nextButton->setFixedSize(150, 100);  // 设置按钮大小为100x50

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();  // 用于将按钮推到右侧
    buttonLayout->addWidget(prevButton);
    buttonLayout->addWidget(nextButton);

    mainLayout->addWidget(stackWidget);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    updateButtonStatus();  // 初始化按钮状态
    resize(1000,800);
}

void PageSwitcher::addPage(QWidget *page) {
    stackWidget->addWidget(page);
    updateButtonStatus();  // 每次添加页面后，更新按钮状态
}


void PageSwitcher::switchToPrevPage() {
    int currentIndex = stackWidget->currentIndex();
    if (currentIndex > 0) {
        stackWidget->setCurrentIndex(currentIndex - 1);
    }
    updateButtonStatus();  // 翻页后，更新按钮状态
}

void PageSwitcher::switchToNextPage() {
    int currentIndex = stackWidget->currentIndex();
    if (currentIndex < stackWidget->count() - 1) {
        stackWidget->setCurrentIndex(currentIndex + 1);
    }
    updateButtonStatus();  // 翻页后，更新按钮状态
}

void PageSwitcher::updateButtonStatus() {
    int currentIndex = stackWidget->currentIndex();
    prevButton->setEnabled(currentIndex > 0);
    nextButton->setEnabled(currentIndex < stackWidget->count() - 1);
}
