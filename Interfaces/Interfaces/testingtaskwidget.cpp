#include "testingtaskwidget.hpp"

TestingTaskWidget::TestingTaskWidget() {

}

void TestingTaskWidget::showPicture(QString address) {
//    labelExercise->setPixmap(QPixmap::fromImage(QImage(address)));//отображение картинки с заданием taskText путь для файла
}

void TestingTaskWidget::showAnswers(QStringList)
{
}

void TestingTaskWidget::showTaskText(QStringList answers, QString taskText) {
//    labelExercise->setText(taskText + '\n');
//      for(int i = 0; i < answers.length(); i++) {
//       labelAnswers->append(answers.at(i) + '\n');
//     }
    //  Сразу осмысленные названия классов и методов и процедур и функций и всего остального
    //  Использовать принятое в проекте форматирование кода иначе будешь переписывать не только свое говнище но и чужое!!!
    //  С чего начать
    //  1 написать послностью класс тестингтасквиджет
      //  или 2 - сначала связать фасады с логикой
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
