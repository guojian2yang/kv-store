#pragma once

#include <string>

#include "mini_redis/config.hpp"

namespace mini_redis
{

  class KeyValueStore;

  class Rdb
  {
  public:
    Rdb() = default;
    explicit Rdb(const RdbOptions &opts) : opts_(opts) {}
    void setOptions(const RdbOptions &opts) { opts_ = opts; }

    bool save(const KeyValueStore &store, std::string &err) const;
    bool load(KeyValueStore &store, std::string &err) const;
    std::string path() const;

  private:
    RdbOptions opts_{};
  };

} // namespace mini_redis
