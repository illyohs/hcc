#pragma once

#include <filesystem>

namespace fs = std::filesystem;

namespace hcc
{

  enum EngineMode
  {
    BIT,
    TEXT,
  };

  class IREngine
  {
    private:
    public:
      void write();
      void read(fs::path path, EngineMode mode);
  };
}
