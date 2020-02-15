/* file      : libicu/data/config.h -*- C -*-
 * license   : Unicode License; see accompanying LICENSE file
 */

#ifndef LIBICU_DATA_CONFIG_H
#define LIBICU_DATA_CONFIG_H

/*
 * Introduce the charset/endianness macro definitions. Also make sure there is
 * no the 'U_DISABLE_RENAMING redefined' warning for the upstream's
 * auto-generated files.
 */
#ifndef IN_GENERATED_CCODE
#  define IN_GENERATED_CCODE
#  define U_DISABLE_RENAMING 1
#  include "unicode/umachine.h"
#endif

/*
 * The only other possible charset is EBCDIC that may only appear on the
 * big-endian architectures and currently is not very common. Note that we can
 * add support for it, if requested (see README-DEV for details).
 */
#if U_CHARSET_FAMILY != U_ASCII_FAMILY
#  error EBCDIC charset is not supported
#endif

#endif /* LIBICU_DATA_CONFIG_H */
