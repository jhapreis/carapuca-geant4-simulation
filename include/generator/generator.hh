#pragma once

#include "G4VUserActionInitialization.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Geantino.hh"

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction{
private:
    G4ParticleGun *m_ParticleGun;
public:

    PrimaryGenerator();
    ~PrimaryGenerator();

    virtual void GeneratePrimaries(G4Event* anEvent) override;
};
