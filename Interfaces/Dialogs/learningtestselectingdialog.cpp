#include "learningtestselectingdialog.hpp"
#include "ui_learningtestselectingdialog.h"

LearningTestSelectingDialog::LearningTestSelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LearningTestSelectingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

LearningTestSelectingDialog::~LearningTestSelectingDialog()
{
    delete ui;
}

void LearningTestSelectingDialog::setTestsData(const QStringList &tests)
{
}

QString LearningTestSelectingDialog::getSelectedTest()
{
}

void LearningTestSelectingDialog::on_canselPushButton_clicked()
{
    this->reject();
}

void LearningTestSelectingDialog::on_okPushButton_clicked()
{
    this->accept();
}
