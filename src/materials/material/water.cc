#include "materials/materials.hh"

namespace Materials{

    G4Material* Water(){

        auto water = G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER");

        auto properties = new G4MaterialPropertiesTable();

        std::vector<G4double> energies = {1.65*CLHEP::eV, 3.10*CLHEP::eV};
        std::vector<G4double> rindex   = {1.33          , 1.33};

        properties->AddProperty("RINDEX", energies, rindex);

        water->SetMaterialPropertiesTable(properties);

        return water;
    }

} // Materials
