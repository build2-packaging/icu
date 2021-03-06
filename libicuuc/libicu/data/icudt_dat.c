/* file      : libicu/data/icudt_dat.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/icudt65b_dat.c>
#else
#  include <libicu/data/le/icudt65l_dat.c>
#endif
