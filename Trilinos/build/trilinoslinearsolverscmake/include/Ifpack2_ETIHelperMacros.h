#ifndef IFPACK2_ETIHELPERMACROS_H_
#define IFPACK2_ETIHELPERMACROS_H_

#include <Ifpack2_ConfigDefs.hpp>
#include <Tpetra_ConfigDefs.hpp>
#include <Tpetra_CrsMatrix.hpp>
#include <Tpetra_CrsGraph.hpp>

#define IFPACK2_INSTANTIATE_SL(INSTMACRO)\
	INSTMACRO( double , int )


#define IFPACK2_INSTANTIATE_SL_REAL(INSTMACRO)\
	INSTMACRO( double , int , longlong )


#define IFPACK2_INSTANTIATE_L(INSTMACRO)\
	INSTMACRO( int )


#define IFPACK2_INSTANTIATE_SLG(INSTMACRO)\
	INSTMACRO( double , int , longlong )


#define IFPACK2_INSTANTIATE_SLG_REAL(INSTMACRO)\
	INSTMACRO( double , int , longlong )


#define IFPACK2_INSTANTIATE_LG(INSTMACRO)\
	INSTMACRO( int , longlong )


#define IFPACK2_INSTANTIATE_SLGN(INSTMACRO)\
	INSTMACRO( double , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define IFPACK2_INSTANTIATE_SLGN_REAL(INSTMACRO)\
	INSTMACRO( double , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define IFPACK2_INSTANTIATE_LGN(INSTMACRO)\
	INSTMACRO( double , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define IFPACK2_INSTANTIATE_N(INSTMACRO)\
	INSTMACRO( Kokkos_Compat_KokkosOpenMPWrapperNode )


#define IFPACK2_ETI_MANGLING_TYPEDEFS()  \
	typedef long long longlong; \
	typedef Kokkos::Compat::KokkosOpenMPWrapperNode Kokkos_Compat_KokkosOpenMPWrapperNode;

#endif // IFPACK2_ETIHELPERMACROS_H_
