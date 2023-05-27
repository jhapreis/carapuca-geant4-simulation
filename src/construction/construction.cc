#include "construction/construction.hh"

Construction::Construction(G4String const& carapuca_filename)
:
carapuca_filename(carapuca_filename)
{
    logmanager = std::make_shared<LogManager>("construction", "info", "", LOGFILE_PATH)->GetLogger();
}

Construction::~Construction() = default;

G4VPhysicalVolume* Construction::Construct(){
    auto vaccum = Materials::Vacuum();
    printf("----- Vaccum Temperature: %f.\n", vaccum->GetTemperature());

    auto world_box      = new G4Box("World_Box", 100*CLHEP::mm, 100*CLHEP::mm, 100*CLHEP::mm);
    auto logical_world  = new G4LogicalVolume(world_box, vaccum, "Logical_World");
    auto physical_world = new G4PVPlacement(nullptr, {0.,0.,0.}, logical_world, "Physical_World", nullptr, false, 0);

    auto box          = new G4Box("Box", 100*CLHEP::mm, 50*CLHEP::mm, 5*CLHEP::mm);
    auto logical_box  = new G4LogicalVolume(box, vaccum, "logical_box");
    auto phsyical_box = new G4PVPlacement(nullptr, {0.,0.,0.}, logical_box, "physical_box", physical_world->GetLogicalVolume(), false, 0);

    return phsyical_box;
}


G4VPhysicalVolume* BuildCarapuca(){

    auto vaccum = Materials::Vacuum();
    // auto air = Materials::Air();
    // auto vikuiti = Materials::Vikuiti();
    // auto ej286 = Materials::EJ286();
    // auto glass = Materials::OpticalGlass();


    //World

    auto worldBox = new G4Box("worldBox", 100*CLHEP::mm, 100*CLHEP::mm, 100*CLHEP::mm);
    auto logicalWorld = new G4LogicalVolume(worldBox, vaccum, "Logical World");
    auto physicalWorld = new G4PVPlacement(nullptr, {0,0,0}, logicalWorld, "Physical World", nullptr, false, 0);


    // Outside box

    auto x  = 93*CLHEP::mm/2;
    auto y1 = 10.5*CLHEP::mm/2;
    auto z  = 70*CLHEP::mm/2;
    auto thickness = 8.70*CLHEP::mm/2;

    auto __out_box = new G4Box("outside_box", x, y1, z);
    auto __in_box  = new G4Box("inside_box" , x-thickness, y1-0.001*CLHEP::mm, z-thickness );

    auto box = new G4SubtractionSolid("box", __out_box, __in_box, nullptr, {0,thickness,0});

    auto logical_box = new G4LogicalVolume(box, vaccum, "logical_box");

    auto physical_box = new G4PVPlacement(nullptr, {0,0,0}, "physical_box", logical_box, physicalWorld, false, 0, false);

    
    // Dichroic Filter

    auto y2 = 2*CLHEP::mm/2;

    auto filter = new G4Box("filter", x, y2, z);

    auto logical_filter = new G4LogicalVolume(filter, vaccum, "logical_filter");

    auto physical_filter = new G4PVPlacement(nullptr, {0,y1+y2,0}, "physical_filter", logical_filter, physicalWorld, false, 0, false);


    // Light guide

    auto y3 = 3.8*CLHEP::mm/2;

    auto light_guide = new G4Box("light_guide", x, y3, z);

    auto logical_light_guide = new G4LogicalVolume(light_guide, vaccum, "logical_box");

    auto physical_light_guide = new G4PVPlacement(nullptr, {0,y1+y2+y3,0}, "physical_light_guide", logical_light_guide, physicalWorld, false, 0, false);


    // SiPM

    auto size = 6*CLHEP::mm/2;
    thickness = 0.1*CLHEP::mm/2;

    auto sipm = new G4Box("sipm", size, size, thickness);

    auto logical_sipm = new G4LogicalVolume(sipm, vaccum, "logical_sipm");

    // auto physical_sipm = new G4PVPlacement(nullptr, {x-thickness, y1/2, z-thickness}, "physical_sipm", logical_sipm, physicalWorld, false, 0, false);


    return physicalWorld;
};


G4VPhysicalVolume* Construction::GenerateCArapuca(G4Material* material, G4String const& filename, G4int scale, G4VSensitiveDetector *pSDetector, G4LogicalVolume* pMotherVolume, G4RotationMatrix *pRot, const G4ThreeVector &translation){

    auto carapuca = CADMesh::TessellatedMesh::FromOBJ(filename);

    carapuca->SetScale(scale);

    auto carapuca_logical = new G4LogicalVolume( carapuca->GetSolid(), material, "carapuca_logical", nullptr, pSDetector, nullptr, true);

    auto carapuca_physical = new G4PVPlacement(pRot, translation, carapuca_logical, "carapuca_physical", pMotherVolume, false, 0, false);

    return carapuca_physical;
}
