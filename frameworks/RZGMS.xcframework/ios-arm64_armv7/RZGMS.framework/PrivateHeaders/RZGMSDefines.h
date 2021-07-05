//
//  RZGMSDefines.h
//  RZGMS
//
//  Created by yxibng on 2021/6/25.
//

#ifndef RZGMSDefines_h
#define RZGMSDefines_h

#if __has_feature(objc_generics)
#   define __GENERICS(class, ...)      class<__VA_ARGS__>
#   define __GENERICS_TYPE(type)       type
#else
#   define __GENERICS(class, ...)      class
#   define __GENERICS_TYPE(type)       id
#endif




#endif /* RZGMSDefines_h */
