/* file      : libicu/data/unit.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/unit.c>
#else
#  include <libicu/data/le/unit.c>
#endif
