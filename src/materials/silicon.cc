#include "materials/materials.hh"

namespace Materials{

G4Material *Silicon(){

    auto silicon = G4NistManager::Instance()->FindOrBuildMaterial("G4_Si");
    auto siPropertiesTable = new G4MaterialPropertiesTable();
    silicon->SetMaterialPropertiesTable(siPropertiesTable);
    // CONFIG::FillProperty("BARWLS_RINDEX", siPropertiesTable); // avoid surface reflection
    // CONFIG::FillProperty("SI_ABSLENGTH", siPropertiesTable);  // high AbsLength to kill the photon

    return silicon;
}
}//Materials
