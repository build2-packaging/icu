/* file      : libicu/data/zone.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/zone.c>
#else
#  include <libicu/data/le/zone.c>
#endif
