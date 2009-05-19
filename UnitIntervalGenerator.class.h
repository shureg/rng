#ifndef UNITINTERVALGENERATOR_CLASS_H_INCLUDED
#define UNITINTERVALGENERATOR_CLASS_H_INCLUDED

namespace MCS_RNG
{
   //! A generic class that sequentially generates a number in the unit interval
   class UnitIntervalGenerator
   {
   public:

      //! Generates a number in the unit interval
      double operator() = 0;

      //! Determines whether the generated number can take an interval endpont value (0 or 1)
      /*! Subtle differences in various implementations on unit interval number generators
      may differ in whether the values generated can be 0, 1, both, or neither. This difference
      may sometimes be important. To see why, consider an example of generating a univariate
      exponentially distributed random variable via the inverse distribution function method.
      The formula is quite simple, to get an exponential random variable \f$ x \f$ with mean \f$ \lambda \f$
      from a uniform random variable \f$ u \f$ we use \f$ x = \frac{\log 1-u}{\lambda} \f$ . This is
      sometimes simplified to \f$ x = \frac{\log u}{\lambda} \f$ on the basis that \f$ u \f$ and
      \f$ 1-u \f$ have the same distribution. Clearly the former formula will have a problem if \f$ u \f$
      can be equal to \f$ 1 \f$ , while the latter will fail when \f$ u \f$ is \f$ 0 \f$ . Although it
      is quite difficult to handle such issues automatically it is imporant to provide the users
      of the MCS_RNG::UnitIntervalGenerator object with the means to determine which endpoints, if any, are
      reachable by the generator.
      */
      bool endpoint_reachable(int);

   protected:

      //! Determines whether the generated number can be equal to zero
      bool can_be_zero;

      //! Determines whether the generated number can be equal to one
      bool can_be_one;

   };
}

#endif // UNITINTERVALGENERATOR_CLASS_H_INCLUDED
