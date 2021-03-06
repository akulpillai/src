// RUN: not llvm-mc -triple=aarch64 -show-encoding -mattr=+sve  2>&1 < %s| FileCheck %s


// ------------------------------------------------------------------------- //
// Invalid predicate

fmls z0.h, p8/m, z1.h, z2.h
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: restricted predicate has range [0, 7].
// CHECK-NEXT: fmls z0.h, p8/m, z1.h, z2.h
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:


// ------------------------------------------------------------------------- //
// Invalid element width

fmls z0.s, p7/m, z1.h, z2.h
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: invalid element width
// CHECK-NEXT: fmls z0.s, p7/m, z1.h, z2.h
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:


// ------------------------------------------------------------------------- //
// z register out of range for index

fmls z0.h, z1.h, z8.h[0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: Invalid restricted vector register, expected z0.h..z7.h
// CHECK-NEXT: fmls z0.h, z1.h, z8.h[0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

fmls z0.s, z1.s, z8.s[0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: Invalid restricted vector register, expected z0.s..z7.s
// CHECK-NEXT: fmls z0.s, z1.s, z8.s[0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

fmls z0.d, z1.d, z16.d[0]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: Invalid restricted vector register, expected z0.d..z15.d
// CHECK-NEXT: fmls z0.d, z1.d, z16.d[0]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:


// ------------------------------------------------------------------------- //
// Invalid element index

fmls z0.h, z1.h, z2.h[-1]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: vector lane must be an integer in range [0, 7].
// CHECK-NEXT: fmls z0.h, z1.h, z2.h[-1]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

fmls z0.h, z1.h, z2.h[8]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: vector lane must be an integer in range [0, 7].
// CHECK-NEXT: fmls z0.h, z1.h, z2.h[8]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

fmls z0.s, z1.s, z2.s[-1]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: vector lane must be an integer in range [0, 3].
// CHECK-NEXT: fmls z0.s, z1.s, z2.s[-1]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

fmls z0.s, z1.s, z2.s[4]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: vector lane must be an integer in range [0, 3].
// CHECK-NEXT: fmls z0.s, z1.s, z2.s[4]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

fmls z0.d, z1.d, z2.d[-1]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: vector lane must be an integer in range [0, 1].
// CHECK-NEXT: fmls z0.d, z1.d, z2.d[-1]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:

fmls z0.d, z1.d, z2.d[2]
// CHECK: [[@LINE-1]]:{{[0-9]+}}: error: vector lane must be an integer in range [0, 1].
// CHECK-NEXT: fmls z0.d, z1.d, z2.d[2]
// CHECK-NOT: [[@LINE-1]]:{{[0-9]+}}:
