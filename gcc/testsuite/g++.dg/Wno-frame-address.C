// { dg-do compile }
// { dg-skip-if "Cannot access arbitrary stack frames." { arm*-*-* } }
// { dg-options "-Werror" }

// Verify that -Wframe-address is not enabled by default by enabling
// -Werror and verifying the test still compiles.
#include "Wframe-address.C"
