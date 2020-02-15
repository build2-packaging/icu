/* file      : libicu/data/coll.c -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/coll.c>
#else
#  include <libicu/data/le/coll.c>
#endif
