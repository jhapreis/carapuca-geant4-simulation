#include "construction/construction.hh"

G4OpticalSurface* BuildAirWaterSurface(G4VPhysicalVolume* air_volume, G4VPhysicalVolume* water_volume){

    auto surface = new G4OpticalSurface("surface_air_water");
    surface->SetModel(unified);
    surface->SetType(dielectric_dielectric);
    surface->SetFinish(polished);

    auto properties = new G4MaterialPropertiesTable();
    surface->SetMaterialPropertiesTable(properties);

    new G4LogicalBorderSurface("logical_surface_air_water", air_volume, water_volume, surface);
    new G4LogicalBorderSurface("logical_surface_water_air", water_volume, air_volume, surface);

    std::vector<G4double> energies     = {1.65*CLHEP::eV, 3.10*CLHEP::eV};
    std::vector<G4double> reflectivity = {1.            , 1.}; // 1 - ABS

    properties->AddProperty("REFLECTIVITY", energies, reflectivity);

    return surface;
}


G4OpticalSurface* Construction::BuildVikuitiAirSurface(G4VPhysicalVolume *vikuiti_vol, G4VPhysicalVolume *air_vol) {

    auto surface = new G4OpticalSurface("surface_vikuiti_air");
    surface->SetModel(unified);
    surface->SetType(dielectric_metal); // glass = mirror
    surface->SetFinish(ground); // superficie rugosa = ground
    surface->SetSigmaAlpha(0.*CLHEP::deg);

    auto properties = new G4MaterialPropertiesTable();
    surface->SetMaterialPropertiesTable(properties);

    new G4LogicalBorderSurface("logical_surface_vikuiti_air", vikuiti_vol, air_vol, surface);
    new G4LogicalBorderSurface("logical_surface_air_vikuiti", air_vol    , vikuiti_vol, surface);

    std::vector<G4double> energies     = {1.65*CLHEP::eV, 3.10*CLHEP::eV};
    std::vector<G4double> reflectivity = {1.            , 1.}; // 1 - ABSORPTION

    properties->AddProperty("REFLECTIVITY", energies, reflectivity);

    return surface;
}
