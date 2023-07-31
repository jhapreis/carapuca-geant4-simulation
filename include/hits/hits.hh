#pragma once

#include "G4VHit.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4UnitsTable.hh"

class Hits : public G4VHit{

public:
    Hits(G4Step* step);
    ~Hits();
    void Print();

private:
    int track_id;
    G4String particle_id;
    double energy_deposited;
    G4ThreeVector position;
    G4ThreeVector direction;
};
