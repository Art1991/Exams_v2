#ifndef STARTWIDGETLOGICS_HPP
#define STARTWIDGETLOGICS_HPP

// это будет класс логики стартового окна
// его нужно будет связать с навигационным классом
// переключение виджетов с разными функциями нашей программы

#include <QWidget>

class StartWidgetLogics : public QObject
{
    Q_OBJECT

public:
    explicit StartWidgetLogics(QObject* parent = 0);

    // QWidget : public QObject
    // ...
    // StartWidgetLogics(QWidget*) -> StartWidgetLogics(QObject*)
    // если есть explicit
    // то такого автокаста классов не происходит
    // мы получим ошибку о том, что нет конструктора, принимающего аргументов QWidget*


    void connectSignalsSlots(QWidget*);
    //функции включения нужных виджетов
    //их несколько разных для каждого виджета своя
    void showTestPreparingWidget(); // функция, вызванная из startwidgetfacade.cpp
    void showRequestedWidget(); 
    void showSettings();
    void showTheoryParagraph();
    void showTestingWidget();
    void closeStartWidget();
private:

signals:
    void askTaskPreparingWidget(); // вот мы выполнили первый пункт - создали сигнал
    // теперь сигнал надо выпустить в файле startwidgetlogic.cpp

};

#endif // STARTWIDGETLOGICS_HPP
