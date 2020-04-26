//
//  Header.h
//  CPlusDemo
//
//  Created by uwei on 28/11/2016.
//  Copyright © 2016 Tencent. All rights reserved.
//

#ifndef Header_h
#define Header_h


#define ABC(x) uwei##x // ## 符号是将参数x作为字符串与 ## 符号前面的字符串拼接在一起 转成一个字符串
#define MyPrint(x) std::cout << #x << " is " << x <<std::endl; // # 符号会将跟在后面的参数转成字符串，相当与在参数x上加上""，形成"x"

#endif /* Header_h */
