#pragma once
#include "G4VSensitiveDetector.hh"

class SensorDetector : public G4VSensitiveDetector{
public:
    explicit SensorDetector(const G4String &name);
    ~SensorDetector() override;
    G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist) override;
};
