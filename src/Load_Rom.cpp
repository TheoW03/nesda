#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <optional>
#include <cstdint>
#include <RomUtil.h>

#define PRG_ROM_SIZE 16384
#define CHR_ROM_SIZE 8192

std::vector<uint8_t> file_tobyte_vector(std::optional<std::string> file_name)
{
    if (!file_name.has_value())
    {
        std::cout << "TetroidDisasm:  requires file" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<uint8_t> instructions;
    std::ifstream infile(file_name.value(), std::ios::binary); // Open the file for reading
    if (!infile)
    {
        std::cout << "TetroidDisasm: file " << file_name.value() << " doesnt exist" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    while (infile)
    {
        uint8_t a = (uint8_t)infile.get();
        instructions.push_back(a);
    }

    return instructions;
}
NESRom load_rom(std::vector<uint8_t> instructions)
{

    NESHeader nes_header;
    NESRom nes_rom;
    memcpy(&nes_header, instructions.data(), sizeof(NESHeader));
    if (                                 //
        (nes_header.ident[0] != 'N'      //
         && nes_header.ident[1] != 'E'   //
         && nes_header.ident[2] != 'S'   //
         && nes_header.ident[3] != 0x1a) // all man style should be the default in the VS code formatiro
        || nes_header.flag7.inesverif == 0xc)
    {
        std::cout << "nesda: this isnt a iNES version 1.0 header" << std::endl;
        exit(EXIT_FAILURE);
    }
    nes_header.flag6.val = instructions[6];
    nes_header.flag7.val = instructions[7];
    nes_header.flag8 = instructions[8];
    nes_header.flag9.val = instructions[9];

    // this sets the hader
    nes_rom.header = nes_header;
    uint16_t prg_start = 16 + (512 * nes_header.flag6.trainer);

    // this sets the mapper
    size_t prg_rom = nes_header.prg_size * PRG_ROM_SIZE;
    size_t chr_rom = nes_header.chr_size * CHR_ROM_SIZE;
    for (size_t i = prg_start; i < prg_rom + prg_start; i++)
    {
        nes_rom.prg_rom.push_back(instructions[i]);
    }
    size_t chr_start = prg_start + prg_rom;
    size_t chr_size = prg_start + prg_rom + chr_rom;
    for (size_t i = chr_start; i < chr_size; i++)
    {
        nes_rom.chr_rom.push_back(instructions[i]);
    }

    return nes_rom;
}