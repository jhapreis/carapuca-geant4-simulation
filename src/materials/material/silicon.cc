#include "materials/materials.hh"

namespace Materials{

G4Material *Silicon(){

    auto silicon = G4NistManager::Instance()->FindOrBuildMaterial("G4_Si");
    auto siPropertiesTable = new G4MaterialPropertiesTable();

    std::vector<G4double> energies  = {1.65*CLHEP::eV, 3.10*CLHEP::eV};
    std::vector<G4double> rindex    = {1., 1.};
    std::vector<G4double> abslength = {1*CLHEP::nm, 1*CLHEP::nm}; // arbitrarily small value

    siPropertiesTable->AddProperty("RINDEX", energies, rindex);
    siPropertiesTable->AddProperty("ABSLENGTH", energies, abslength);
    silicon->SetMaterialPropertiesTable(siPropertiesTable);

    return silicon;
}
}//Materials
