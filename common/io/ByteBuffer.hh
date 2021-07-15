#pragma once

#include <cstddef>
#include <cstdint>

namespace hcc {
  typedef std::uint8_t BYTE;
  //TODO: Finish work on byte buffer for the file scanner. - Anthony Anderson 7/15/2021
  class ByteBuffer
  {
    private:
      std::size_t size;
    public:
      ByteBuffer();
      ByteBuffer(std::size_t size);

  };
}
