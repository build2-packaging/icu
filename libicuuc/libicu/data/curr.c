/* file      : libicu/data/curr.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/curr.c>
#else
#  include <libicu/data/le/curr.c>
#endif
