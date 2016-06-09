#ifndef THROWINGCONTROLLERFACTORY_H
#define THROWINGCONTROLLERFACTORY_H

#include <ControllerFactory.h>
#include <StartupException.h>

class ThrowingControllerFactory : public ControllerFactory<Controller>
{
public:
    ThrowingControllerFactory( const QString& msg )
        : m_msg( msg )
    {}
    /* reimpl */
    virtual Controller* create() {
        throw StartupException( m_msg );
    }
private:
    QString m_msg;
};

#endif // THROWINGCONTROLLERFACTORY_H
