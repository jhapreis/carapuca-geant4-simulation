#pragma once

#include <iostream>
#include <stdlib.h>

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

#include "materials/materials.hh"
#include "json_file/json_file.hh"

#include "carapuca/front_plate.hh"
#include "carapuca/carapuca.hh"

#include "logger/logmanager.hh"
#include "logger/logger.hh"

class Construction : public G4VUserDetectorConstruction{
    public:
        Construction();
        ~Construction();
        virtual G4VPhysicalVolume* Construct();

    private:

        G4VPhysicalVolume* GenerateWorld();
        G4VPhysicalVolume* GenerateCArapuca();
        G4VPhysicalVolume* GenerateTestVolume();

        G4VPhysicalVolume* BuildFrontPlate();
        G4VPhysicalVolume* BuildBackPlate();

        G4VPhysicalVolume* physical_world;
        G4VPhysicalVolume* physical_carapuca;

        std::shared_ptr<spdlog::logger> logmanager;
};
