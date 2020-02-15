/* file      : libicu/data/other.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/other.c>
#else
#  include <libicu/data/le/other.c>
#endif
