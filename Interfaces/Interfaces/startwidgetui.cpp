#include "startwidgetui.hpp"
#include "ui_startwidgetui.h"
#include <QMessageBox>

StartWidgetUI::StartWidgetUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWidgetUI)
{
    ui->setupUi(this);
}

StartWidgetUI::~StartWidgetUI()
{
    delete ui;
}

void StartWidgetUI::on_settingsPushButton_clicked()
{
    emit settingsJumpRequest();
}

void StartWidgetUI::on_startTestPushButton_clicked()
{
    emit testingJumpRequest();
}

void StartWidgetUI::on_extendedTheoryPushButton_clicked()
{
    emit extendedTheoryJumpRequest();
}

void StartWidgetUI::on_testPreparingPushPutton_clicked()
{
    emit reviewedTestLEarningRequest(); //при нажатии на кнопку выпускается сигнал reviewedTestLEarningRequest()
    // он объявлен в файле startwidgetui.hpp
}

void StartWidgetUI::on_exitPushButton_clicked()
{
    emit exitJumpRequest();
}
