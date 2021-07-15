#pragma once

#include <string>
#include <vector>

#include "../token/Token.hh"

namespace hcc
{

  // QUESTION: Should there be nodes for all the opcodes: Anthony Anderson 7/15/2021
  struct Node;
  struct FileNode;
  struct LableNode;
  struct FunctionNode;
  struct OpNode;
  struct DirectiveNode;

  struct LiteralNode;
  struct TypeLiteralNode;
  struct StringLiteral;

  struct Node{};
  struct LiteralNode{};

  struct FileNode : Node
  {
    std::string name;
    std::vector<DirectiveNode> directives;
    std::vector<Node> nodes;
  };

  struct LabelNode : Node
  {
    Token token;
    std::vector<OpCode> opcodes;
  };

  struct FunctionNode : Node
  {
    hcc::Token token;
    std::string name;
    std::vector<std::string> args;
  };

  struct TypeLiteralNode : LiteralNode
  {
    hcc::Token literal;
  };

  struct StringLiteral : LiteralNode
  {
    hcc::Token literal;
  };

  struct DirectiveNode : Node
  {
    Token direvice;
    std::vector<LiteralNode> args;
  };

  struct OpNode : Node
  {
    hcc::Token token;
    hcc::OpCode OpCode;
    std::vector<LiteralNode> args;
  };
}
