#ifndef TPETRACORE_ETIHELPERMACROS_H
#define TPETRACORE_ETIHELPERMACROS_H

#include <Tpetra_ConfigDefs.hpp>

/* Tpetra provides official support for the following nodes */
#include <Kokkos_DefaultNode.hpp>

/* Tpetra provides official support for dd_real and qd_real */
#if defined(HAVE_TPETRA_QD)
#include <qd/qd_real.h>
#endif

#define TPETRA_INSTANTIATE_SLGN( INSTMACRO ) \
  TPETRA_INSTANTIATE_SLGN_NO_ORDINAL_SCALAR( INSTMACRO ) \
  TPETRA_INSTANTIATE_GLGN( INSTMACRO )

#define TPETRA_INSTANTIATE_VECTOR( INSTMACRO ) \
  TPETRA_INSTANTIATE_SLGN( INSTMACRO )

#define TPETRA_INSTANTIATE_MULTIVECTOR( INSTMACRO ) \
  TPETRA_INSTANTIATE_SLGN_NO_ORDINAL_SCALAR( INSTMACRO ) \
  TPETRA_INSTANTIATE_GLGN_NO_INT( INSTMACRO ) \
  TPETRA_INSTANTIATE_LLGN( INSTMACRO )

#define TPETRA_INSTANTIATE_LLGN(INSTMACRO)\
	INSTMACRO( int , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_GLGN_NO_INT(INSTMACRO)\
	INSTMACRO( longlong , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_GLGN(INSTMACRO)\
	INSTMACRO( longlong , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_GLG(INSTMACRO)\
	INSTMACRO( longlong , int , longlong )


#define TPETRA_INSTANTIATE_PLGN(INSTMACRO)\
	INSTMACRO( int , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )\
	INSTMACRO( double , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )\
	INSTMACRO( longlong , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_LGN(INSTMACRO)\
	INSTMACRO( int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_SLG( INSTMACRO ) \
  TPETRA_INSTANTIATE_SLG_NO_ORDINAL_SCALAR( INSTMACRO ) \
  TPETRA_INSTANTIATE_GLG( INSTMACRO )

#define TPETRA_INSTANTIATE_LG(INSTMACRO)\
	INSTMACRO( int , longlong )


#define TPETRA_INSTANTIATE_SL(INSTMACRO)\
	INSTMACRO( int , int )\
	INSTMACRO( double , int )\
	INSTMACRO( longlong , int )


#define TPETRA_INSTANTIATE_SN(INSTMACRO)\
	INSTMACRO( int , Kokkos_Compat_KokkosOpenMPWrapperNode )\
	INSTMACRO( double , Kokkos_Compat_KokkosOpenMPWrapperNode )\
	INSTMACRO( longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_GN(INSTMACRO)\
	INSTMACRO( longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_S(INSTMACRO)\
	INSTMACRO( int )\
	INSTMACRO( double )\
	INSTMACRO( longlong )


#define TPETRA_INSTANTIATE_L(INSTMACRO)\
	INSTMACRO( int )


#define TPETRA_INSTANTIATE_G(INSTMACRO)\
	INSTMACRO( longlong )


#define TPETRA_INSTANTIATE_N(INSTMACRO)\
	INSTMACRO( Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_TSLGN(INSTMACRO)


#define TPETRA_INSTANTIATE_TSLG(INSTMACRO)


#define TPETRA_INSTANTIATE_CONVERT(INSTMACRO)


#define TPETRA_INSTANTIATE_CONVERT_SSL(INSTMACRO)


#define TPETRA_INSTANTIATE_TESTMV( INSTMACRO ) \
  TPETRA_INSTANTIATE_SLGN_NO_ORDINAL_SCALAR( INSTMACRO )

#define TPETRA_INSTANTIATE_DOUBLE_INT_INT_N(INSTMACRO)\
	INSTMACRO( double , int , int , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_SLGN_NO_ORDINAL_SCALAR(INSTMACRO)\
	INSTMACRO( double , int , longlong , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_SLG_NO_ORDINAL_SCALAR(INSTMACRO)\
	INSTMACRO( double , int , longlong )


#define TPETRA_INSTANTIATE_SL_NO_ORDINAL_SCALAR(INSTMACRO)\
	INSTMACRO( double , int )


#define TPETRA_INSTANTIATE_SN_NO_ORDINAL_SCALAR(INSTMACRO)\
	INSTMACRO( double , Kokkos_Compat_KokkosOpenMPWrapperNode )


#define TPETRA_INSTANTIATE_S_NO_ORDINAL_SCALAR(INSTMACRO)\
	INSTMACRO( double )


#define TPETRA_ETI_MANGLING_TYPEDEFS()  \
	typedef long long longlong; \
	typedef Kokkos::Compat::KokkosOpenMPWrapperNode Kokkos_Compat_KokkosOpenMPWrapperNode;

#endif // TPETRACORE_ETIHELPERMACROS_H
