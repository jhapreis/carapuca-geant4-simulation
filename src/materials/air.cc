#include "materials/materials.hh"

namespace Materials{

G4Material* Air(){

    auto air = G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR");

    return air;
}

} // Materials
