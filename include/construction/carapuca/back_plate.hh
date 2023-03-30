#pragma once

#include "construction/construction.hh"


namespace carapuca::back_plate{

    struct External
    {
        double length;
        double width;
        double height;
    };

    struct BackCutSipm
    {
        double length;
        double width;
        double pos;
    };


class BackPlate {

    public:
        BackPlate(
            G4LogicalVolume* mother_volume,
            G4Material* material,
            External const* external,
            BackCutSipm const* back_cut_sipm, 
            const G4ThreeVector &translation, 
            G4RotationMatrix *pRot
        );
        ~BackPlate();

        G4LogicalVolume* GetLogicalVolume();
        G4VPhysicalVolume* GetPhysicalVolume();

    private:
        G4LogicalVolume* LogicalConstruct(const G4String & name);
        G4VPhysicalVolume* PhysicalConstruct(const G4String & name, const G4ThreeVector &translation, G4RotationMatrix *pRot);
        
        G4LogicalVolume* mother_volume;

        G4Material* material;

        G4LogicalVolume* logical_volume;
        G4VPhysicalVolume* physical_volume;

        const External* external;
        const BackCutSipm* back_cut_sipm;
};

} // carapuca::back_plate
