#include <iostream>

#include "hits/hits.hh"
#include "sensitive/sensitive.hh"

SensorDetector::SensorDetector(const G4String &name) : G4VSensitiveDetector(name)
{
    std::cout << "Creating Sensor Detector named " << name << std::endl;;
}

SensorDetector::~SensorDetector() = default;

G4bool SensorDetector::ProcessHits(G4Step*aStep, G4TouchableHistory* tHist){
    if (aStep->GetTotalEnergyDeposit()!=0) {
        std::cout << "Processing Hits..." << std::endl;
        auto aHit = new Hits(aStep);
        aHit->Print();
        delete aHit;
        return true;
    }
    return false;
}
