/* file      : libicu/data/region.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/region.c>
#else
#  include <libicu/data/le/region.c>
#endif
