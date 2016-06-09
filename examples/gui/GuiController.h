#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <Controller.h>
#include <ControllerFactory.h>

class GuiController : public Controller
{
    Q_OBJECT
public:
    GuiController();

public Q_SLOTS:
    void requestTimeOfDay();

Q_SIGNALS:
    void timeOfDay( QString );
};

#endif // GUICONTROLLER_H
