#ifndef STARTWIDGETFACADE_HPP
#define STARTWIDGETFACADE_HPP

#include <QObject>


// это класс - фасад, связывающий UI стартового окна с логикой работы стартового окна
// фактически классы StartWidgetUi и StartWidgetLogic
//

class StartWidgetFacade : public QObject
{
    Q_OBJECT
public:
    explicit StartWidgetFacade(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // STARTWIDGETFACADE_HPP
