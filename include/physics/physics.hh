#pragma once

#include "G4VModularPhysicsList.hh"

#include "globals.hh"
#include "G4ios.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4Material.hh"
#include "G4MaterialTable.hh"

#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4IonPhysics.hh"
#include "G4StoppingPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4NeutronTrackingCut.hh"
#include "G4Cerenkov.hh"

#include "G4HadronPhysicsFTFP_BERT.hh"

#include "G4OpticalParameters.hh"
#include "G4OpticalPhysics.hh"
#include "G4FastSimulationPhysics.hh"

#include ".cfg/logger.hh"

#include "logger/logmanager.hh"

class PhysicsList : public G4VModularPhysicsList{
    public:
        PhysicsList();
        ~PhysicsList() override;
};
