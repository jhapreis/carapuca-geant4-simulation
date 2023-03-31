#include "construction/construction.hh"

Construction::Construction(G4String const& carapuca_filename)
:
carapuca_filename(carapuca_filename)
{
    logmanager = std::make_shared<LogManager>("construction", "info", "", LOGFILE_PATH)->GetLogger();
}

Construction::~Construction() = default;

G4VPhysicalVolume *Construction::Construct()
{
    logmanager->info("Constructing...");

    physical_world = GenerateWorld();


    auto vikuiti = Materials::Vikuiti();

    physical_carapuca = GenerateCArapuca(
        vikuiti,
        carapuca_filename,
        500,
        nullptr,
        physical_world->GetLogicalVolume(),
        nullptr,
        G4ThreeVector(0.,0.,0.)
    );

    return physical_world;
}

G4VPhysicalVolume *Construction::GenerateTestVolume()
{
    logmanager->info("Generating test volume...");

    auto air = Materials::Air();

    auto position = G4ThreeVector(0., 0., 0.);

    auto test  = new G4Tubs("volTest", 0., 10.*cm, 20.*cm, 0., 2*M_PI*rad);
    auto logic = new G4LogicalVolume(test, air, "LogicalVolume");
    auto physi = new G4PVPlacement(nullptr, position, logic, "PhysicalVolume", physical_world->GetLogicalVolume(), false, 0, true);

    return physi;
}

G4VPhysicalVolume *Construction::GenerateWorld(){

    logmanager->info("Generating Physical World...");

    auto lAr = Materials::LiquidArgon();

    auto position = G4ThreeVector(0., 0., 0.);

    auto worldBox = new G4Box("worldBox", 0.5 * m, 0.5 * m, 0.5 * m);
    auto logWorld = new G4LogicalVolume(worldBox, lAr, "LogicalWorld");
    auto phyWorld = new G4PVPlacement(nullptr, position, logWorld, "PhysicalWorld", nullptr, false, 0, true);
    return phyWorld;
}

G4VPhysicalVolume* Construction::GenerateCArapuca(G4Material* material, G4String const& filename, G4int scale, G4VSensitiveDetector *pSDetector, G4LogicalVolume* pMotherVolume, G4RotationMatrix *pRot, const G4ThreeVector &translation){

    auto carapuca = CADMesh::TessellatedMesh::FromOBJ(filename);

    carapuca->SetScale(scale);

    auto carapuca_logical = new G4LogicalVolume( carapuca->GetSolid(), material, "carapuca_logical", nullptr, pSDetector, nullptr, true);

    auto carapuca_physical = new G4PVPlacement(pRot, translation, carapuca_logical, "carapuca_physical", pMotherVolume, false, 0, false);

    return carapuca_physical;
}
