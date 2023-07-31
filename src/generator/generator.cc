#include "generator/generator.hh"

PrimaryGenerator::PrimaryGenerator() :
        G4VUserPrimaryGeneratorAction(),
        m_ParticleGun( new G4ParticleGun( G4Geantino::Definition() ) )
{

};

PrimaryGenerator::~PrimaryGenerator(){
    delete m_ParticleGun;
};

void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent){
    for (int i=0; i<5; i++){
        m_ParticleGun->GeneratePrimaryVertex(anEvent);
    }
};
