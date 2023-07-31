#pragma once

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include <G4RNGHelper.hh>
#include <G4String.hh>
#include "../3rdparty/rapidcsv/rapidcsv.h"

namespace Materials{

    G4Material* Air();
    G4Material* EJ286();
    G4Material* G10();
    G4Material* Glass();
    G4Material* Silicon();
    G4Material* Vikuiti();
    G4Material* Water();

class Properties{
    public:
        explicit Properties(const char * filename);
        void ReadDataFromCSV(const char * energy_col, const char * property_col, G4double energy_unit = CLHEP::eV, G4double property_unit = 1.);
        
        const char * filename;
        std::vector<G4double> energies;
        std::vector<G4double> property;
};

} // Materials
