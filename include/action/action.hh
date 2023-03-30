#pragma once

#include "G4VUserActionInitialization.hh"
#include "generator/generator.hh"

class ActionInitialization : public G4VUserActionInitialization{
public:
    virtual void Build() const override;
};
