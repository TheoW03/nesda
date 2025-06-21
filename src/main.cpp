#include <iostream>
#include <RomUtil.h>
#include <Disasm.h>
#include <util.h>
#include <cli.h>

int main(int argc, char const *argv[])
{

    std::vector<std::string> args;

    for (int i = 1; i < argc; i++)
    {
        args.push_back(argv[i]);
    }
    auto p = parse_cmd(args);
    /* code */
    // std::cout << p.files << std::endl;

    // auto parsed_rom = load_rom(file_tobyte_vector("./games/Mario.nes"));
    // auto parsed_rom2 = load_rom(file_tobyte_vector("mario.nes"));
    // for (int i = 0; i < parsed_rom.prg_rom.size(); i++)
    // {
    //     if (parsed_rom.prg_rom[i] != parsed_rom2.prg_rom[i])
    //     {
    //         printf("error %x \n", (i + 0x8000));
    //     }
    // }
    init(load_rom(file_tobyte_vector(p.files)), p);
    // std::cout << byteToHex16(0x8000) << std::endl;
    // std::cout << byteToHex(10) << std::endl;
    return 0;
}
