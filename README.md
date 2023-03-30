# C-Arapuca-Open

Repositório para a implementação das simulações do C-Arapuca com o Geant4.

</br>

## Compilação do projeto

Para compilar, execute:

```bash
mkdir build

cd build

cmake ..

make -j4
```

A execução se dá pelo arquivo `ArapucaSim` com uma macro:

```bash
./ArapucaSim -i photons_2.mac
```

Instalação do `spdlog`: vide informações completas [aqui](https://github.com/gabime/spdlog).

```bash
sudo apt install libspdlog-dev
```
