#include "materials/materials.hh"

namespace Materials{

G4Material *Vikuiti(){
    
    auto vikuiti = G4NistManager::Instance()->FindOrBuildMaterial("G4_KAPTON");
    
    return vikuiti;
}

}//Materials
