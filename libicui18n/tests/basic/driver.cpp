// file      : tests/basic/driver.cpp
// license   : Unicode License; see accompanying LICENSE file

#include <string>
#include <memory>    // unique_ptr
#include <cassert>
#include <iostream>
#include <stdexcept> // runtime_error

#include <unicode/utypes.h>
#include <unicode/uclean.h>

#include <unicode/datefmt.h>
#include <unicode/calendar.h>
#include <unicode/timezone.h>
#include <unicode/bytestream.h>

// Usage: argv[0] <locale>
//
// Print the full 01/01/2020 00:00 time in Berlin's timezone using the
// specified locale.
//
int
main (int argc, char* argv[])
{
  using namespace std;
  using namespace icu;

  assert (argc == 2);
  const char* locale (argv[1]);

  UErrorCode e (U_ZERO_ERROR);

  auto validate = [&e] (const char* what)
  {
    if (U_FAILURE (e))
      throw runtime_error (string (what) + " failed: " + u_errorName (e));
  };

  int r (0);

  try
  {
    unique_ptr<Calendar> cal (Calendar::createInstance (e));
    validate ("Calendar::createInstance()");

    cal->adoptTimeZone (TimeZone::createTimeZone ("Europe/Berlin"));
    cal->clear ();
    cal->set (2020, Calendar::JANUARY, 1);

    UDate date (cal->getTime (e));
    validate ("Calendar::getTime()");

    unique_ptr<DateFormat> fmt (
      DateFormat::createDateTimeInstance (DateFormat::kFull,
                                          DateFormat::kFull,
                                          locale));

    fmt->setCalendar (*cal);

    UnicodeString us;
    fmt->format(date, us, e);
    validate ("DateFormat::format()");

    string s;
    StringByteSink<string> bs (&s);
    us.toUTF8 (bs);

    cout << s << endl;
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
