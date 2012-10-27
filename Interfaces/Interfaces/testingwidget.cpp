#include "testingwidget.hpp"
#include "ui_testingwidget.h"

#define A_FIELDS_COUNT 20
#define B_FIELDS_COUNT 20
#define C_FIELDS_COUNT 0

TestingWidget::TestingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestingWidget)
{
    ui->setupUi(this);

    navigationButtonCount = 20;
    aCount = A_FIELDS_COUNT;
    bCount = B_FIELDS_COUNT;
    cCount = C_FIELDS_COUNT;

    navigationsInit();
    answersAInit();
    answersBInit();

}

TestingWidget::~TestingWidget()
{
    delete ui;
}

void TestingWidget::setTaskCount(const int aCount, const int bCount, const int cCount)
{
    this->aCount = aCount;
    this->bCount = bCount;
    this->cCount = cCount;

    showNavigationButtons(aCount);

    showAAnswersFields(aCount);
    showBAnswersFields(bCount);
    showCAnswersFields(cCount);

    ui->comboBoxNavigation->setCurrentIndex(0);
    ui->answerWidget->setCurrentIndex(0);
}

void TestingWidget::hideHelpButtons()
{
    for (int i = 1; i <= navigationButtonCount; i++)
    {
        QToolButton *button = ui->navigationWidget->findChild<QToolButton *>("navigationHelpButton_" + QString::number(i, 10));

        if (button != NULL)
        {
            button->hide();
        }
    }
}

void TestingWidget::showHelpButtons()
{
    for (int i = 1; i <= navigationButtonCount; i++)
    {
        QToolButton *button = ui->navigationWidget->findChild<QToolButton *>("navigationHelpButton_" + QString::number(i, 10));

        if (button != NULL)
        {
            button->show();
        }
    }
}

void TestingWidget::navigationsInit() {
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->setSpacing(0);
    ui->scrollAreaWidgetContents->setLayout(verticalLayout);

    for (int i = 1; i <= navigationButtonCount; i++)
    {
        // navigationWidget_1..n
        QWidget *navigationWidget = new QWidget;
        navigationWidget->setObjectName("navigationWidget_" + QString::number(i, 10));
        navigationWidget->setFixedHeight(45);
        navigationWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->setContentsMargins(0, 0, 5, 0);
        horizontalLayout->setSpacing(0);
        navigationWidget->setLayout(horizontalLayout);

        // navigationButton_1..n
        QPushButton *navigationButton = new QPushButton;
        navigationButton->setObjectName("navigationButton_" + QString::number(i, 10));
        navigationButton->setFlat(true);
        navigationButton->setText("NB" + QString::number(i, 10));
        navigationButton->setFixedHeight(45);
        navigationButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        navigationWidget->layout()->addWidget(navigationButton);

        // scrollAreaWidgetContents < vertical layout < qwidget < horizontal layout < button & helpbutton

        QToolButton *taskHelpButton = new QToolButton();
        taskHelpButton->setObjectName("navigationHelpButton_" + QString::number(i, 10));
        taskHelpButton->setFixedSize(36, 36);
        taskHelpButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        navigationWidget->layout()->addWidget(taskHelpButton);

        ui->scrollAreaWidgetContents->layout()->addWidget(navigationWidget);

        connect(navigationButton, SIGNAL(clicked()), this, SLOT(on_taskPushButton_clicked()));
        connect(taskHelpButton, SIGNAL(clicked()), this, SLOT(on_taskHelpPushButton_clicked()));
    }
}

void TestingWidget::answersAInit()
{
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout->setSpacing(3);
    ui->answerPage_A->setLayout(horizontalLayout);

    for (int i = 1; i <= A_FIELDS_COUNT; i++)
    {
        QGroupBox *groupBox = new QGroupBox();
        groupBox->setTitle("A" + QString::number(i, 10));
        groupBox->setObjectName("aGroupBox_" + QString::number(i, 10));
        groupBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        QVBoxLayout *verticalLayout = new QVBoxLayout;
        groupBox->setLayout(verticalLayout);

        for (int j = 1; j < 5; j++)
        {
            QCheckBox *checkBox = new QCheckBox;
            checkBox->setObjectName("A_" + QString::number(i, 10) + "_" + QString::number(j, 10));
            checkBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

            groupBox->layout()->addWidget(checkBox);
        }

        ui->answerPage_A->layout()->addWidget(groupBox);
    }
}

void TestingWidget::answersBInit()
{
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setSpacing(5);

    for (int i = 1; i <= B_FIELDS_COUNT; i++)
    {
        QWidget *answerWidget = new QWidget;
        answerWidget->setObjectName("bAnswerWidget_" + QString::number(i, 10));
        answerWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setSpacing(5);

        QLabel *answerLabel = new QLabel;
        answerLabel->setText("B" + QString::number(i, 10));
        answerLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        answerLabel->setFixedWidth(30);

        QLineEdit *answerLineEdit = new QLineEdit;
        answerWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        answerWidget->setObjectName("B_" + QString::number(i, 10));

        horizontalLayout->addWidget(answerLabel);
        horizontalLayout->addWidget(answerLineEdit);

        answerWidget->setLayout(horizontalLayout);
        gridLayout->addWidget(answerWidget, (i - 1) % 5, (i - 1) / 5);
    }

    ui->answerPage_B->setLayout(gridLayout);
}

