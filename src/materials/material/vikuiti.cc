#include "materials/materials.hh"

namespace Materials{

G4Material *Vikuiti(){
    
    auto vikuiti = G4NistManager::Instance()->FindOrBuildMaterial("G4_KAPTON");

    auto properties = new G4MaterialPropertiesTable();

    std::vector<G4double> energies     = {1.65*CLHEP::eV, 3.10*CLHEP::eV};
    std::vector<G4double> rindex       = {1.            , 1.};

    properties->AddProperty("RINDEX", energies, rindex);

    vikuiti->SetMaterialPropertiesTable(properties);
    
    return vikuiti;
}

}//Materials
