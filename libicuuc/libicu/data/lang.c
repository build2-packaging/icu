/* file      : libicu/data/lang.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/lang.c>
#else
#  include <libicu/data/le/lang.c>
#endif
