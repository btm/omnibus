/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Christian Schulte, 2004
 *
 *  Last modified:
 *     $Date: 2010-05-11 12:33:38 +0200 (Tue, 11 May 2010) $ by $Author: tack $
 *     $Revision: 10940 $
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <gecode/driver.hh>

#include <cmath>

namespace Gecode { namespace Driver {
    
  void 
  stop(Support::Timer& timer, std::ostream& os) {
    double t = timer.stop();
    double sec = floor(t / 1000.0);
    int o_msec = static_cast<int>(t - 1000.0*sec);
    double min = floor(sec / 60.0);
    int o_sec = static_cast<int>(sec - 60.0*min);
    double hour = floor(min / 60.0);
    int o_min = static_cast<int>(min - 60.0*hour);
    double day = floor(hour / 24.0);
    int o_hour = static_cast<int>(hour - 24.0*day);
    int o_day = static_cast<int>(day);
    if (o_day)
      os << o_day << " days, ";
    if (o_hour)
      os << o_hour << ":";
    if (o_min) {
      if (o_hour) {
        os.width(2); os.fill('0');
      }
      os << o_min << ":";
      os.width(2); os.fill('0');
    }
    os << o_sec << ".";
    os.width(3); os.fill('0');
    os << o_msec
       << " ("
       << std::showpoint << std::fixed
       << std::setprecision(6) << t << " ms)";
  }
  
  
  double
  am(double t[], int n) {
    if (n < 1)
      return 0.0;
    double s = 0;
    for (int i=n; i--; )
      s += t[i];
    return s / n;
  }
  
  double
  dev(double t[], int n) {
    if (n < 2)
      return 0.0;
    double m = am(t,n);
    double s = 0.0;
    for (int i=n; i--; ) {
      double d = t[i]-m;
      s += d*d;
    }
    return ::sqrt(s / (n-1)) / m;
  }

  bool Cutoff::sigint;

}}

// STATISTICS: driver-any
