// Copyright (C) 2015 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// { dg-options "-std=gnu++11 -lstdc++fs" }
// { dg-require-filesystem-ts "" }

#include <experimental/filesystem>
#include <testsuite_hooks.h>
#include <testsuite_fs.h>

namespace fs = std::experimental::filesystem;

void
test01()
{
  bool test __attribute__((unused)) = false;

  std::error_code ec;
  auto p = __gnu_test::nonexistent_path();
  canonical( p, ec );
  VERIFY( ec );

  p = fs::current_path();
  canonical( p, ec );
  VERIFY( !ec );

  p = "/";
  p = canonical( p, ec );
  VERIFY( p == "/" );
  VERIFY( !ec );

  p = "/.";
  p = canonical( p, ec );
  VERIFY( p == "/" );
  VERIFY( !ec );

  p = "/..";
  p = canonical( p, ec );
  VERIFY( p == "/" );
  VERIFY( !ec );

  p = "/../.././.";
  p = canonical( p, ec );
  VERIFY( p == "/" );
  VERIFY( !ec );

  p = "/dev/stdin";
  if (exists(p))
    {
      auto p2 = canonical(p);
      if (is_symlink(p))
        VERIFY( p != p2 );
      else
        VERIFY( p == p2 );
      VERIFY( canonical(p2) == p2 );
    }
}

int
main()
{
  test01();
}
