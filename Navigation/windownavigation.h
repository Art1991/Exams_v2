#ifndef WINDOWNAVIGATION_H
#define WINDOWNAVIGATION_H

#include <QObject>
#include <QStackedWidget>
#include <QList>
#include <QPair>

class WindowNavigation : public QObject
{
    Q_OBJECT
public:
    explicit WindowNavigation(QObject *parent = 0);
    
signals:
    
public slots:
    void showExtendedTheory();
    void showStartWidget();
    void showTestPreparingWidget();
    void showTestingWidget();
    void showPluginWidget(const QString &pluginId);

private:
    QList<QPair <QWidget *, QString > > widgetsTable;
};

#endif // WINDOWNAVIGATION_H
