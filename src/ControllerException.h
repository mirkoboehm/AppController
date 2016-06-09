#ifndef CONTROLLEREXCEPTION_H
#define CONTROLLEREXCEPTION_H

#include <QtCore>

/** ControllerException are caught in the controller thread's run method, and transported to the main thread for error handling.
  QtConcurrent::Exception is re-used for that purpose, since it already implements the necessary means for cloning. */
class ControllerException: public QtConcurrent::Exception {
public:
    ControllerException( const QString& msg );

    ~ControllerException() throw() {}

    void raise() const;
    ControllerException *clone() const;
    QString msg() const;

private:
    QString m_msg;
};

#endif // CONTROLLEREXCEPTION_H
