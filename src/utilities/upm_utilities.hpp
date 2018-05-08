#pragma once

#include <string>
#include <vector>

#include "upm_utilities.h"

namespace upm
{
  class UpmStringParser
  {
  public:
    static std::vector<std::string>  parse(const std::string &initStr)
    {
      int numTokens = 0;
      char **initStrTokens = upm_parse_init_str(initStr.c_str(), ",", &numTokens);
      std::vector<std::string> tokens(initStrTokens, initStrTokens + numTokens);
      upm_delete_parsed_str(initStrTokens, numTokens);

      return tokens;
    }
  };
}
