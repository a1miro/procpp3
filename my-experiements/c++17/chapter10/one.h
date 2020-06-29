#pragma once
#include <memory>
#include <cinttypes>

class one {

  public:
    one() = default;
    virtual ~one() = default;
    uint64_t id() const;

  private:
    struct data;
    std::unique_ptr<data> data_;
};
