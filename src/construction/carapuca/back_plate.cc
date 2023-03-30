#include "construction/carapuca/back_plate.hh"


namespace carapuca::back_plate{


BackPlate::BackPlate
(
    G4LogicalVolume* mother_volume,
    G4Material* material,
    External const* external,
    BackCutSipm const* back_cut_sipm,
    const G4ThreeVector &translation, 
    G4RotationMatrix *pRot
)
:   
    mother_volume(mother_volume),
    material(material),
    external(external),
    back_cut_sipm(back_cut_sipm)
{
    logical_volume = LogicalConstruct("log_carapuca_backplate");
    physical_volume = PhysicalConstruct("phy_carapuca_backplate", translation, pRot);
}


BackPlate::~BackPlate() = default;


G4LogicalVolume* BackPlate::GetLogicalVolume(){
    return logical_volume;
}


G4VPhysicalVolume* BackPlate::GetPhysicalVolume(){
    return physical_volume;
}


G4LogicalVolume* BackPlate::LogicalConstruct(const G4String & name)
{
    auto boxBackPlateCover = new G4Box("boxFrontCoverPlate", external->length/2, external->height/2, external->width/2);

    auto bpcSiPMCut   = new G4Box("bpcSiPMCut", back_cut_sipm->length/2, external->height/2, back_cut_sipm->width/2);

    auto x = back_cut_sipm->length/2 + back_cut_sipm->pos;
    auto z = (external->width - back_cut_sipm->width)/2;

    auto backPlateSub1 = new G4SubtractionSolid("solidBPC1",boxBackPlateCover, bpcSiPMCut, nullptr, {x,0,z});
    auto backPlateSub2 = new G4SubtractionSolid("solidBPC2",backPlateSub1, bpcSiPMCut, nullptr, {x,0,-z});
    auto backPlateSub3 = new G4SubtractionSolid("solidBPC3",backPlateSub2, bpcSiPMCut, nullptr, {-x,0,z});
    auto backPlateSub4 = new G4SubtractionSolid("solidBPC4",backPlateSub3, bpcSiPMCut, nullptr, {-x,0,-z});

    return new G4LogicalVolume(backPlateSub4, material, name);
}


G4VPhysicalVolume* BackPlate::PhysicalConstruct(const G4String & name, const G4ThreeVector &translation, G4RotationMatrix *pRot){
    return new G4PVPlacement(pRot, translation, logical_volume, name, mother_volume, false, 0, true);
}


} // carapuca::back_plate
