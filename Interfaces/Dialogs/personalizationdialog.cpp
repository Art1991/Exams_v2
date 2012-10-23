#include "personalizationdialog.hpp"
#include "ui_personalizationdialog.h"

PersonalizationDialog::PersonalizationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalizationDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

PersonalizationDialog::~PersonalizationDialog()
{
    delete ui;
}

void PersonalizationDialog::on_okPushButton_clicked()
{
    this->accept();
}

void PersonalizationDialog::on_canselPushButton_clicked()
{
    this->reject();
}
