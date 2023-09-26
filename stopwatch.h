#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();
    QString calcTime();

public slots:
    void timeWorker();

private:
    QTimer* timer;
    int min, sec, ms;
    int cache_min, cache_sec, cache_ms;

signals:
    void sgnl_startTimer(QString min, QString sec, QString ms);
};

#endif // STOPWATCH_H
