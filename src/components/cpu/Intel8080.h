#ifndef INTEL8080_H
#define INTEL8080_H

#define BYTEMASK 255

#include <iostream>
#include <iomanip>
#include <string>

#include "CPU.h"
#include "../../utils/LinkedList.h"


// define a namespace for Intel8080?
// otherwise would have many Instruction types, MachineStates, etc.

// fix the problem of masks being the same as each others, e.g. multiple masks being 0xFF in an enum


// set up an array of length 256 which contains the instruction base for each instructions
// i.e. loop through array, if index & instruction == instruction, then set that index in the array to instruction
typedef enum InstructionBases {
    nop = 0x00,
    lxi = 0x01,
    stax = 0x02,
    inx = 0x03,
    inr = 0x04,
    dcr = 0x05,
    mvi = 0x06,
    rlc = 0x07,
    dad = 0x09,
    ldax = 0x0A,
    dcx = 0x0B,
    rrc = 0x0F,
    ral = 0x17,
    rar = 0x1F,
    shld = 0x22,
    daa = 0x27,
    lhld = 0x2A,
    cma = 0x2F,
    sta = 0x32,
    stc = 0x37,
    lda = 0x3A,
    cmc = 0x3F,
    mov = 0x40,
    hlt = 0x76,
    add = 0x80,
    adc = 0x88,
    sub = 0x90,
    sbb = 0x98,
    ana = 0xA0,
    xra = 0xA8,
    ora = 0xB0,
    cmp = 0xB8,
    retcond = 0xC0,
    pop = 0xC1,
    jmpcond = 0xC2,
    jmp = 0xC3,
    callcond = 0xC4,
    push = 0xC5,
    adi = 0xC6,
    rst = 0xC7,
    ret = 0xC9,
    call = 0xCD,
    aci = 0xCE,
    out = 0xD3,
    sui = 0xD6,
    in = 0xDB,
    sbi = 0xDE,
    xthl = 0xE3,
    ani = 0xE6,
    pchl = 0xE9,
    xchg = 0xEB,
    xri = 0xEE,
    di = 0xF3,
    ori = 0xF6,
    sphl = 0xF9,
    ei = 0xFB,
    cpi = 0xFE,
} Instructions;

typedef enum InstructionTypes {
    _nop,
    _lxi,
    _stax,
    _inx,
    _inr,
    _dcr,
    _mvi,
    _rlc,
    _dad,
    _ldax,
    _dcx,
    _rrc,
    _ral,
    _rar,
    _shld,
    _daa,
    _lhld,
    _cma,
    _sta,
    _stc,
    _lda,
    _cmc,
    _mov,
    _hlt,
    _add,
    _adc,
    _sub,
    _sbb,
    _ana,
    _xra,
    _ora,
    _cmp,
    _retcond,
    _pop,
    _jmpcond,
    _jmp,
    _callcond,
    _push,
    _adi,
    _rst,
    _ret,
    _call,
    _aci,
    _out,
    _sui,
    _in,
    _sbi,
    _xthl,
    _ani,
    _pchl,
    _xchg,
    _xri,
    _di,
    _ori,
    _sphl,
    _ei,
    _cpi,
} InstructionTypes;

// 1s in the static fields, 0s in the variable fields
typedef enum InstructionMasks {
    nop_mask = BYTEMASK,
    lxi_mask = 0b11001111,
    stax_mask = 0b11001111,
    inx_mask = 0b11001111,
    inr_mask = 0b11000111,
    dcr_mask = 0b11000111,
    mvi_mask = 0b11000111,
    rlc_mask = BYTEMASK,
    dad_mask = 0b11001111,
    ldax_mask = 0b11001111,
    dcx_mask = 0b11001111,
    rrc_mask = BYTEMASK,
    ral_mask = BYTEMASK,
    rar_mask = BYTEMASK,
    shld_mask = BYTEMASK,
    daa_mask = BYTEMASK,
    lhld_mask = BYTEMASK,
    cma_mask = BYTEMASK,
    sta_mask = BYTEMASK,
    stc_mask = BYTEMASK,
    lda_mask = BYTEMASK,
    cmc_mask = BYTEMASK,
    mov_mask = 0b11000000,
    hlt_mask = BYTEMASK,
    add_mask = 0b11111000,
    adc_mask = 0b11111000,
    sub_mask = 0b11111000,
    sbb_mask = 0b11111000,
    ana_mask = 0b11111000,
    xra_mask = 0b11111000,
    ora_mask = 0b11111000,
    cmp_mask = 0b11111000,
    retcond_mask = 0b11000111,
    pop_mask = 0b11001111,
    jmpcond_mask = 0b11000111,
    jmp_mask = BYTEMASK,
    callcond_mask = 0b11000111,
    push_mask = 0b11001111,
    adi_mask = BYTEMASK,
    rst_mask = 0b11000111,
    ret_mask = BYTEMASK,
    call_mask = BYTEMASK,
    aci_mask = BYTEMASK,
    out_mask = BYTEMASK,
    sui_mask = BYTEMASK,
    in_mask = BYTEMASK,
    sbi_mask = BYTEMASK,
    xthl_mask = BYTEMASK,
    ani_mask = BYTEMASK,
    pchl_mask = BYTEMASK,
    xchg_mask = BYTEMASK,
    xri_mask = BYTEMASK,
    di_mask = BYTEMASK,
    ori_mask = BYTEMASK,
    sphl_mask = BYTEMASK,
    ei_mask = BYTEMASK,
    cpi_mask = BYTEMASK,
} InstructionMasks;

typedef enum FlagBits {
    CY = 0,
    P = 2,
    AC = 4,
    Z = 6,
    S = 7
} FlagBits;

typedef enum MachineStates {
    m1t1,
    m1t2,
    m1t3,
    m1t4,
    m1t5,
    m2t1,
    m2t2,
    m2t3,
    m3t1,
    m3t2,
    m3t3,
    m4t1,
    m4t2,
    m4t3,
    m5t1,
    m5t2,
    m5t3,
    m5t4,
    m5t5
} MachineStates;

typedef enum Conditions {
    notzero,
    zero,
    nocarry,
    carry,
    parityodd,
    parityeven,
    plus,
    minus,
} Conditions;

class Intel8080 : public CPU {
private:
    // int machineState;
    // int machineCycle;
    const int numInstructions; // 256
    const int numInstructionTypes; // 57
    const int maxNumMachineStates; // 19
    // const int maxNumMachineCycles; // 5
    // const int numFlags; // 5?
    // const int numRegisters; // ?
    // const int memoryLimit; // 65536

public:
    std::string machineStateNames[19];
    std::string instructionNames[256];
    std::string instructionTypeNames[57];
    LINKEDLIST nextMachineState[256];
    InstructionBases instructionBase[256];
    InstructionTypes instructionType[256];

    // constructors
    Intel8080();
    // Intel8080(memory, ...);

    void updateMachineState();
};

#endif
