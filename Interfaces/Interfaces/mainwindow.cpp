#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    swptr = new StartWidgetUI();
    tpwptr = new TestPreparingWidget();
    etlwptr = new ExtendsTheoryLearningWidget();
    twptr = new TestingWidget();
    twptr->setTaskCount(15, 10, 0);
    ui->stackedWidget->addWidget(swptr);
    ui->stackedWidget->addWidget(tpwptr);
    ui->stackedWidget->addWidget(etlwptr);
    ui->stackedWidget->addWidget(twptr);
//    ui->stackedWidget->addWidget(new StartWidgetUI()); // id == 0
//    ui->stackedWidget->addWidget(new TestPreparingWidget()); // id == 1
//    ui->stackedWidget->addWidget(new ExtendsTheoryLearningWidget()); // id == 2
//    TestingWidget *t = new TestingWidget();
//    t->setTaskCount(15, 10, 0);
//    ui->stackedWidget->addWidget(t); // id == 3
    ui->stackedWidget->setCurrentIndex(0);

    setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int key = event->button();
    if (key == Qt::LeftButton)
    {
        int index = ui->stackedWidget->currentIndex();
        if (index - 1 >= 0)
        {
            ui->stackedWidget->setCurrentIndex(index - 1);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
        }
    }

    if (key == Qt::RightButton)
    {
        int index = ui->stackedWidget->currentIndex();
        if (index + 1 < ui->stackedWidget->count())
        {
            ui->stackedWidget->setCurrentIndex(index + 1);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    event->ignore();
    // event->accept();
}

void MainWindow::switchToTestPreparingWidget() {
    // В этом слоте от нас требуется сменить показываемый виджет на TestPreparingWidget
    // тут есть непбольшой фокус - у TestPreparingWidget есть какой-то свой цифровой id
    // мы его пока что не знаем
    // вот мы его узнали, каким именно образом - непонятно, но узнали
    ui->stackedWidget->setCurrentIndex(1);
    // казалось бы, что работа закончена, однако не стоит забывать, что
    // сигналы и слоты необходимо связывать с помощью QObject::connect()
    // connect(объект-источник, название сигнала, объект-приемник, название слота, тип подключения)
    // где ставить коннект? ставить там, где можно получить все аргументы для него, в частности указатели на
    // на объект-источник и объект-приемник
    // идем в файл starrwidgetfacade.cpp
}

StartWidgetUI* MainWindow::getStartWidgetUIPtr() {
    return swptr;
}

TestPreparingWidget* MainWindow::getTestPreparingWidgetPtr() {
    return tpwptr;
}

ExtendsTheoryLearningWidget* MainWindow::getExtendsTheoryLearningWidgetPtr() {
    return etlwptr;
}

TestingWidget* MainWindow::getTestingWidgetPtr() {
    return twptr;
}
