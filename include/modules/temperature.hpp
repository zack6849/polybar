#pragma once

#include <istream>

#include "config.hpp"
#include "modules/meta/timer_module.hpp"

POLYBAR_NS

namespace modules {
  enum class temp_state { NORMAL = 0, WARN };

  class temperature_module : public timer_module<temperature_module> {
   public:
    using timer_module::timer_module;

    void setup();
    bool update();
    string get_format() const;
    bool build(builder* builder, const string& tag) const;

   private:
    static constexpr auto TAG_LABEL = "<label>";
    static constexpr auto TAG_LABEL_WARN = "<label-warn>";
    static constexpr auto TAG_RAMP = "<ramp>";
    static constexpr auto FORMAT_WARN = "format-warn";

    map<temp_state, label_t> m_label;
    ramp_t m_ramp;

    string m_path;
    int m_zone = 0;
    int m_tempwarn = 0;
    int m_temp = 0;
    int m_perc = 0;
  };
}

POLYBAR_NS_END
