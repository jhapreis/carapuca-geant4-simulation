#include "construction/construction.hh"

G4VPhysicalVolume* Construction::BuildWorldVolume(){

    auto air = Materials::Air();

    auto world_box      = new G4Box("World_Box", 100*CLHEP::cm, 100*CLHEP::cm, 100*CLHEP::cm);
    auto logical_world  = new G4LogicalVolume(world_box, air, "Logical_World");
    auto physical_world = new G4PVPlacement(nullptr, {0.,0.,0.}, logical_world, "Physical_World", nullptr, false, 0);
    logical_world->SetVisAttributes( new G4VisAttributes(false) );

    return physical_world;
}
