#ifndef STARTWIDGETLOGICS_HPP
#define STARTWIDGETLOGICS_HPP

// это будет класс логики стартового окна
// его нужно будет связать с навигационным классом
// переключение виджетов с разными функциями нашей программы

#include <QWidget>

class StartWidgetLogics
{
public:
    StartWidgetLogics();
    QWidget* getTestPreparingWidgetPtr();

    //функции включения нужных виджетов
    //их несколько разных для каждого виджета своя
    void showRequestedWidget();
private:


};

#endif // STARTWIDGETLOGICS_HPP
