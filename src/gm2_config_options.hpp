// ====================================================================
// This file is part of GM2Calc.
//
// GM2Calc is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// GM2Calc is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GM2Calc.  If not, see
// <http://www.gnu.org/licenses/>.
// ====================================================================

#ifndef GM2_CONFIG_OPTIONS_H
#define GM2_CONFIG_OPTIONS_H

namespace gm2calc {

/**
 * @class Config_options
 * @brief configuration for the calculation of \f$a_\mu\f$
 */
struct Config_options {
   enum E_output_format : unsigned {
      Minimal = 0, Detailed = 1, NMSSMTools = 2, SPheno = 3, GM2Calc = 4 };

   Config_options()
     : output_format(Minimal)
     , loop_order(2)
     , tanb_resummation(true)
     , force_output(false)
     , verbose_output(false)
     , calculate_uncertainty(false)
   {}

   E_output_format output_format; ///< output format
   unsigned loop_order;           ///< loop order
   bool tanb_resummation;         ///< tan(beta) resummation
   bool force_output;             ///< print output even if error occured
   bool verbose_output;           ///< print additional information
   bool calculate_uncertainty;    ///< calculate uncertainty
};

} // namespace gm2calc

#endif