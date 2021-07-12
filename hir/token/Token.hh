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

  //TODO: remove lable function and directive
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
    LABLE,
    CMP_EQ,
    CMP_LT,
    CMP_GT,
    JMP,
    JMP_NQ,
    JMP_EQ,
    JMP_ERR,
    FUNC,
    DEREF,
    PTRTO,
    CALL,
    STORE,
    WRITE,
  };


  struct OpCode
  {
    std::string   name;
    std::uint8_t  code;
    Instruction   instruction;
  };


  //TODO: Finish the opcode map
  const std::unordered_map<std::string, OpCode> OpCodes =
  {
    {"add", {"add", 0x01, ADD}},
    {"sub", {"sub", 0x02, SUB}},
    {"div", {"div", 0x03, DIV}},
    {"mul", {"mul", 0x04, MUL}},
    {"and", {"and", 0x05, AND}},
    {"or",  {"or",  0x06, OR}},
    {"xor", {"xor", 0x07, XOR}},

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


  class Posistion
  {
    int line, start, end, length;
  };

  class Token
  {
    public:
      std::string lexme;
      Posistion pos;
      Type type;
  };
}
