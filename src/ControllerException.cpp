#include "ControllerException.h"

ControllerException::ControllerException( const QString& msg )
    : m_msg( msg )
{}

void ControllerException::raise() const
{
    throw *this;
}

ControllerException *ControllerException::clone() const
{
    return new ControllerException( *this );
}

QString ControllerException::msg() const
{
    return m_msg;
}
