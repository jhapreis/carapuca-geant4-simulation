#include "physics/physics.hh"


PhysicsList::PhysicsList(){

    auto logmanager = std::make_shared<LogManager>("physics", "info", "", LOGFILE_PATH)->GetLogger();

    logmanager->info("Setting Physics...");

    logmanager->info("   Setting Optical Physics...");
    RegisterPhysics(new G4OpticalPhysics());

//    logmanager->info("   Setting Fast Simulation Physics...");
//    auto fastSimulationPhysics = new G4FastSimulationPhysics();
//    fastSimulationPhysics->ActivateFastSimulation("opticalphoton"); // this is for the dichroic filter paremetrization
//    RegisterPhysics(fastSimulationPhysics);

    logmanager->info("   Setting EM Physics...");
    RegisterPhysics(new G4EmStandardPhysics());

    logmanager->info("   Setting Decay Physics...");
    RegisterPhysics(new G4DecayPhysics());

    logmanager->info("   Done.");
}

PhysicsList::~PhysicsList() = default;
