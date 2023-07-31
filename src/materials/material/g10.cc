#include "materials/materials.hh"

namespace Materials{

G4Material* G10(){
    
    using namespace CLHEP;

    auto elC = G4NistManager::Instance()->FindOrBuildElement("C");
    auto elH = G4NistManager::Instance()->FindOrBuildElement("H");
    auto elO = G4NistManager::Instance()->FindOrBuildElement("O");
    auto elSi = G4NistManager::Instance()->FindOrBuildElement("Si");

    auto G10 = new G4Material("G10", 1.700*g/cm3, 4);
    G10->AddElement(elSi,1);
    G10->AddElement(elO, 2);
    G10->AddElement(elC, 3);
    G10->AddElement(elH, 3);        

    return G10;
}
} // Materials
