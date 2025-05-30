#include <instruction.h>
#include <memory>
#include <vector>

// std::shared_ptr<instr> (AddressMode addressMode, DisAsmState &disasm);

std::shared_ptr<instr> disassemble_MultiByteInstr(AddressMode addressMode, DisAsmState &disasm, std::string name);
std::shared_ptr<instr> disassemble_Branch(AddressMode addressMode, DisAsmState &disasm, std::string name);
std::shared_ptr<instr> disassemble_Onebyte(AddressMode addressMode, DisAsmState &disasm, std::string name);
std::shared_ptr<instr> disassemble_RtsRti(AddressMode addressMode, DisAsmState &disasm, std::string name);
std::shared_ptr<instr> disassemble_brk(AddressMode addressMode, DisAsmState &disasm, std::string name);

std::shared_ptr<instr> JSR(AddressMode addressMode, DisAsmState &disasm, std::string name);
std::shared_ptr<instr> JMP(AddressMode addressMode, DisAsmState &disasm, std::string name);

// std::shared_ptr<instr> LDA(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> LDY(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> LDX(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> RTI(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> BEQ(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> BNE(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> BCC(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> BCS(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> BPL(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> BMI(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> CLC(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> SEC(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> CLD(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> SED(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> CLI(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> SEI(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> CLI(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> CLV(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> INC(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> INX(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> INY(AddressMode addressMode, DisAsmState &disasm);

// std::shared_ptr<instr> BVC(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> BVS(AddressMode addressMode, DisAsmState &disasm);
// std::shared_ptr<instr> RTS(AddressMode addressMode, DisAsmState &disasm);
