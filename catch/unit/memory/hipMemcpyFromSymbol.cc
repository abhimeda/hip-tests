/*
Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <hip_test_common.hh>
#define SIZE 1024

/* Test verifies hipMemcpyFromSymbol API Negative scenarios.
 */

TEST_CASE("Unit_hipMemcpyFromSymbol_Negative") {
  void *Sd;
  char S[SIZE]="This is not a device symbol";

  HIP_CHECK(hipMalloc(&Sd, SIZE));

  SECTION("Passing void pointer") {
    REQUIRE(hipSuccess != hipMemcpyFromSymbol(S, HIP_SYMBOL(Sd),
                              SIZE, 0, hipMemcpyDeviceToHost));
  }

  SECTION("Passing NULL Pointer") {
    REQUIRE(hipSuccess != hipMemcpyFromSymbol(S, nullptr,
                              SIZE, 0, hipMemcpyDeviceToHost));
  }

  HIP_CHECK(hipFree(Sd));
}
