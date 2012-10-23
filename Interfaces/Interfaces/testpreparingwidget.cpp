#include "testpreparingwidget.hpp"
#include "ui_testpreparingwidget.h"

#define A_FIELDS_COUNT 20
#define B_FIELDS_COUNT 20
#define C_FIELDS_COUNT 0

TestPreparingWidget::TestPreparingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestPreparingWidget)
{
    ui->setupUi(this);


    navigationButtonCount = 20;
    aCount = A_FIELDS_COUNT;
    bCount = B_FIELDS_COUNT;
    cCount = C_FIELDS_COUNT;

    navigationsInit();

    showNavigationButtons(20, "A");
}

TestPreparingWidget::~TestPreparingWidget()
{
    delete ui;
}

void TestPreparingWidget::setTaskCount(const int aCount, const int bCount, const int cCount)
{
    this->aCount = aCount;
    this->bCount = bCount;
    this->cCount = cCount;

    showNavigationButtons(aCount);

    ui->comboBoxNavigation->setCurrentIndex(0);
}

void TestPreparingWidget::navigationsInit()
{
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->setSpacing(0);
    ui->scrollAreaWidgetContents->setLayout(verticalLayout);

    for (int i = 1; i <= navigationButtonCount; i++)
    {
        QWidget *navigationWidget = new QWidget;
        navigationWidget->setObjectName("navigationWidget_" + QString::number(i, 10));
        navigationWidget->setFixedHeight(45);
        navigationWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->setContentsMargins(0, 0, 5, 0);
        horizontalLayout->setSpacing(0);
        navigationWidget->setLayout(horizontalLayout);

        QPushButton *navigationButton = new QPushButton;
        navigationButton->setObjectName("navigationButton_" + QString::number(i, 10));
        navigationButton->setFlat(true);
        navigationButton->setText("NB" + QString::number(i, 10));
        navigationButton->setFixedHeight(45);
        navigationButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        navigationWidget->layout()->addWidget(navigationButton);

        ui->scrollAreaWidgetContents->layout()->addWidget(navigationWidget);

        connect(navigationButton, SIGNAL(clicked()), this, SLOT(on_taskPushButton_clicked()));
    }
}

void TestPreparingWidget::showNavigationButtons(const int count, const QString &taskType)
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

void TestPreparingWidget::on_taskPushButton_clicked()
{
    QString senderName = sender()->objectName();

    if (!senderName.contains("navigationButton_"))
    {
        return;
    }

    senderName.remove("navigationButton_");

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

    emit jumpToTaskRequest(taskId);
}


void TestPreparingWidget::on_startTestPushButton_clicked()
{
    emit testExecutionRequst();
}

void TestPreparingWidget::on_extendedTheoryPushButton_clicked()
{
    emit extendedTheoryRequest();
}

void TestPreparingWidget::on_exitPushButton_clicked()
{
    emit menuJumpRequest();
}

void TestPreparingWidget::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        showNavigationButtons(aCount, "A");
        break;
    case 1:
        showNavigationButtons(bCount, "B");
        break;
    case 2:
        showNavigationButtons(cCount, "C");
        break;
    }
}
