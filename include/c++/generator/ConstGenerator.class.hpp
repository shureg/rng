// =====================================================================================
// 
//       Filename:  ConstGenerator.class.hpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  30/10/09 14:57:58
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Alexander Kabanov (aak), alexander.kabanov@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef  CONSTGENERATOR_CLASS_INC
#define  CONSTGENERATOR_CLASS_INC

#include "TypedRandomGenerator.class.hpp"

namespace RNG
{
   template<typename T> class ConstGenerator: 
      public TypedRandomGenerator<T>
   {
      public:

	 ConstGenerator(const T&);

	 const T operator() () const;

	 XmlField xml_description() const;

      protected:

	 T value;
   };

   template<typename T> ConstGenerator<T>::ConstGenerator(const T& _value): value(_value)
   {}

   template<typename T> const T ConstGenerator<T> operator() () const
   {
      return value;
   }

   tmeplate<typename T> XmlField ConstGenerator<T>::xml_description() const
   {
      XmlField tmp("Const_Generator");
      tmp.add_field("value",value);

      return tmp;
   }
}

#endif   // ----- #ifndef CONSTGENERATOR_CLASS_INC  -----
