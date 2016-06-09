#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

/** The Controller class is a QObject that is instantiated in the controller thread. It provides the operations to the application.
  */
class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller( QObject* parent = 0 );

public Q_SLOTS:
    void quit();
};

#endif
