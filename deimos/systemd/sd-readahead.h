/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#ifndef foosdreadaheadhfoo
#define foosdreadaheadhfoo

/***
  Copyright 2010 Lennart Poettering

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this software and associated documentation files
  (the "Software"), to deal in the Software without restriction,
  including without limitation the rights to use, copy, modify, merge,
  publish, distribute, sublicense, and/or sell copies of the Software,
  and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
***/

#ifdef __cplusplus
extern "C" {
#endif

/*
  Reference implementation of a few boot readahead related
  interfaces. These interfaces are trivial to implement. To simplify
  porting we provide this reference implementation.  Applications are
  welcome to reimplement the algorithms described here if they do not
  want to include these two source files.

  You may compile this with -DDISABLE_SYSTEMD to disable systemd
  support. This makes all calls NOPs.

  Since this is drop-in code we don't want any of our symbols to be
  exported in any case. Hence we declare hidden visibility for all of
  them.

  You may find an up-to-date version of these source files online:

  http://cgit.freedesktop.org/systemd/plain/src/sd-readahead.h
  http://cgit.freedesktop.org/systemd/plain/src/sd-readahead.c

  This should compile on non-Linux systems, too, but all functions
  will become NOPs.

  See sd-readahead(7) for more information.
*/

#ifndef _sd_hidden_
#if (__GNUC__ >= 4) && !defined(SD_EXPORT_SYMBOLS)
#define _sd_hidden_ __attribute__ ((visibility("hidden")))
#else
#define _sd_hidden_
#endif
#endif

/*
  Controls ongoing disk read-ahead operations during boot-up. The argument
  must be a string, and either "cancel", "done" or "noreplay".

  cancel = terminate read-ahead data collection, drop collected information
  done = terminate read-ahead data collection, keep collected information
  noreplay = terminate read-ahead replay
*/
int sd_readahead(const char *action) _sd_hidden_;

#ifdef __cplusplus
}
#endif

#endif
