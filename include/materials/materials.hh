#pragma once

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"

namespace Materials{

    G4Material* Air();
    G4Material* EJ280();
    G4Material* EJ286();
    G4Material* G10();
    G4Material* LiquidArgon();
    G4Material* OpticalGlass();
    G4Material* PTP();
    G4Material* Silicon();
    G4Material* Vacuum();
    G4Material* Vikuiti();

} // Materials
