#pragma once

#include "construction/construction.hh"

class CArapuca{

    public:
        CArapuca(G4LogicalVolume* mother_volume, G4VPhysicalVolume* front_plate);
        ~CArapuca();
        G4VPhysicalVolume* GetPhysicalVolume();

    private:
        G4LogicalVolume* mother_volume;
        G4VPhysicalVolume* physical_front_plate;

};
