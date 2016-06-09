#include <QApplication>
#include <QtDebug>
#include <ControllerThread.h>
#include <QMutexLocker>

ControllerThread::ControllerThread( ControllerFactoryBase* factory, QObject* parent )
    : QThread( parent )
    , m_factory( factory )
    , m_startupException( 0 )
{
    start();
    m_semaphore.acquire();
    qDebug() << Q_FUNC_INFO << "Controller object has been created";
    if( m_startupException != 0 ) {
        // if there was an exception during startup, the thread is expected to exit right
        // away:
        wait();
        throw *m_startupException;
    }
}

ControllerThread::~ControllerThread()
{
    if( isRunning() ) {
        quit();
    }
    wait();
    qDebug() << Q_FUNC_INFO << "Controller thread has exited.";
}

QSharedPointer<Controller> ControllerThread::controller() const
{
    return m_controller;
}

void ControllerThread::run()
{
    Q_ASSERT_X( m_semaphore.available() == 0, Q_FUNC_INFO, "No semaphore resources should be available when the thread starts.");
    qDebug() << Q_FUNC_INFO << "Starting thread" << this->thread();
    try {
        m_controller = QSharedPointer<Controller>( m_factory->create() );
        m_semaphore.release();
    } catch( ControllerException& e ) {
        m_startupException = e.clone();
        m_semaphore.release(); // this would be nice in a "finally" block, heh?
        return;
    }

    exec();
    qDebug() << Q_FUNC_INFO << "Leaving thread" << this->thread();
}
