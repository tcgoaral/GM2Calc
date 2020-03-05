#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 1

#include "doctest.h"
#include "gm2_slha_io.hpp"
#include "gm2_config_options.hpp"

#include <sstream>

#define CHECK_CLOSE(a,b,eps)                            \
   do {                                                 \
      CHECK((a) == doctest::Approx(b).epsilon(eps));    \
   } while (0)


TEST_CASE("fill_config")
{
   gm2calc::Config_options config;

   char const * const slha_input = R"(
Block GM2CalcConfig
     0     9     # output format (0, 1, 2, 3, 4)
     1     9     # loop order (0, 1 or 2)
     2     0     # disable/enable tan(beta) resummation (0 or 1)
     3     1     # force output (0 or 1)
     4     1     # verbose output (0 or 1)
     5     1     # calculate uncertainty
)";

   std::istringstream stream(slha_input);

   gm2calc::GM2_slha_io slha;
   slha.read_from_stream(stream);
   slha.fill(config);

   CHECK(config.output_format == 9);
   CHECK(config.loop_order == 9);
   CHECK(config.tanb_resummation == false);
   CHECK(config.force_output == true);
   CHECK(config.verbose_output == true);
   CHECK(config.calculate_uncertainty == true);
}