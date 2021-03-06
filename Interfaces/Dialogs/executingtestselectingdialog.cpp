#include "executingtestselectingdialog.hpp"
#include "ui_executingtestselectingdialog.h"

ExecutingTestSelectingDialog::ExecutingTestSelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExecutingTestSelectingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

ExecutingTestSelectingDialog::~ExecutingTestSelectingDialog()
{
    delete ui;
}

void ExecutingTestSelectingDialog::setTestsData(const QStringList &tests)
{
}

QString ExecutingTestSelectingDialog::getSelectedTest()
{
}

void ExecutingTestSelectingDialog::on_canselPushButton_clicked()
{
    this->reject();
}

void ExecutingTestSelectingDialog::on_okPushButton_clicked()
{
    this->accept();
}
