#ifndef PERSONALIZATIONDIALOG_H
#define PERSONALIZATIONDIALOG_H

#include <QDialog>
#include <QString>
#include <QList>
#include <QStringList>

namespace Ui {
    class PersonalizationDialog;
}

class PersonalizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalizationDialog(QWidget *parent = 0);
    ~PersonalizationDialog();

    QStringList getFields();            // Возвращает - имя, фамилию, группу/класс
    QString getName();
    QString getSurname();
    QString getGroup();
    QString getForm();

private slots:
    void on_okPushButton_clicked();

    void on_canselPushButton_clicked();

private:
    Ui::PersonalizationDialog *ui;
};

#endif // PERSONALIZATIONDIALOG_H
