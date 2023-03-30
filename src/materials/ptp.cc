#include "materials/materials.hh"

namespace Materials{

G4Material *PTP(){

    auto pTP = G4NistManager::Instance()->FindOrBuildMaterial("G4_TERPHENYL");
    auto pTPPropertiesTable = new G4MaterialPropertiesTable();
    pTP->SetMaterialPropertiesTable(pTPPropertiesTable);
    
    // CONFIG::FillProperty("pTP_RINDEX", pTPPropertiesTable, eV);
    // CONFIG::FillProperty("pTP_ABSLENGTH", pTPPropertiesTable, eV, mm);
    // CONFIG::FillProperty("pTP_EMISSION", pTPPropertiesTable, eV);
    // CONFIG::FillProperty("pTP_ABSORPTION", pTPPropertiesTable);


    // //pTPPropertiesTable->AddConstProperty("WLSMEANNUMBERPHOTONS", 10);
    // pTPPropertiesTable->AddConstProperty("WLSTIMECONSTANT", CONFIG::Value("pTP_TIMECONSTANT")*ns);
    // //pTPPropertiesTable->AddConstProperty("WLSMEANNUMBERPHOTONS", 1); //CONFIG::Value("pTP_MEANNUMBERPHOTONS"));
    pTP->SetMaterialPropertiesTable(pTPPropertiesTable);

    return pTP;
}

}//Materials
