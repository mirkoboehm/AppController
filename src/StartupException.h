#ifndef STARTUPEXCEPTION_H
#define STARTUPEXCEPTION_H

#include <ControllerException.h>

/** StartupException is the type of exception that controller objects should throw if errors occur during startup. */
class StartupException : public ControllerException {
public:
    StartupException( const QString& msg );
    // ~StartupException() throw() {}
};

#endif // STARTUPEXCEPTION_H
