/* file      : libicu/data/brkitr.c -*- C -*-
 * copyright : Copyright (c) 2016-2019 Code Synthesis Ltd
 * license   : Unicode License; see accompanying LICENSE file
 */

#include <libicu/data/config.h>

#if U_IS_BIG_ENDIAN
#  include <libicu/data/be/brkitr.c>
#else
#  include <libicu/data/le/brkitr.c>
#endif
