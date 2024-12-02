#include "Intel8080.h"

void Intel8080::updateMachineState() {
    
}

// constructor
Intel8080::Intel8080(): numInstructions(256), numInstructionTypes(57), maxNumMachineStates(19) {//, memoryLimit(65536) {
    std::string tmpMachStateNames[] = {
        "M1T1", "M1T2", "M1T3", "M1T4", "M1T5",
        "M2T1", "M2T2", "M2T3",
        "M3T1", "M3T2", "M3T3",
        "M4T1", "M4T2", "M4T3",
        "M5T1", "M5T2", "M5T3", "M5T4", "M5T5"
    };

    for (int i = 0; i < maxNumMachineStates; i++)
        machineStateNames[i] = tmpMachStateNames[i];

    std::string tmpInstNames[] = {
    //   x0           x1              x2           x3           x4           x5           x6            x7           x8           x9           xA           xB           xC           xD           xE            xF
        "NOP",       "LXI B, d16",   "STAX B",    "INX B",     "INR B",     "DCR B",     "MVI B, d8",  "RLC",       "*NOP",      "DAD B",     "LDAX B",    "DCX B",     "INR C",     "DCR C",     "MVI C, d8",  "RRC",       // x0
        "*NOP",      "LXI D, d16",   "STAX D",    "INX D",     "INR D",     "DCR D",     "MVI D, d8",  "RAL",       "*NOP",      "DAD D",     "LDAX D",    "DCX D",     "INR E",     "DCR E",     "MVI E, d8",  "RAR",       // x1
        "*NOP",      "LXI H, d16",   "SHLD a16",  "INX H",     "INR H",     "DCR H",     "MVI H, d8",  "DAA",       "*NOP",      "DAD H",     "LHLD a16",  "DCX H",     "INR L",     "DCR L",     "MVI L, d8",  "CMA",       // x2
        "*NOP",      "LXI SP, d16",  "STA a16",   "INX SP",    "INR M",     "DCR M",     "MVI M, d8",  "STC",       "*NOP",      "DAD SP",    "LDA a16",   "DCX SP",    "INR A",     "DCR A",     "MVI A, d8",  "CMC",       // x3
        "MOV B, B",  "MOV B, C",     "MOV B, D",  "MOV B, E",  "MOV B, H",  "MOV B, L",  "MOV B, M",   "MOV B, A",  "MOV C, B",  "MOV C, C",  "MOV C, D",  "MOV C, E",  "MOV C, H",  "MOV C, L",  "MOV C, M",   "MOV C, A",  // x4
        "MOV D, B",  "MOV D, C",     "MOV D, D",  "MOV D, E",  "MOV D, H",  "MOV D, L",  "MOV D, M",   "MOV D, A",  "MOV E, B",  "MOV E, C",  "MOV E, D",  "MOV E, E",  "MOV E, H",  "MOV E, L",  "MOV E, M",   "MOV E, A",  // x5
        "MOV H, B",  "MOV H, C",     "MOV H, D",  "MOV H, E",  "MOV H, H",  "MOV H, L",  "MOV H, M",   "MOV H, A",  "MOV L, B",  "MOV L, C",  "MOV L, D",  "MOV L, E",  "MOV L, H",  "MOV L, L",  "MOV L, M",   "MOV L, A",  // x6
        "MOV M, B",  "MOV M, C",     "MOV M, D",  "MOV M, E",  "MOV M, H",  "MOV M, L",  "HLT",        "MOV M, A",  "MOV A, B",  "MOV A, C",  "MOV A, D",  "MOV A, E",  "MOV A, H",  "MOV A, L",  "MOV A, M",   "MOV A, A",  // x7
        "ADD B",     "ADD C",        "ADD D",     "ADD E",     "ADD H",     "ADD L",     "ADD M",      "ADD A",     "ADC B",     "ADC C",     "ADC D",     "ADC E",     "ADC H",     "ADC L",      "ADC M",     "ADC A",     // x8
        "SUB B",     "SUB C",        "SUB D",     "SUB E",     "SUB H",     "SUB L",     "SUB M",      "SUB A",     "SBB B",     "SBB C",     "SBB D",     "SBB E",     "SBB H",     "SBB L",      "SBB M",     "SBB A",     // x9
        "ANA B",     "ANA C",        "ANA D",     "ANA E",     "ANA H",     "ANA L",     "ANA M",      "ANA A",     "XRA B",     "XRA C",     "XRA D",     "XRA E",     "XRA H",     "XRA L",      "XRA M",     "XRA A",     // xA
        "ORA B",     "ORA C",        "ORA D",     "ORA E",     "ORA H",     "ORA L",     "ORA M",      "ORA A",     "CMP B",     "CMP C",     "CMP D",     "CMP E",     "CMP H",     "CMP L",      "CMP M",     "CMP A",     // xB
        "RNZ",       "POP B",        "JNZ a16",   "JMP a16",   "CNZ a16",   "PUSH B",    "ADI d8",     "RST 0",     "RZ",        "RET",       "JZ a16",    "*JMP a16",  "CZ a16",    "CALL a16",   "ACI d8",    "RST 1",     // xC
        "RNC",       "POP D",        "JNC a16",   "OUT d8",    "CNC a16",   "PUSH D",    "SUI d8",     "RST 2",     "RC",        "*RET",      "JC a16",    "IN d8",     "CC a16",    "*CALL a16",  "SBI d8",    "RST 3",     // xD
        "RPO",       "POP H",        "JPO a16",   "XTHL",      "CPO a16",   "PUSH H",    "ANI d8",     "RST 4",     "RPE",       "PCHL",      "JPE a16",   "XCHG",      "CPE a16",   "*CALL a16",  "XRI d8",    "RST 5",     // xE
        "RP",        "POP PSW",      "JP a16",    "DI",        "CP a16",    "PUSH PSW",  "ORI d8",     "RST 6",     "RM",        "SPHL",      "JM a16",    "EI",        "CM a16",    "*CALL a16",  "CPI d8",    "RST 7"      // xF
    };

    for (int i = 0; i < numInstructions; i++)
        instructionNames[i] = tmpInstNames[i];

    // these don't get associated by instruction number, but by number in which they appear here
    // for example, DAD should be at 0x09, but it is at 0x08 since NOP is repeated just before it
    // this was probably why I made the instructions enums as consecutive numbers from 1 up
    std::string tmpInstTypeNames[] = {
        "NOP", "LXI", "STAX", "INX", "INR", "DCR", "MVI", "RLC", "DAD", "LDAX", "DCX", "RRC", "RAL", "RAR",
        "SHLD", "DAA", "LHLD", "CMA", "STA", "STC", "LDA", "CMC",
        "MOV", "HLT", "ADD", "ADC", "SUB", "SBB", "ANA", "XRA", "ORA", "CMP",
        "RETcond", "POP", "JMPcond", "JMP", "CALLcond", "PUSH", "ADI", "RST", "RET", "CALL", "ACI",
        "OUT", "SUI", "IN", "SBI", "XTHL", "ANI", "PCHL", "XCHG", "XRI", "DI", "ORI", "SPHL", "EI", "CPI"
    };

    for (int i = 0; i < numInstructionTypes; i++)
        instructionTypeNames[i] = tmpInstTypeNames[i];

    InstructionMasks instrMasks[] = {nop_mask, lxi_mask, stax_mask, inx_mask, inr_mask, dcr_mask, mvi_mask, rlc_mask, dad_mask, ldax_mask, dcx_mask, rrc_mask, ral_mask, rar_mask, shld_mask, daa_mask, lhld_mask, cma_mask, sta_mask, stc_mask, lda_mask, cmc_mask, mov_mask, hlt_mask, add_mask, adc_mask, sub_mask, sbb_mask, ana_mask, xra_mask, ora_mask, cmp_mask, retcond_mask, pop_mask, jmpcond_mask, jmp_mask, callcond_mask, push_mask, adi_mask, rst_mask, ret_mask, call_mask, aci_mask, out_mask, sui_mask, in_mask, sbi_mask, xthl_mask, ani_mask, pchl_mask, xchg_mask, xri_mask, di_mask, ori_mask, sphl_mask, ei_mask, cpi_mask};
    
    InstructionBases instrBases[] = {nop, lxi, stax, inx, inr, dcr, mvi, rlc, dad, ldax, dcx, rrc, ral, rar, shld, daa, lhld, cma, sta, stc, lda, cmc, mov, hlt, add, adc, sub, sbb, ana, xra, ora, cmp, retcond, pop, jmpcond, jmp, callcond, push, adi, rst, ret, call, aci, out, sui, in, sbi, xthl, ani, pchl, xchg, xri, di, ori, sphl, ei, cpi};
    InstructionTypes instrTypes[] = {_nop, _lxi, _stax, _inx, _inr, _dcr, _mvi, _rlc, _dad, _ldax, _dcx, _rrc, _ral, _rar, _shld, _daa, _lhld, _cma, _sta, _stc, _lda, _cmc, _mov, _hlt, _add, _adc, _sub, _sbb, _ana, _xra, _ora, _cmp, _retcond, _pop, _jmpcond, _jmp, _callcond, _push, _adi, _rst, _ret, _call, _aci, _out, _sui, _in, _sbi, _xthl, _ani, _pchl, _xchg, _xri, _di, _ori, _sphl, _ei, _cpi};

    // make instrs contain the base instruction form again, that's (one reason) why it's not working
    // also check if the string outputs align with this, or other components
    bool match = false;
    for (int i = 0; i < numInstructions; i++) {
        match = false;
        // this is a problem, can't use j, need to index the Instructions enum using j, since they have different values
        for (int j = 0; j < numInstructionTypes && !match; j++) {
            if ((i & instrMasks[j]) == instrBases[j]) {
                instructionType[i] = instrTypes[j];
                match = true;
            }
        }
    }

    std::cout << "i\thex\tinstr type\tinstr name" << std::endl;
    for (int i = 0; i < numInstructions; i++) {
        // std::cout << i << ":\t" << instructionTypeNames[instructionType[i]] << std::endl;
        // std::cout << i << ":\t" << std::hex << std::setw(2) << std::setfill('0') << i << "\t" << std::dec << instructionType[i] << "\t\t" << instructionTypeNames[instructionType[i]] << std::endl;
        std::cout << instructionTypeNames[instructionType[i]] << ", ";
    }
    std::cout << std::endl;

    // LINKEDLIST mt53335 = new LinkedList({m1t1, m1t2, m1t3, m1t4, m1t5, m2t1, m2t2, m2t3, m3t1, m3t2, m3t3, m4t1, m4t2, m4t3, m5t1, m5t2, m5t3, m5t4, m5t5});
    // LINKEDLIST mt

    // nextMachineState[0x00] = ;

}
