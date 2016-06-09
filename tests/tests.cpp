#include <QtTest/QtTest>
#include <Controller.h>
#include <ControllerThread.h>
#include <ControllerFactory.h>
#include <QSharedPointer>
#include <QSignalSpy>

#include <ThrowingControllerFactory.h>

class ControllerThreadTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testLifetimeSynchronization()
    {
        QSharedPointer<QSignalSpy> spy;
        {
            ControllerThread ct( new ControllerFactory<Controller>() );
            spy = QSharedPointer<QSignalSpy>( new QSignalSpy( &ct, SIGNAL( finished() ) ) );
            QVERIFY( spy->isValid() );
            // check that the controller is alive
            QVERIFY( ct.isRunning() );
            QVERIFY( ct.controller().data() != 0 );
            // exit the block, this exits and joins the controller thread
        }
        // now check that the controller has exited properly
        QCOMPARE( spy->count(), 1 );
    }

    void testControllerCreationWithException()
    {
        QString msg( "This is the message from the broken factory." );
        // create a controller thread with a Controller object that throws an exception during instantiation
        try {
            ControllerThread ct( new ThrowingControllerFactory( msg ) );
            QFAIL( "An exception should have occured in the main thread by now.");
            Q_UNUSED( ct );
        } catch( ControllerException& e ) {
            // make sure the error is caught in the main thread
            QCOMPARE( msg, e.msg() ); // this exception is initially thrown in the controller thread
        } catch( ... ) {
            QFAIL( "Wrong exception type caught!" );
        }
    }
};

QTEST_MAIN(ControllerThreadTests)

#include "tests.moc"
