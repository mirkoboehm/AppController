#include <QTime>

#include "GuiController.h"

GuiController::GuiController()
{
}

void GuiController::requestTimeOfDay()
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString();
    emit timeOfDay( timeString );
}

