#pragma once

#include "construction/construction.hh"

namespace carapuca::front_plate{

    struct External
    {
        double length;
        double width;
        double height;
    };

    struct WindowCutSipm
    {
        double length;
        double width;
        double pos;
    };

    struct WindowCutWindow
    {
        double length;
        double width;
    };

    struct WindowCutFilter
    {
        double length;
        double width;
        double height;
    };

    struct Filter    
    {
        double pos;
    };


// External structure
class FrontPlate {

    public:
        FrontPlate(
            G4LogicalVolume* mother_volume,
            G4Material* material,
            External const* external,
            Filter const* filter,
            WindowCutFilter const* window_cut_filter, 
            WindowCutSipm const* window_cut_sipm, 
            WindowCutWindow const* window_cut_window,
            const G4ThreeVector &translation, 
            G4RotationMatrix *pRot
        );
        ~FrontPlate();

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
        const Filter* filter;
        const WindowCutFilter* window_cut_filter;
        const WindowCutSipm* window_cut_sipm;
        const WindowCutWindow* window_cut_window;
};

} // carapuca::front_plate
