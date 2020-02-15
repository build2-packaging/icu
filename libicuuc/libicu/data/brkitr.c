/* file      : libicu/data/brkitr.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/brkitr.c>
#else
#  include <libicu/data/le/brkitr.c>
#endif
