
#include "timer.h"
#include <QApplication>
#include <QLoggingCategory>

Timer::Timer(QObject *parent) : QObject{parent} {

}

void Timer::run() {
    mainWindow->formControl->stopSearch();
    uint64_t prog, end, seed;
    mainWindow->formControl->sthread.getProgress(&prog, &end, &seed);
    QDebug info = qInfo();
    info.noquote();
    info << QString::asprintf("PROGRESS: %" PRIu64, seed);
    QApplication::quit();
}

// timer to cancel search after 5 minutes
void Timer::startTimer() {
    QTimer::singleShot(5*60*1000, this, SLOT(run()));
}
