#include "testingtaskwidget.hpp"

TestingTaskWidget::TestingTaskWidget() {

}

void TestingTaskWidget::showPicture(QString address) {
//    labelExercise->setPixmap(QPixmap::fromImage(QImage(address)));//����������� �������� � �������� taskText ���� ��� �����
}

void TestingTaskWidget::showAnswers(QStringList)
{
}

void TestingTaskWidget::showTaskText(QStringList answers, QString taskText) {
//    labelExercise->setText(taskText + '\n');
//      for(int i = 0; i < answers.length(); i++) {
//       labelAnswers->append(answers.at(i) + '\n');
//     }
    //  ����� ����������� �������� ������� � ������� � �������� � ������� � ����� ����������
    //  ������������ �������� � ������� �������������� ���� ����� ������ ������������ �� ������ ���� ������� �� � �����!!!
    //  � ���� ������
    //  1 �������� ���������� ����� �����������������
      //  ��� 2 - ������� ������� ������ � �������
}

void TestingTaskWidget::showTaskText(QString)
{
}

void TestingTaskWidget::toFinishCount() {
    //tlptr->timeFinish();
}

void TestingTaskWidget::toReckon() {
    //tlptr->timeStart();
}

void TestingTaskWidget::dumpingOfAnswers() {

}

void TestingTaskWidget::showResult(QStringList results) {
    QMessageBox msgBox;
    msgBox.setText(results.at(1));
    msgBox.exec();
}
