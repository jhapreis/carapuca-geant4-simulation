#include "hits/hits.hh"

Hits::Hits(G4Step *step):
    track_id(step->GetTrack()->GetTrackID()),
    particle_id(step->GetTrack()->GetParticleDefinition()->GetParticleName()),
    energy_deposited(step->GetTotalEnergyDeposit()),
    position(step->GetPreStepPoint()->GetPosition()),
    direction(step->GetPreStepPoint()->GetMomentumDirection())
{

}

Hits::~Hits() = default;

void Hits::Print(){
    // This implementation NEEDS Single-Thread mode
    // TODO: Change to save on ROOT file
    G4cout << "   TrackID: "   << track_id << G4endl;
    G4cout << "   PID: "       << particle_id << G4endl;
    G4cout << "   EnergyDep: " << std::setw(7) << G4BestUnit( energy_deposited, "Energy" ) << G4endl;
    G4cout << "   Position: "  << std::setw(7) << G4BestUnit( position, "Length" ) << G4endl;
    G4cout << "   Direction: " << std::setw(7) << direction << G4endl;
}
