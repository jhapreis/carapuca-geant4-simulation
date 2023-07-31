#include "construction/construction.hh"

Construction::Construction(G4String const& carapuca_filename)
:
carapuca_filename(carapuca_filename)
{
    logmanager = std::make_shared<LogManager>("construction", "info", "", LOGFILE_PATH)->GetLogger();
}

Construction::~Construction() = default;

G4VPhysicalVolume* Construction::Construct(){
    auto vikuiti = Materials::Vikuiti();

    mother_volume = BuildWorldVolume();

    auto out_box = new G4Box("Box", 50*CLHEP::mm, 50*CLHEP::mm, 50*CLHEP::mm);
    auto out_logical_box  = new G4LogicalVolume(out_box, vikuiti, "logical_box");
    auto out_phsyical_box = new G4PVPlacement(nullptr, {0.,0.,0.}, out_logical_box, "out_physical_box", mother_volume->GetLogicalVolume(), false, 0);

    BuildVikuitiAirSurface(out_phsyical_box, mother_volume);

    BuildDetector();

    return mother_volume;
}


G4VPhysicalVolume* BuildCarapuca(){

    auto vaccum = Materials::Air();


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
