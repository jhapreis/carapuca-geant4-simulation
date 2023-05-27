#include "materials/materials.hh"

namespace Materials{

G4Material *Vacuum(){

    auto air = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");
    auto airPropertiesTable = new G4MaterialPropertiesTable();
    air->SetMaterialPropertiesTable(airPropertiesTable);
    auto nAir   = {1., 1.};
    auto energy = {1., 10.};
    airPropertiesTable->AddProperty("RINDEX", energy, nAir, 2);
    return air;
}

}//Materials
