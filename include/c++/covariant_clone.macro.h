// =====================================================================================
// 
//       Filename:  covariant_clone.macro.h
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  10/28/2010 01:54:45 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================


#ifndef  COVARIANT_CLONE_MACRO_INC
#define  COVARIANT_CLONE_MACRO_INC

#define COVARIANT_CLONE(C) \
   C* real_clone() const \
   { \
      C* tmp = new C(*this); \
      return tmp; \
   }

#define RNG_CLONE(C) \
   RandomGenerator* real_clone() const \
   { \
      C* tmp = new C(*this); \
      return (RandomGenerator*) tmp; \
   }

#endif   // ----- #ifndef COVARIANT_CLONE_MACRO_INC  -----
