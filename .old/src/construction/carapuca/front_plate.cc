#include "construction/carapuca/front_plate.hh"


namespace carapuca::front_plate{

FrontPlate::FrontPlate
(
    G4LogicalVolume* mother_volume,
    G4Material* material,
    External const* external,
    Filter const* filter,
    WindowCutFilter const* window_cut_filter, 
    WindowCutSipm const* window_cut_sipm, 
    WindowCutWindow const* window_cut_window,
    const G4ThreeVector &translation, 
    G4RotationMatrix *pRot
)
:   
    mother_volume(mother_volume),
    material(material),
    external(external),
    filter(filter),
    window_cut_filter(window_cut_filter),
    window_cut_sipm(window_cut_sipm),
    window_cut_window(window_cut_window)
{

    logical_volume = LogicalConstruct("log_carapuca_frontplate");
    physical_volume = PhysicalConstruct("phy_carapuca_frontplate", translation, pRot);

}


FrontPlate::~FrontPlate() = default;


G4LogicalVolume* FrontPlate::GetLogicalVolume(){
    return logical_volume;
}


G4VPhysicalVolume* FrontPlate::GetPhysicalVolume(){
    return physical_volume;
}


G4LogicalVolume* FrontPlate::LogicalConstruct(const G4String & name)
{
    // Box front plate cover
    auto boxFrontPlateCover = new G4Box(
        "boxFrontCoverPlate",
        external->length/2,
        external->height/2, 
        external->width/2
    );

    // SiPM fitting cuts
    auto fpcSiPMHole = new G4Box(
        "boxFCPSiPMHole",
        window_cut_sipm->length / 2,
        external->height,
        window_cut_sipm->width / 2
    );

    // Acceptance window
    auto fpcFilterWindow = new G4Box(
        "boxFCPFilterHole",
        window_cut_window->length / 2,
        external->height,
        window_cut_window->width / 2
    );

    auto solidFPCAperture = new G4UnionSolid("solidFCPAperture",fpcSiPMHole,fpcFilterWindow);

    // Filter fitting indentation
    auto fcpFilterWindow = new G4Box(
        "boxFCPFilterHole",
        window_cut_filter->length / 2,
        external->height/2,
        window_cut_filter->width / 2
    );

    auto y = external->height - window_cut_filter->height;
    auto solidFPCWindow = new G4UnionSolid(
        "solidFCPAperture",
        solidFPCAperture,
        fcpFilterWindow,
        nullptr,
        {0,y,0}
    );

    // Cutting two cells
    auto x = window_cut_sipm->length / 2 + window_cut_sipm->pos;

    auto fcpSubLeft  = new G4SubtractionSolid("solidFCPLeft" , boxFrontPlateCover, solidFPCWindow, nullptr, {x,0,0});
    auto fcpSubRight = new G4SubtractionSolid("solidFCPRight", fcpSubLeft, solidFPCWindow, nullptr, {-x,0,0});

    return new G4LogicalVolume(fcpSubRight, material, name);
}


G4VPhysicalVolume* FrontPlate::PhysicalConstruct(const G4String & name, const G4ThreeVector &translation, G4RotationMatrix *pRot){
    return new G4PVPlacement(pRot, translation, logical_volume, name, mother_volume, false, 0, true);
}

} // carapuca::front_plate
