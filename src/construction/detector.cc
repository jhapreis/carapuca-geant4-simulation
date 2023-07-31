#include "construction/construction.hh"
#include "sensitive/sensitive.hh"

G4VPhysicalVolume* Construction::BuildDetector() {
    auto silicon = Materials::Silicon();

    auto dimension = 0.5*CLHEP::m;
    auto thickness = 1.*CLHEP::mm;
    auto distance  = 9*CLHEP::cm;

    auto sensor = new G4Box("sensor_box", dimension/2, thickness/2, dimension/2);
    auto logical_sensor = new G4LogicalVolume(sensor, silicon, "logical_sensor_box");
    auto physical_sensor = new G4PVPlacement(0, {0., -1*distance, 0.}, logical_sensor, "sensitive_detector", mother_volume->GetLogicalVolume(), false, 0);

    auto detector = new SensorDetector("PhotonCounter");

    logical_sensor->SetVisAttributes(new G4VisAttributes(G4Color::Red()));
    logical_sensor->SetSensitiveDetector(detector);

    return physical_sensor;
}
