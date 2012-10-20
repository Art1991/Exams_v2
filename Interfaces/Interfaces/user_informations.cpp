#include "user_informations.hpp"
#include <QtXml/QtXml>
#include <QtXmlPatterns/QtXmlPatterns>
#include <QFile>
#include <QDebug>

User_informations :: User_informations() {
}

void User_informations :: save_Information() {
    QDomDocument model("");
    QDomNode xmlNode = model.createProcessingInstruction("xml", "version=\"1.0\"");
    model.insertBefore(xmlNode, model.firstChild());

    /* Дефолтные данные
    */
    fio = "Chernyshev Arthur Rustemovich";
    number_of_test = "12";
    time_date = "12.02.2012";
    total_number_of_task = "36";
    number_of_correct_task = "5";
    procent_of_correct_task = "5,6%";
    test_answers.append("tempNULL");
    test_answers.append("not false");
    correctness_answers.append("Corrected on 56%");
    correctness_answers.append("InCorrected");

    /*--------------------------------*/


    QDomElement Root = model.createElement("Root");
    QDomElement Fio = model.createElement("Fio");
    QDomElement Number_of_test = model.createElement("Number_of_test");
    QDomElement Time_date = model.createElement("Time_date");
    QDomElement Total_number_of_task = model.createElement("Total_number_of_task");
    QDomElement Number_of_correct_task = model.createElement("Number_of_correct_task");
    QDomElement Procent_of_correct_task = model.createElement("Procent_of_correct_task");
    QDomElement Test_answers = model.createElement("test_answers");
    QDomElement Correctness_answers = model.createElement("correctness_answers");


    QDomText TextOfFio = model.createTextNode(fio);
    QDomText TextOfNumber_of_test = model.createTextNode(number_of_test);
    QDomText TextOfTime_date = model.createTextNode(time_date);
    QDomText TextOfTotal_number_of_task = model.createTextNode(total_number_of_task);
    QDomText TextOfNumber_of_correct_task = model.createTextNode(number_of_correct_task);
    QDomText TextOfProcent_of_correct_task = model.createTextNode(procent_of_correct_task);

    model.appendChild(Root);
    Root.appendChild(Fio);
    Root.appendChild(Number_of_test);
    Root.appendChild(Time_date);
    Root.appendChild(Total_number_of_task);
    Root.appendChild(Number_of_correct_task);
    Root.appendChild(Procent_of_correct_task);
    Root.appendChild(Test_answers);
    Root.appendChild(Correctness_answers);

    foreach (QString str, test_answers) {
        QDomElement el = model.createElement("answer");
        el.appendChild(model.createTextNode(str));
        Test_answers.appendChild(el);
    }

    foreach (QString str, correctness_answers) {
        QDomElement el = model.createElement("correcting");
        el.appendChild(model.createTextNode(str));
        Correctness_answers.appendChild(el);
    }

    Fio.appendChild(TextOfFio);
    Number_of_test.appendChild(TextOfNumber_of_test);
    Time_date.appendChild(TextOfTime_date);
    Total_number_of_task.appendChild(TextOfTotal_number_of_task);
    Number_of_correct_task.appendChild(TextOfNumber_of_correct_task);
    Procent_of_correct_task.appendChild(TextOfProcent_of_correct_task);

    QFile xmlUserFile("./xmlUserFile.xml");
    if (!xmlUserFile.exists()) {
        return;
    }

    xmlUserFile.open(QIODevice::WriteOnly);
    QTextStream information(&xmlUserFile);

    model.save(information, 5);
    xmlUserFile.close();
}


void User_informations :: read_Information() {
    QFile xmlUserFile("./xmlUserFile.xml");
    xmlUserFile.open(QIODevice::ReadOnly);
    if (!xmlUserFile.exists()) {
        qDebug("is not xml file");
        return;
    }
    QDomDocument model;

    if(!model.setContent(&xmlUserFile)) {
        qDebug("is not xml file2");
        return;
    }

    fio = model.elementsByTagName("Fio").at(0).toElement().text();
    number_of_test = model.elementsByTagName("Number_of_test").at(0).toElement().text();
    time_date = model.elementsByTagName("Time_date").at(0).toElement().text();
    total_number_of_task = model.elementsByTagName("Total_number_of_task").at(0).toElement().text();
    number_of_correct_task = model.elementsByTagName("Number_of_correct_task").at(0).toElement().text();
    procent_of_correct_task = model.elementsByTagName("Procent_of_correct_task").at(0).toElement().text();


    QDomNodeList strList = model.elementsByTagName("correctness_answers");
    for(int i = 0; i < strList.length(); i++) {
        correctness_answers.append(strList.at(i).toElement().elementsByTagName("test_answers").at(0).toElement().text());
        qDebug() << correctness_answers;
    }


    strList = model.elementsByTagName("test_answers");
    for(int i = 0; i < strList.length(); i++) {
        test_answers.append(strList.at(i).toElement().elementsByTagName("test_answers").at(0).toElement().text());
        qDebug() << test_answers;
    }
    xmlUserFile.close();
}
