#include "materials/materials.hh"
#include "CLHEP/Random/RanecuEngine.h"
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4MaterialPropertiesTable.hh"

namespace Materials{

G4Material* EJ286(){

    using namespace CLHEP;

    // Polystyrene (C8H8)n
    auto elC = G4NistManager::Instance()->FindOrBuildElement("C");
    auto elH = G4NistManager::Instance()->FindOrBuildElement("H");

    auto ej286 = new G4Material("EJ286", 1.023*g/cm3, 2);
    ej286->AddElement(elC, 8);
    ej286->AddElement(elH, 8);

    auto properties = new G4MaterialPropertiesTable();

    auto rindex    = Properties("data/materials/EJ286/rindex.csv");
    auto abslength = Properties("data/materials/EJ286/abslength.csv");
    auto emission  = Properties("data/materials/EJ286/emission.csv");

    rindex.ReadDataFromCSV("energy_eV", "rindex");
    abslength.ReadDataFromCSV("energy_eV", "length_m", CLHEP::eV, CLHEP::m);
    emission.ReadDataFromCSV("energy_eV", "emission");

    properties->AddProperty("RINDEX", rindex.energies, rindex.property);
    properties->AddProperty("ABSLENGTH", abslength.energies, abslength.property);
    properties->AddProperty("WLSCOMPONENT", emission.energies, emission.property);

    properties->AddConstProperty("WLSTIMECONSTANT", 1.2*ns);

    ej286->SetMaterialPropertiesTable(properties);

    return ej286;
}

} //Materials
