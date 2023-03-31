#include "construction/carapuca/carapuca.hh"

CArapuca::CArapuca(
    G4LogicalVolume* mother_volume,
    G4VPhysicalVolume* front_plate
)
:
    mother_volume(mother_volume),
    physical_front_plate(front_plate)
{

}

CArapuca::~CArapuca() = default;


G4VPhysicalVolume* CArapuca::GetPhysicalVolume(){
    return physical_front_plate;
}
