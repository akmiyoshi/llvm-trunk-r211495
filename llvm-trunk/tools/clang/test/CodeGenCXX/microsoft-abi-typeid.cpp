// RUN: %clang_cc1 -emit-llvm -O1 -o - -triple=i386-pc-win32 %s | FileCheck %s

struct type_info;
namespace std { using ::type_info; }

struct V { virtual void f(); };
struct A : virtual V { A(); };

extern A a;
extern int b;
A* fn();

const std::type_info* test0_typeid() { return &typeid(int); }
// CHECK-LABEL: define %struct.type_info* @"\01?test0_typeid@@YAPBUtype_info@@XZ"()
// CHECK:   ret %struct.type_info* bitcast (%"MSRTTITypeDescriptor\02"* @"\01??_R0H@8" to %struct.type_info*)

const std::type_info* test1_typeid() { return &typeid(A); }
// CHECK-LABEL: define %struct.type_info* @"\01?test1_typeid@@YAPBUtype_info@@XZ"()
// CHECK:   ret %struct.type_info* bitcast (%"MSRTTITypeDescriptor\07"* @"\01??_R0?AUA@@@8" to %struct.type_info*)

const std::type_info* test2_typeid() { return &typeid(&a); }
// CHECK-LABEL: define %struct.type_info* @"\01?test2_typeid@@YAPBUtype_info@@XZ"()
// CHECK:   ret %struct.type_info* bitcast (%"MSRTTITypeDescriptor\07"* @"\01??_R0PAUA@@@8" to %struct.type_info*)

const std::type_info* test3_typeid() { return &typeid(*fn()); }
// CHECK-LABEL: define %struct.type_info* @"\01?test3_typeid@@YAPBUtype_info@@XZ"()
// CHECK:        [[CALL:%.*]] = tail call %struct.A* @"\01?fn@@YAPAUA@@XZ"()
// CHECK-NEXT:   [[CMP:%.*]] = icmp eq %struct.A* [[CALL]], null
// CHECK-NEXT:   br i1 [[CMP]]
// CHECK:        tail call i8* @__RTtypeid(i8* null)
// CHECK-NEXT:   unreachable
// CHECK:        [[THIS:%.*]] = bitcast %struct.A* [[CALL]] to i8*
// CHECK-NEXT:   [[VBTBLP:%.*]] = bitcast %struct.A* [[CALL]] to i8**
// CHECK-NEXT:   [[VBTBL:%.*]] = load i8** [[VBTBLP]], align 4
// CHECK-NEXT:   [[VBSLOT:%.*]] = getelementptr inbounds i8* [[VBTBL]], i32 4
// CHECK-NEXT:   [[VBITCST:%.*]] = bitcast i8* [[VBSLOT]] to i32*
// CHECK-NEXT:   [[VBASE_OFFS:%.*]] = load i32* [[VBITCST]], align 4
// CHECK-NEXT:   [[ADJ:%.*]] = getelementptr inbounds i8* [[THIS]], i32 [[VBASE_OFFS]]
// CHECK-NEXT:   [[RT:%.*]] = tail call i8* @__RTtypeid(i8* [[ADJ]])
// CHECK-NEXT:   [[RET:%.*]] = bitcast i8* [[RT]] to %struct.type_info*
// CHECK-NEXT:   ret %struct.type_info* [[RET]]

const std::type_info* test4_typeid() { return &typeid(b); }
// CHECK: define %struct.type_info* @"\01?test4_typeid@@YAPBUtype_info@@XZ"()
// CHECK:   ret %struct.type_info* bitcast (%"MSRTTITypeDescriptor\02"* @"\01??_R0H@8" to %struct.type_info*)
