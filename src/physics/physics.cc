#include "physics/physics.hh"


PhysicsList::PhysicsList(){

    auto logmanager = std::make_shared<LogManager>("physics", "info", "", LOGFILE_PATH)->GetLogger();

    logmanager->info("Setting Physics...");

    logmanager->info("   Setting Optical Physics...");
    auto opticalPhysics = new G4OpticalPhysics();
    auto opticalParameters = G4OpticalParameters::Instance();
    //    opticalParameters->SetWLSTimeProfile("exponential");
    //    opticalParameters->SetProcessActivation(kCerenkov,true);
    //    opticalParameters->SetCerenkovTrackSecondariesFirst(true);
    //    opticalParameters->SetCerenkovMaxPhotonsPerStep(10);
    RegisterPhysics(opticalPhysics);

    logmanager->info("   Setting Fast Simulation Physics...");
    auto fastSimulationPhysics = new G4FastSimulationPhysics();
    fastSimulationPhysics->ActivateFastSimulation("opticalphoton"); // this is for the dichroic filter paremetrization
    RegisterPhysics(fastSimulationPhysics);

    logmanager->info("   Setting EM Physics...");
    auto emPhysics = new G4EmStandardPhysics();
    RegisterPhysics(emPhysics);

    logmanager->info("   Setting Decay Physics...");
    auto decayPhysics = new G4DecayPhysics();
    RegisterPhysics(decayPhysics);

    logmanager->info("   Done.");
}

PhysicsList::~PhysicsList() = default;
