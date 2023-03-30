#include "materials/materials.hh"

namespace Materials{

G4Material* EJ280(){

    auto BARWLS_DENSITY      = 1.;
    auto BARWLS_RINDEX       = 1.;
    auto BARWLS_ABSLENGTH    = 1.;
    auto BARWLS_EMISSION     = 1.;
    auto BARWLS_ABSORPTION   = 1.;
    auto BARWLS_TIMECONSTANT = 1.*CLHEP::ns;

    // Polystyrene (C8H8)n
    auto elC = G4NistManager::Instance()->FindOrBuildElement("C");
    auto elH = G4NistManager::Instance()->FindOrBuildElement("H");

    auto bar = new G4Material("EJ280", BARWLS_DENSITY * CLHEP::g / CLHEP::cm3, 2);
    bar->AddElement(elC, 8);
    bar->AddElement(elH, 8);

    auto barPropertiesTable = new G4MaterialPropertiesTable();

    // barPropertiesTable->AddProperty("BARWLS_RINDEX", BARWLS_RINDEX);
    // barPropertiesTable->AddProperty("BARWLS_ABSLENGTH", BARWLS_ABSLENGTH);
    // barPropertiesTable->AddProperty("BARWLS_EMISSION", BARWLS_EMISSION);
    // barPropertiesTable->AddProperty("BARWLS_ABSORPTION", BARWLS_ABSORPTION);

    // CONFIG::FillProperty("BARWLS_RINDEX", barPropertiesTable, eV);
    // CONFIG::FillProperty("BARWLS_ABSLENGTH", barPropertiesTable, eV, m);
    // CONFIG::FillProperty("BARWLS_EMISSION", barPropertiesTable, eV);
    // CONFIG::FillProperty("BARWLS_ABSORPTION", barPropertiesTable);

    barPropertiesTable->AddConstProperty("WLSTIMECONSTANT", BARWLS_TIMECONSTANT);

    bar->SetMaterialPropertiesTable(barPropertiesTable);

    return bar;
}

}//Materials
