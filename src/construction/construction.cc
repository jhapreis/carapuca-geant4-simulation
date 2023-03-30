#include "construction/construction.hh"

Construction::Construction(){
    logmanager = std::make_shared<LogManager>("construction", "info", "", LOGFILE_PATH)->GetLogger();
}

Construction::~Construction() = default;

G4VPhysicalVolume *Construction::Construct()
{
    logmanager->info("Constructing...");

    physical_world = GenerateWorld();
    physical_carapuca = GenerateCArapuca();

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

G4VPhysicalVolume* Construction::GenerateCArapuca(){

    logmanager->info("Generating Physical CARAPUCA...");

    auto front_plate = BuildFrontPlate();

    auto carapuca = new CArapuca(physical_world->GetLogicalVolume(), front_plate);

    return carapuca->GetPhysicalVolume();
}

G4VPhysicalVolume* Construction::BuildFrontPlate(){
    logmanager->info("Building Front Plate...");

    auto config_file = std::string("data/carapuca/front_plate/");

    auto json_external          = JsonFile(config_file+"external.json");
    auto json_filter            = JsonFile(config_file+"filter.json");
    auto json_window_cut_filter = JsonFile(config_file+"window_cut_filter.json");
    auto json_window_cut_sipm   = JsonFile(config_file+"window_cut_sipm.json");
    auto json_window_cut_window = JsonFile(config_file+"window_cut_window.json");
    
    logmanager->info("   Building External...");
    auto external = new carapuca::front_plate::External(
        {
            json_external.GetDouble("lenght")*cm, 
            json_external.GetDouble("width")*cm, 
            json_external.GetDouble("height")*cm
        }
    );
    
    logmanager->info("   Building Filter...");
    auto filter = new carapuca::front_plate::Filter(
        {
            json_filter.GetDouble("pos")*cm
        }
    );
    
    logmanager->info("   Building WindowCutFilter...");
    auto window_cut_filter = new carapuca::front_plate::WindowCutFilter(
        {
            json_window_cut_filter.GetDouble("lenght")*cm, 
            json_window_cut_filter.GetDouble("width")*cm, 
            json_window_cut_filter.GetDouble("height")*cm
        }
    );
    
    logmanager->info("   Building WindowCutSipm...");
    auto window_cut_sipm = new carapuca::front_plate::WindowCutSipm(
        {
            json_window_cut_sipm.GetDouble("lenght")*cm, 
            json_window_cut_sipm.GetDouble("width")*cm, 
            json_window_cut_sipm.GetDouble("pos")*cm
        }
    );
    
    logmanager->info("   Building WindowCutWindow...");
    auto window_cut_window = new carapuca::front_plate::WindowCutWindow(
        {
            json_window_cut_window.GetDouble("lenght")*cm, 
            json_window_cut_window.GetDouble("width")*cm
        }
    );

    logmanager->info("   Assembling Front Plate...");
    auto front_plate = new carapuca::front_plate::FrontPlate(
        physical_world->GetLogicalVolume(),
        Materials::G10(),
        external,
        filter,
        window_cut_filter,
        window_cut_sipm,
        window_cut_window,
        {0.,0.,0.},
        nullptr);

    logmanager->info("   Done.");

    return front_plate->GetPhysicalVolume();
}


G4VPhysicalVolume* Construction::BuildBackPlate(){
    logmanager->info("Building Back Plate...");

    return nullptr;
}
