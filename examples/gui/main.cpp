#include <QApplication>

#include <ControllerThread.h>
#include <MainWindow.h>
#include <GuiController.h>

int main( int argc,  char** argv ) {
    QApplication app(  argc, argv );
    MainWindow mainwindow;
    ControllerThread ct( new ControllerFactory<GuiController>() );
    // connect view and controller
    QObject::connect( &mainwindow, SIGNAL( requestTimeOfDay() ),
                     ct.controller().data(), SLOT( requestTimeOfDay() ) );
    QObject::connect( ct.controller().data(), SIGNAL( timeOfDay( QString ) ),
                     &mainwindow, SLOT(receiveTimeOfDay( QString ) ) );
    mainwindow.show();
    return app.exec();
}
