#include <QThread>

#include <Controller.h>

Controller::Controller( QObject* parent )
    : QObject( parent )
{}

/** Tell the containing thread to exit the event loop. */
void Controller::quit()
{
    thread()->quit();
}

