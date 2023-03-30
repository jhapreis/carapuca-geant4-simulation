#include "materials/materials.hh"

namespace Materials{

G4Material* EJ286(){
    return nullptr;
    
    // using namespace CLHEP;

    // // Polystyrene (C8H8)n
    // auto elC = G4NistManager::Instance()->FindOrBuildElement("C");
    // auto elH = G4NistManager::Instance()->FindOrBuildElement("H");

    // auto bar = new G4Material("EJ286", CONFIG::Value("BARWLS_DENSITY") * g / cm3, 2);
    // bar->AddElement(elC, 8);
    // bar->AddElement(elH, 8);

    // auto barPropertiesTable = new G4MaterialPropertiesTable();

    // CONFIG::FillProperty("BARWLS_RINDEX", barPropertiesTable, eV);
    // CONFIG::FillProperty("BARWLS_ABSLENGTH", barPropertiesTable, eV, m);
    // CONFIG::FillProperty("BARWLS_EMISSION", barPropertiesTable, eV);
    // CONFIG::FillProperty("BARWLS_ABSORPTION", barPropertiesTable);

    // barPropertiesTable->AddConstProperty("WLSTIMECONSTANT", CONFIG::Value("BARWLS_TIMECONSTANT")*ns);

    // bar->SetMaterialPropertiesTable(barPropertiesTable);

    // return bar;
}

}//Materials
