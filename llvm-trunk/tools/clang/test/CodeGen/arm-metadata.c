// REQUIRES: arm-registered-target
// RUN: %clang_cc1 -triple armv7a-linux-gnueabi -emit-llvm -o - %s | FileCheck -check-prefix=DEFAULT %s
// RUN: %clang_cc1 -triple armv7a-linux-gnueabi -emit-llvm -o - %s -fshort-enums | FileCheck -check-prefix=SHORT-ENUM %s
// RUN: %clang_cc1 -triple armv7a-linux-gnueabi -emit-llvm -o - %s -fshort-wchar | FileCheck -check-prefix=SHORT-WCHAR %s

// DEFAULT:  !{{[0-9]+}} = metadata !{i32 1, metadata !"wchar_size", i32 4}
// DEFAULT:   !{{[0-9]+}} = metadata !{i32 1, metadata !"min_enum_size", i32 4}

// SHORT-WCHAR: !{{[0-9]+}} = metadata !{i32 1, metadata !"wchar_size", i32 2}
// SHORT-WCHAR:   !{{[0-9]+}} = metadata !{i32 1, metadata !"min_enum_size", i32 4}

// SHORT_ENUM:  !{{[0-9]+}} = metadata !{i32 1, metadata !"wchar_size", i32 4}
// SHORT-ENUM:  !{{[0-9]+}} = metadata !{i32 1, metadata !"min_enum_size", i32 1}
