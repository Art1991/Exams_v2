#include "testingtaskwidget.hpp"

TestingTaskWidget::TestingTaskWidget() {

}

void TestingTaskWidget::showPicture(QString address) {
    labelExercise->setPixmap(QPixmap::fromImage(QImage(address)));//����������� �������� � �������� taskText ���� ��� �����
}

void TestingTaskWidget::showTaskText(QStringList answers, QString taskText) {
    labelExercise->setText(taskText + '\n');
      for(int i = 0; i < answers.length(); i++) {
       labelAnswers->append(answers.at(i) + '\n');
     }
    //  ����� ����������� �������� ������� � ������� � �������� � ������� � ����� ����������
    //  ������������ �������� � ������� �������������� ���� ����� ������ ������������ �� ������ ���� ������� �� � �����!!!
    //  � ���� ������
    //  1 �������� ���������� ����� �����������������
    //  ��� 2 - ������� ������� ������ � �������
}

void TestingTaskWidget::toFinishCount() {
    tlptr->timeFinish();
}

void TestingTaskWidget::toReckon() {
    tlptr->timeStart();
}

void TestingTaskWidget::dumpingOfAnswers() {

}

void TestingTaskWidget::showResult(QString results) {
    QMessageBox msgBox;
    msgBox.setText(results);
    msgBox.exec();
}
