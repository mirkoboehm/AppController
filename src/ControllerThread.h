#ifndef CONTROLLERTHREAD_H
#define CONTROLLERTHREAD_H

#include <QThread>
#include <QSharedPointer>
#include <Controller.h>
#include <ControllerFactory.h>
#include <QSemaphore>

#include <ControllerException.h>
#include <ControllerFactory.h>

/** ControllerThread encapsulates the controller thread, and it's life time.
The thread will be started in the constructor, and joined in the destructor.
If the thread is still running when the destructor is entered, it will quit the event loop.
ControllerThread assumes that it will run an event loop. If this is not the case, it might
not be the right tool for the job.
*/
class ControllerThread : public QThread {
    Q_OBJECT

public:
    /** Create the controller thread, start it, and wait for the run method to start.
      The contructor will only exit once the run method was started, and the controller object was created.
      */
    explicit ControllerThread( ControllerFactoryBase* factory, QObject* parent = 0 );
    /** Destroy the thread, and make sure it's event loop was exited and the thread was properly joined. */
    ~ControllerThread();

    /** Access the controller object.
      The controller thread provides the context in which the controller thread executes it's operations.
      The controller object is a QObject that is created within the run method. */
    QSharedPointer<Controller> controller() const;

    /** The threads run method. It creates the controller object, and then executes the threads event loop.
      The controller object is held in a shared pointer.
      There is usually no need to overload this method. */
    void run();

private:
    QSharedPointer<Controller> m_controller;
    ControllerFactoryBase* m_factory;
    QSemaphore m_semaphore;
    ControllerException* m_startupException;
};

#endif
