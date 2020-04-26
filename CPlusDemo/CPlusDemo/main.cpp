//
//  main.cpp
//  CPlusDemo
//
//  Created by uwei on 4/29/16.
//  Copyright © 2016 Tencent. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include "Header.h"

class VirtualClass {
public:
    VirtualClass();
    virtual void f1() = 0; // 纯虚函数不用基类实现，但子类必须实现
    virtual void f2();     // 虚函数表明子类可以override，但是基类也必须实现
    
    ~VirtualClass();
};

VirtualClass::VirtualClass() {}

VirtualClass::~VirtualClass(){}

void VirtualClass::f2() {
    std::cout<< "this is base class" << std::endl;
    this->f1();
}

class SubVirtualClass:public VirtualClass {
public:
    SubVirtualClass();
    ~SubVirtualClass();
    void f1();
};

SubVirtualClass::SubVirtualClass(){}
SubVirtualClass::~SubVirtualClass(){}

void SubVirtualClass::f1() {
    std::cout<< "this is sub class" << std::endl;
}

class BaseTest {virtual void dummy(){};};
class Base {virtual void dummy(){};};
class CastA {};
class CastB {};
class CastC : public Base {
    void dummy();
};


void CastC::dummy() {
    
}


//以size最大的结构作为自己的大小
// 也就是说，整型i和匿名结构体s在内存中的起始地址是一样的，但是这个联合体的大小是匿名结构体的大小
// 切记联合体是内存共享的，要注意赋值的时候的内存占用大小
union MyUnion {
    struct {
        int x;
        int y;
        int z;
    } s;
    
    int i;
    double d;
};



struct StructA {
    int m_i;
    char m_c;
    double m_d;
};

struct StructB {
    double m_d;
    int m_i;
    char m_c;
};

struct StructC {
    int m_i;
    double m_d;
    char m_c;
    
};

struct CustomSetStruct {
    int age;
    char * name;
    
#pragma mark - operator overloading
    // for set
    bool operator <(const CustomSetStruct &c)const {
        return age < c.age;
    }
};


class ABC(class1) {
public:
    ABC(class1)(std::string name) {
        this->s_name = name;
    }
    void printInfo();
private:
    std::string s_name;
};

void ABC(class1)::printInfo() {
    std::cout << "My name is " << s_name << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
#pragma mark - Macro Demo

    ABC(class1) test1 =  ABC(class1)("haha");
    test1.printInfo();
    int i_num = 1021;
    MyPrint(i_num)
    
    
#pragma mark - Pointer
    
    int *iPtr = nullptr;
    char *cPtr = nullptr;
    std::cout << "sizeof iPtr is " << sizeof(iPtr) << std::endl;
    std::cout << "sizeof iPtr is " << sizeof(cPtr) << std::endl;
    char *pChar = "Uwei";
//    pChar[2] = 'x'; // because pChar is point to a const that not allowed to modify
    std::cout << "pChar " << pChar << std::endl;
    
    
    CastA *castA = new CastA();
//    CastB *reinterpertA = reinterpret_cast<CastA *>(castA); //
    CastB *reinterpertBFromA = reinterpret_cast<CastB *>(castA);
    
    
//    CastB *staticBFromA      = static_cast<CastB *>(castA);
    Base *base          = new Base;
    CastC *staticC      = static_cast<CastC *>(base);
    
    const CastA *constCastA = new CastA();
    
//    CastB *constB       = const_cast<CastB *>(castA);
//    const CastB *constB       = const_cast<CastB *>(constCastA);
    CastA *variableCastA = const_cast<CastA *>(constCastA);
    
//    CastB *dynamicB      = dynamic_cast<CastB *>(castA);
    
    CastC *dynamicCFromBase = dynamic_cast<CastC *>(base);
    CastC *castC            = new CastC();
    CastC *dynamicCFromC    = dynamic_cast<CastC *>(castC);
    
    BaseTest *testBase = new BaseTest();
    
    CastA *testA            = dynamic_cast<CastA *>(testBase);
    
    
    StructA a;
    StructB b;
    StructC c;
    std::cout << "Size strcut A is " << sizeof(a) << std::endl;
    std::cout << "Size strcut B is " << sizeof(b) << std::endl;
    std::cout << "Size strcut C is " << sizeof(c) << std::endl;
    int i1 = 1, i2 = 2, i3 = 3;
    int *p[3] = {&i1, &i2, &i3};
    for (int i = 0; i < 3; i++) {
        std::cout<< "p[" << i << "] = " << *p[i] << std::endl;
     }
    
    
    
    int ia[4] = {1,2,3,4};
    
    int (*pp)[4] = &ia;
    
    for (int i = 0; i < 4; i++) {
        std::cout<< "pp[" << i << "] = " << (*pp)[i] << std::endl;
    }
    
    int *ppp[2][2] = {0};
    int (*pppp)[2][2] = {0};
    
    MyUnion myu;
    myu.s.x = 1;
    myu.s.y = 2;
    myu.s.z = 3;
    
    myu.i   = 0;
    
    std::cout<< "MyUnion is " << myu.s.x << "  " << myu.s.y << "  " << myu.s.z << std::endl;
    
    // 由于double类型占用内存比int类型的要大两倍，那么也就可以推定，x,y都没有值了
    myu.d = 100.02;
    
    std::cout<< "MyUnion is " << myu.s.x << "  " << myu.s.y << "  " << myu.s.z << std::endl;
    
    
    const char *constChar = "uwei";
    constChar = "yuan";
    const char * const constCharPtr = "test";
//    constCharPtr = "testcopy"; // not allow
    
    
    StructA aa1 = {10, 65, 10.1};
    StructA aa2 = {11, 66, 10.2};
    std::set<StructA> seta; // compier error because of no override operator <
    std::vector<StructA> vectorA;
    vectorA.push_back(aa2);
    vectorA.push_back(aa1);
    
//    seta.insert(aa1);
//    seta.insert(aa2);
//    seta.insert(aa3);
//    seta.insert(aa4);
    
    std::set<int> iset;
    iset.insert(12);
    iset.insert(34);
    iset.insert(2);
    
    int isetint = 100;
    iset.insert(isetint);
    
    std::set<int>::iterator it;
    
    for (it = iset.begin(); it != iset.end(); it++) {
        std::cout<< *it << std::endl;
    }
    
    CustomSetStruct custom1 = {10, "uwei"};
    CustomSetStruct custom2 = {11, "yuan"};
    std::set<CustomSetStruct> cSet;
    cSet.insert(custom1);
    cSet.insert(custom2);
    
    std::set<CustomSetStruct>:: iterator setIt;
    
    for (setIt = cSet.begin(); setIt != cSet.end(); ++setIt) {
        std::cout<< setIt->age << "    " << setIt->name <<std::endl;
    }
    
    VirtualClass *vc = new SubVirtualClass();
    vc->f1();
    
    
    
    return 0;
}
