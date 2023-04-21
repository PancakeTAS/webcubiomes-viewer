
#ifndef TIMER_H
#define TIMER_H

#include "mainwindow.h"
#include <QObject>


class Timer : public QObject {
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);
    MainWindow* mainWindow;
    void startTimer();
public slots:
    void run();

};

#endif // TIMER_H
