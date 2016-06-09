#ifndef CONTROLLERFACTORY_H
#define CONTROLLERFACTORY_H

#include <QSharedPointer>

class Controller;

/** A non-templated base class for the factory to be used as a generic argument to the controller thread. */
class ControllerFactoryBase
{
public:
    virtual Controller* create() = 0;
};

/** The controller factory is passed in to the controller thread.
  It is used to create a Controller object in the controller thread.
  Unless it requires special creation arguments, the templated factory
  implementation should suffice.
*/
template<class ControllerType>
class ControllerFactory : public ControllerFactoryBase
{
    virtual ControllerType* create() {
        return new ControllerType();
    }
};

#endif // CONTROLLERFACTORY_H
