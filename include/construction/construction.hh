#pragma once

#include <iostream>
#include <stdlib.h>

#include "../3rdparty/cadmesh/CADMesh.hh"

#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalBorderSurface.hh"

#include "materials/materials.hh"
#include "json_file/json_file.hh"
#include "sensitive/sensitive.hh"

#include "logger/logmanager.hh"
#include "logger/logger.hh"


class Construction : public G4VUserDetectorConstruction{

public:
    explicit Construction(G4String const& carapuca_filename);
    ~Construction() override;
    G4VPhysicalVolume* Construct() override;

private:
    std::shared_ptr<spdlog::logger> logmanager;
    G4VPhysicalVolume* mother_volume;
    G4String carapuca_filename;

    G4VPhysicalVolume* BuildWorldVolume();
    G4VPhysicalVolume* BuildDetector();
    G4OpticalSurface* BuildVikuitiAirSurface(G4VPhysicalVolume* vikuiti_vol, G4VPhysicalVolume* air_vol);
};
