#include <cassert>
#include "CLHEP/Units/SystemOfUnits.h"
#include "G4String.hh"
#include "G4Types.hh"
#include "materials/materials.hh"


namespace Materials{

Properties::Properties(const char * filename)
:
filename(filename)
{
    rapidcsv::Document datafile(filename);
}


void Properties::ReadDataFromCSV(const char * energy_col, const char * property_col, G4double energy_unit, G4double property_unit){
    
    // TODO: Modificar a forma como passa as unidades das colunas. Trocar para ler uma por vez? É necessário guardar o objeto Document.

    rapidcsv::Document datafile(filename);

    energies = datafile.GetColumn<double>(*energy_col);
    property = datafile.GetColumn<double>(*property_col);

    for (int i=0; i<energies.size(); i++){
        energies[i] = energies[i]*energy_unit;
        property[i] = property[i]*property_unit;
    }

    return;
}

} // Materials
