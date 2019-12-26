/* file      : libicu/data/icudt_dat.c -*- C -*-
 * copyright : Copyright (c) 2016-2019 Code Synthesis Ltd
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/icudt65b_dat.c>
#else
#  include <libicu/data/le/icudt65l_dat.c>
#endif
