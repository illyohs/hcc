#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>

// TODO: redo how the tokenizer worked form the orginal implenation
namespace hcc
{
  class Token;
  class Posistion;

  enum Instruction
  {
    ADD,
    SUB,
    DIV,
    MUL,
    AND,
    OR,
    XOR,
    NOT,
    DATA,
    CMP_EQ,
    CMP_LT,
    CMP_GT,
    JMP,
    JMP_NQ,
    JMP_EQ,
    JMP_ERR,
    DEREF,
    PTRTO,
    CALL,
    STORE,
    WRITE,
    RETURN,
  };

  struct OpCode
  {
    std::string   name;
    std::uint8_t  code;
    Instruction   instruction;
  };

  const std::unordered_map<std::string, OpCode> OpCodes =
  {
    {"add",     {"add",     0x01, ADD}},
    {"sub",     {"sub",     0x02, SUB}},
    {"div",     {"div",     0x03, DIV}},
    {"mul",     {"mul",     0x04, MUL}},
    {"and",     {"and",     0x05, AND}},
    {"or",      {"or",      0x06, OR}},
    {"xor",     {"xor",     0x07, XOR}},
    {"not",     {"not",     0x08, NOT}},
    {"data",    {"data",    0x09, DATA}},
    {"cmp_eq",  {"cmp_eq",  0x0A, CMP_EQ}},
    {"cmp_lt",  {"cmp_lt",  0x0B, CMP_LT}},
    {"cmp_gt",  {"cmp_gt",  0x0C, CMP_GT}},
    {"jmp",     {"jmp",     0x0D, JMP}},
    {"jmp_nq",  {"jmp_nq",  0x0E, JMP_NQ}},
    {"jmp_eq",  {"jmp_eq",  0x0F, JMP_EQ}},
    {"jmp_err", {"jmp_err", 0x0F, JMP_ERR}},
    {"deref",   {"deref",   0x10, DEREF}},
    {"ptrto",   {"ptrto",   0x11, PTRTO}},
    {"call",    {"call",    0x12, CALL}},
    {"store",   {"store",   0x13, STORE}},
    {"write",   {"write",   0x14, WRITE}},
    {"return",  {"return",  0x15, RETURN}}
  };

  enum Type
  {
    NUMBER,
    INSTRUCTION,
    LITERTAL,
    SPECIAL,
    OPCODE,
    KEYWORD
  };


  struct Posistion
  {
    int line, start, end, length;

    Posistion(int line, int start, int end, int length): line(line), start(start), end(end), length(length){}
  };

  struct Token
  {
    std::string lexme;
    Posistion pos;
    Type type;

    Token(std::string lexme, Posistion pos, Type type): lexme(lexme), pos(pos), type(type){}
  };
}
