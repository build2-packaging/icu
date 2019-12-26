/* file      : tests/basic/driver.c
 * copyright : Copyright (c) 2009-2019 Code Synthesis Tools CC
 * license   : Unicode License; see accompanying LICENSE file
 */
#include <stdio.h>
#include <assert.h>

#include <unicode/uloc.h>
#include <unicode/udata.h>
#include <unicode/uclean.h>
#include <unicode/utypes.h>
#include <unicode/uversion.h>

/* Usage: argv[0]
 *
 * Test some basic libicuuc functionality:
 *
 * - query and print the library version
 * - set, query and print the default locale
 * - load a portion of the bundled data and print its format id/version
 */
int
main ()
{
  /* Print version.
   */
  UVersionInfo v;
  u_getVersion (v);

  char s[U_MAX_VERSION_STRING_LENGTH];
  u_versionToString (v, s);

  printf ("version: %s\n", s);

  /* Change and print the current locale.
   */
  UErrorCode e = U_ZERO_ERROR;

  uloc_setDefault ("en_GB", &e);

  if (U_FAILURE (e))
  {
    fprintf (stderr, "uloc_setDefault failed: %s\n", u_errorName (e));
    u_cleanup ();
    return 1;
  }

  printf ("locale: %s\n", uloc_getDefault ());

  /* Check that data is properly loaded from the libicudata's data bundle and
   * print its format id/version.
   */
  UDataMemory* d = udata_open (NULL, "res", "en_US", &e);

  if (U_FAILURE (e))
  {
    fprintf (stderr, "udata_open failed: %s\n", u_errorName (e));
    u_cleanup ();
    return 1;
  }

  UDataInfo i;
  i.size = sizeof (UDataInfo);

  udata_getInfo (d, &i);

  assert (i.isBigEndian   == U_IS_BIG_ENDIAN);
  assert (i.charsetFamily == U_CHARSET_FAMILY);

  printf ("data: %.4s/%u.%u.%u.%u %u.%u.%u.%u\n",
          i.dataFormat,
          i.formatVersion[0],
          i.formatVersion[1],
          i.formatVersion[2],
          i.formatVersion[3],
          i.dataVersion[0],
          i.dataVersion[1],
          i.dataVersion[2],
          i.dataVersion[3]);

  udata_close (d);

  u_cleanup ();

  return 0;
}
