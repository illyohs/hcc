#pragma once

#include <filesystem>

namespace fs = std::filesystem;


namespace hcc
{
  class IRReader
  {
    private:
    public:
      IRReader(const fs::path path);
      void readTxt();
      void readBit();

  };
}