void TestingWidget::answersCInit()
{
}



void TestingWidget::showNavigationButtons(const int count, const QString &taskType)
{
    for (int i = 1; i <= count; i++)
    {
        QWidget *navigationWidget = ui->navigationWidget->findChild<QWidget *>("navigationWidget_" + QString::number(i, 10));
        if (navigationWidget != NULL)
        {
            QPushButton *navigationButton = navigationWidget->findChild<QPushButton *>("navigationButton_" + QString::number(i, 10));
            if (navigationButton != NULL)
            {
                navigationButton->setText(taskType + " " + QString::number(i));
            }
            navigationWidget->show();
        }
    }
    for (int i = count + 1; i <= navigationButtonCount; i++)
    {
        QWidget *navigationWidget = ui->navigationWidget->findChild<QWidget *>("navigationWidget_" + QString::number(i, 10));
        if (navigationWidget != NULL)
        {
            navigationWidget->hide();
        }
    }
}

void TestingWidget::showAAnswersFields(const int count)
{
    ui->answerWidget->setCurrentIndex(0);

    for (int i = 1; i <= count; i++)
    {
        QGroupBox *navigationWidget = ui->answerPage_A->findChild<QGroupBox *>("aGroupBox_" + QString::number(i, 10));
        if (navigationWidget != NULL)
        {
            navigationWidget->show();
        }
    }
    for (int i = count + 1; i <= A_FIELDS_COUNT; i++)
    {
        QWidget *navigationWidget = ui->answerPage_A->findChild<QWidget *>("aGroupBox_" + QString::number(i, 10));
        if (navigationWidget != NULL)
        {
            navigationWidget->hide();
        }
    }
}

void TestingWidget::showBAnswersFields(const int count)
{
    ui->answerWidget->setCurrentIndex(1);

    for (int i = 1; i <= count; i++)
    {
        QWidget *navigationWidget = ((QGridLayout *)ui->answerPage_B->layout())->itemAtPosition((i - 1) % 5, (i - 1) / 5)->widget();
        if (navigationWidget != NULL)
        {
            navigationWidget->show();
        }
    }
    for (int i = count + 1; i <= B_FIELDS_COUNT; i++)
    {
        QWidget *navigationWidget = ((QGridLayout *)ui->answerPage_B->layout())->itemAtPosition((i - 1) % 5, (i - 1) / 5)->widget();
        if (navigationWidget != NULL)
        {
            navigationWidget->hide();
        }
    }
}

void TestingWidget::showCAnswersFields(const int count) {
    ui->answerWidget->setCurrentIndex(2);
}

void TestingWidget::on_startTestButton_clicked() {
    emit startTestRequest();
}

void TestingWidget::on_stopTestButton_clicked() {
    emit finishTestRequest();
}

void TestingWidget::on_exitPushButton_clicked() {
    // резервное сохранение результата
    emit menuJumpRequest();
}

// слот, который был вызван сигналом navigationButton_n(clicked())
// sender()->objectName() - имя объекта отправителя, в данном случае navigationButton_n
void TestingWidget::on_taskPushButton_clicked() {
    QString senderName = sender()->objectName();

    if (!senderName.contains("navigationButton_")) {
        return;
    }

    senderName.remove("navigationButton_");

    bool ok = true;
    int button = senderName.toInt(&ok);
    if (!ok) {
        return;
    }

    // 1. Что за кнопка нажата была - получили номаер нажатой кнопки в переменной button
    // 2. испустить сигнал с параметром <номер задания>

    QString taskId;
    switch (ui->comboBoxNavigation->currentIndex()) {
    case 0:
        taskId = "A" + QString::number(button);
        break;
    case 1:
        taskId = "B" + QString::number(button);
        break;
    case 2:
        taskId = "C" + QString::number(button);
        break;
    }
    // букву задания и потом номер задания: <буква><число>

    // запуск сигнала с параметром - номером задания
    emit jumpToTaskRequest(taskId);
}

void TestingWidget::on_taskHelpPushButton_clicked()
{
    QString senderName = sender()->objectName();

    if (!senderName.contains("navigationHelpButton_"))
    {
        return;
    }

    senderName.remove("navigationHelpButton_");

    bool ok = true;
    int button = senderName.toInt(&ok);

    if (!ok)
    {
        return;
    }

    QString taskId;
    switch (ui->comboBoxNavigation->currentIndex())
    {
    case 0:
        taskId = "A" + QString::number(button);
        break;
    case 1:
        taskId = "B" + QString::number(button);
        break;
    case 2:
        taskId = "C" + QString::number(button);
        break;
    }

    emit jumpToTaskHelp(taskId);
}

void TestingWidget::on_taskGroupSwitched()
{
}

void TestingWidget::on_comboBox_currentIndexChanged(int index)
{


}


void TestingWidget::on_comboBoxNavigation_currentIndexChanged(int index) {
    switch (index)
    {
    case 0:
        showNavigationButtons(aCount, "A");
        showAAnswersFields(aCount);
        break;
    case 1:
        showNavigationButtons(bCount, "B");
        showBAnswersFields(bCount);
        break;
    case 2:
        showNavigationButtons(cCount, "C");
        showCAnswersFields(cCount);
        break;
    }
}

