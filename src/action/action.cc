#include "action/action.hh"

void ActionInitialization::Build() const {
    SetUserAction( new PrimaryGenerator );
};
