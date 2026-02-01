#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

class Stopwatch:public QObject
{
    Q_OBJECT

public:
    Stopwatch(QObject *parent=nullptr);
    void start();
    double stop();
    void reset();
    double elapsedTime() const;
    double lastTime = 0;

signals:
    void timeChanged (double time);

private slots:
      void updateTime();

private:
      QTimer *timer;
      double timeElapsed;
};

#endif // STOPWATCH_H
