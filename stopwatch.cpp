#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    min = 0;
    sec = 0;
    ms = 0;

    cache_min = 0;
    cache_sec = 0;
    cache_ms = 0;

    connect(timer, &QTimer::timeout, this, &Stopwatch::timeWorker);
}

void Stopwatch::start()
{
    timer->start(10);
}

void Stopwatch::stop()
{
    timer->stop();
}

void Stopwatch::reset()
{
    ms = 0;
    sec = 0;
    min = 0;

    cache_min = 0;
    cache_sec = 0;
    cache_ms = 0;
}

QString Stopwatch::calcTime()
{
    int new_min = min - cache_min;

    int new_sec = sec;
    if(new_sec < cache_sec){
        new_min--;
        new_sec = 60 + new_sec - cache_sec;
    }
    else{
        new_sec = new_sec - cache_sec;
    }

    int new_ms = ms;
    if(new_ms < cache_ms)
    {
        if(new_sec == 0)
        {
            new_min--;
            new_sec = 59;
        }
        else{
            new_sec--;
        }

        new_ms = 100 + new_ms - cache_ms;
    }
    else{
        new_ms = new_ms - cache_ms;
    }

    cache_min = min;
    cache_sec = sec;
    cache_ms = ms;

    return QString::number(new_min) + ':' + QString::number(new_sec) + ':' + QString::number(new_ms);
}

void Stopwatch::timeWorker(){
    ms++;
    if(ms >= 100){
        ms = 0;
        sec++;
    }
    if(sec >= 60){
        sec = 0;
        min++;
    }

    emit sgnl_startTimer(QString::number(min), QString::number(sec), QString::number(ms));
}
