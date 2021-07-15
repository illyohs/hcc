#pragma once

#include <cstddef>
#include <filesystem>
#include <iterator>

namespace fs = std::filesystem;

namespace hcc
{
  class FileScanner
  {
    private:
      const fs::path path;
      const char* buffer; //QUESTION: implent a bytebuffer for this instead of a raw pointer buffer? - Anthony Anderson 5/7/2021
      std::size_t bufferSize;

    public:
      const char current;
      const char previous;
      const char next;
    public:
      FileScanner(const fs::path path);
      ~FileScanner();
      char advance();
  };
}
