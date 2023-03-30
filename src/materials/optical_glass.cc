#include "materials/materials.hh"

namespace Materials{

G4Material* OpticalGlass(){
    using namespace CLHEP;
    
    auto glass = G4NistManager::Instance()->FindOrBuildMaterial("G4_GLASS_PLATE");
    auto glassPropertiesTable = new G4MaterialPropertiesTable();
    glass->SetMaterialPropertiesTable(glassPropertiesTable);
    // CONFIG::FillProperty("FILTER_OPTO_RINDEX", glassPropertiesTable); 
    // CONFIG::FillProperty("LAR_ABSLENGTH", glassPropertiesTable);

    return glass;        
}

}//Materials
