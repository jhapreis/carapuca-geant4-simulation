#include "materials/materials.hh"

namespace Materials{

G4Material* LiquidArgon(){

    auto lAr = G4NistManager::Instance()->FindOrBuildMaterial("G4_lAr");
    auto lArPropertiesTable = new G4MaterialPropertiesTable();
    lAr->SetMaterialPropertiesTable(lArPropertiesTable);

    // CONFIG::FillProperty("LAR_RINDEX", lArPropertiesTable);
    // CONFIG::FillProperty("LAR_ABSLENGTH", lArPropertiesTable);
    // CONFIG::FillProperty("LAR_SCINTILLATION", lArPropertiesTable, CLHEP::eV);

    lArPropertiesTable->AddConstProperty("SCINTILLATIONYIELD", 240 / CLHEP::MeV);
    lArPropertiesTable->AddConstProperty("RESOLUTIONSCALE", 1.0);
    // lArPropertiesTable->AddConstProperty("FASTTIMECONSTANT", 6.2 * CLHEP::ns);

    return lAr;
}

} // Materials
