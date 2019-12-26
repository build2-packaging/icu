// file      : tests/basic/driver.cpp
// copyright : Copyright (c) 2009-2019 Code Synthesis Tools CC
// license   : Unicode License; see accompanying LICENSE file

#include <ios>
#include <string>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <stdexcept> // runtime_error

#include <unicode/ucnv.h>
#include <unicode/utypes.h>
#include <unicode/uclean.h>
#include <unicode/ustdio.h>  // u_strFromUTF8()
#include <unicode/ustring.h> // u_fprintf(), u_get_stdout()

#include <unicode/unistr.h>  // UnicodeString
#include <unicode/ustream.h> // operator<<(std::ostream)

// Usage: argv[0]
//
// Read UTF-8 encoded lines from stdin and print them to stdout using C and
// C++ APIs.
//
int
main ()
{
  using namespace std;
  using namespace icu;

  ucnv_setDefaultName ("UTF-8");

  cin.exceptions  (ios::badbit);
  cout.exceptions (ios::badbit | ios::failbit);

  int r (0);

  try
  {
    for (string l; getline (cin, l); )
    {
      // Print using C API.
      //
      {
        // Make sure the converted input string is always NUL-terminated.
        //
        UChar buf[1024 + 1];
        buf[1024] = 0x0;

        int32_t n;
        UErrorCode e (U_ZERO_ERROR);

        auto validate = [&e] (const char* what)
        {
          if (U_FAILURE (e))
            throw runtime_error (
              string (what) + " failed: " + u_errorName (e));
        };

        u_strFromUTF8 (buf, 1024, &n,
                       l.c_str (), static_cast<int32_t> (l.size ()),
                       &e);

        validate ("u_strFromUTF8()");

        assert (n <= 1024);

        u_fprintf (u_get_stdout (), "%S\n", buf);
      }

      // Print using C++ API.
      //
      cout << UnicodeString::fromUTF8 (l) << endl;
    }
  }
  catch (const runtime_error& e)
  {
    cerr << e.what () << endl;

    r = 1;
  }

  // Free any heap storage that has been potentially allocated and held by the
  // ICU library.
  //
  u_cleanup ();

  return r;
}
