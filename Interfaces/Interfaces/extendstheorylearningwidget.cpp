#include "extendstheorylearningwidget.hpp"
#include "ui_extendstheorylearningwidget.h"

ExtendsTheoryLearningWidget::ExtendsTheoryLearningWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendsTheoryLearningWidget)
{
    ui->setupUi(this);
}

ExtendsTheoryLearningWidget::~ExtendsTheoryLearningWidget()
{
    delete ui;
}

void ExtendsTheoryLearningWidget::on_exitPushButton_clicked()
{
    emit menuJumpRequest();
}
