#include "materials/materials.hh"

namespace Materials{

G4Material* Glass(){
    
    auto glass = G4NistManager::Instance()->FindOrBuildMaterial("G4_GLASS_PLATE");

    auto properties = new G4MaterialPropertiesTable();
    glass->SetMaterialPropertiesTable(properties);

    std::vector<G4double> energies   = {1.65*CLHEP::eV, 3.10*CLHEP::eV};
    std::vector<G4double> rindex     = {2.50          , 2.50};
    std::vector<G4double> abs_lenght = {10*CLHEP::m   , 10*CLHEP::m};


    properties->AddProperty("RINDEX"   , energies, rindex);
    properties->AddProperty("ABSLENGTH", energies, abs_lenght);

    return glass;        
}

}//Materials
