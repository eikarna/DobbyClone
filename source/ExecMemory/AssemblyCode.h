#ifndef ASSEMBLY_CODE_H
#define ASSEMBLY_CODE_H

#include "stdcxx/LiteObject.h"
#include "core/modules/assembler/assembler.h"

using namespace zz;

class CodeBuffer;

class AssemblyCode : public LiteObject {

public:
  void initWithAddressRange(addr_t address, int size);

  void reInitWithAddressRange(addr_t address, int size);

  // realize the buffer address to runtime code, and create a corresponding Code Object
  static AssemblyCode *FinalizeFromAddress(addr_t address, int size);

  // realize the buffer address to runtime code, and create a corresponding Code Object
  static AssemblyCode *FinalizeFromTurboAssember(AssemblerBase *assember);

  inline addr_t raw_instruction_start() {
    return address_;
  };

  inline int raw_instruction_size() {
    return size_;
  };

private:
  addr_t address_;
  int size_;
};

#endif