/*
//@HEADER
// ************************************************************************
//
//                        Kokkos v. 3.0
//       Copyright (2020) National Technology & Engineering
//               Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY NTESS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NTESS OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Siva Rajamanickam (srajama@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef KOKKOSBLAS1_NRM1_TPL_SPEC_DECL_HPP_
#define KOKKOSBLAS1_NRM1_TPL_SPEC_DECL_HPP_

namespace KokkosBlas {
namespace Impl {

namespace {
template <class RV, class XV>
inline void nrm1_print_specialization() {
#ifdef KOKKOSKERNELS_ENABLE_CHECK_SPECIALIZATION
  printf("KokkosBlas1::nrm1<> TPL Blas specialization for < %s , %s >\n",
         typeid(RV).name(), typeid(XV).name());
#endif
}
}  // namespace
}  // namespace Impl
}  // namespace KokkosBlas

// Generic Host side BLAS (could be MKL or whatever)
#ifdef KOKKOSKERNELS_ENABLE_TPL_BLAS
#include "KokkosBlas_Host_tpl.hpp"

namespace KokkosBlas {
namespace Impl {

#define KOKKOSBLAS1_DNRM1_TPL_SPEC_DECL_BLAS(LAYOUT, MEMSPACE, ETI_SPEC_AVAIL) \
  template <class ExecSpace>                                                   \
  struct Nrm1<                                                                 \
      Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                          \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                  \
      Kokkos::View<const double*, LAYOUT, Kokkos::Device<ExecSpace, MEMSPACE>, \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                  \
      1, true, ETI_SPEC_AVAIL> {                                               \
    typedef Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                    \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >             \
        RV;                                                                    \
    typedef Kokkos::View<const double*, LAYOUT,                                \
                         Kokkos::Device<ExecSpace, MEMSPACE>,                  \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >             \
        XV;                                                                    \
    typedef typename XV::size_type size_type;                                  \
                                                                               \
    static void nrm1(RV& R, const XV& X) {                                     \
      Kokkos::Profiling::pushRegion("KokkosBlas::nrm1[TPL_BLAS,double]");      \
      const size_type numElems = X.extent(0);                                  \
      if (numElems < static_cast<size_type>(INT_MAX)) {                        \
        nrm1_print_specialization<RV, XV>();                                   \
        int N   = numElems;                                                    \
        int one = 1;                                                           \
        R()     = HostBlas<double>::asum(N, X.data(), one);                    \
      } else {                                                                 \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);                    \
      }                                                                        \
      Kokkos::Profiling::popRegion();                                          \
    }                                                                          \
  };

#define KOKKOSBLAS1_SNRM1_TPL_SPEC_DECL_BLAS(LAYOUT, MEMSPACE, ETI_SPEC_AVAIL) \
  template <class ExecSpace>                                                   \
  struct Nrm1<                                                                 \
      Kokkos::View<float, LAYOUT, Kokkos::HostSpace,                           \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                  \
      Kokkos::View<const float*, LAYOUT, Kokkos::Device<ExecSpace, MEMSPACE>,  \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                  \
      1, true, ETI_SPEC_AVAIL> {                                               \
    typedef Kokkos::View<float, LAYOUT, Kokkos::HostSpace,                     \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >             \
        RV;                                                                    \
    typedef Kokkos::View<const float*, LAYOUT,                                 \
                         Kokkos::Device<ExecSpace, MEMSPACE>,                  \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >             \
        XV;                                                                    \
    typedef typename XV::size_type size_type;                                  \
                                                                               \
    static void nrm1(RV& R, const XV& X) {                                     \
      Kokkos::Profiling::pushRegion("KokkosBlas::nrm1[TPL_BLAS,float]");       \
      const size_type numElems = X.extent(0);                                  \
      if (numElems < static_cast<size_type>(INT_MAX)) {                        \
        nrm1_print_specialization<RV, XV>();                                   \
        int N   = numElems;                                                    \
        int one = 1;                                                           \
        R()     = HostBlas<float>::asum(N, X.data(), one);                     \
      } else {                                                                 \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);                    \
      }                                                                        \
      Kokkos::Profiling::popRegion();                                          \
    }                                                                          \
  };

#define KOKKOSBLAS1_ZNRM1_TPL_SPEC_DECL_BLAS(LAYOUT, MEMSPACE, ETI_SPEC_AVAIL)    \
  template <class ExecSpace>                                                      \
  struct Nrm1<Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                     \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,             \
              Kokkos::View<const Kokkos::complex<double>*, LAYOUT,                \
                           Kokkos::Device<ExecSpace, MEMSPACE>,                   \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,             \
              1, true, ETI_SPEC_AVAIL> {                                          \
    typedef Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                       \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >                \
        RV;                                                                       \
    typedef Kokkos::View<const Kokkos::complex<double>*, LAYOUT,                  \
                         Kokkos::Device<ExecSpace, MEMSPACE>,                     \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >                \
        XV;                                                                       \
    typedef typename XV::size_type size_type;                                     \
                                                                                  \
    static void nrm1(RV& R, const XV& X) {                                        \
      Kokkos::Profiling::pushRegion(                                              \
          "KokkosBlas::nrm1[TPL_BLAS,complex<double>]");                          \
      const size_type numElems = X.extent(0);                                     \
      if (numElems < static_cast<size_type>(INT_MAX)) {                           \
        nrm1_print_specialization<RV, XV>();                                      \
        int N   = numElems;                                                       \
        int one = 1;                                                              \
        R()     = HostBlas<std::complex<double> >::asum(                          \
            N, reinterpret_cast<const std::complex<double>*>(X.data()), one); \
      } else {                                                                    \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);                       \
      }                                                                           \
      Kokkos::Profiling::popRegion();                                             \
    }                                                                             \
  };

#define KOKKOSBLAS1_CNRM1_TPL_SPEC_DECL_BLAS(LAYOUT, MEMSPACE, ETI_SPEC_AVAIL)   \
  template <class ExecSpace>                                                     \
  struct Nrm1<Kokkos::View<float, LAYOUT, Kokkos::HostSpace,                     \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,            \
              Kokkos::View<const Kokkos::complex<float>*, LAYOUT,                \
                           Kokkos::Device<ExecSpace, MEMSPACE>,                  \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,            \
              1, true, ETI_SPEC_AVAIL> {                                         \
    typedef Kokkos::View<float, LAYOUT, Kokkos::HostSpace,                       \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >               \
        RV;                                                                      \
    typedef Kokkos::View<const Kokkos::complex<float>*, LAYOUT,                  \
                         Kokkos::Device<ExecSpace, MEMSPACE>,                    \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >               \
        XV;                                                                      \
    typedef typename XV::size_type size_type;                                    \
                                                                                 \
    static void nrm1(RV& R, const XV& X) {                                       \
      Kokkos::Profiling::pushRegion(                                             \
          "KokkosBlas::nrm1[TPL_BLAS,complex<float>]");                          \
      const size_type numElems = X.extent(0);                                    \
      if (numElems < static_cast<size_type>(INT_MAX)) {                          \
        nrm1_print_specialization<RV, XV>();                                     \
        int N   = numElems;                                                      \
        int one = 1;                                                             \
        R()     = HostBlas<std::complex<float> >::asum(                          \
            N, reinterpret_cast<const std::complex<float>*>(X.data()), one); \
      } else {                                                                   \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);                      \
      }                                                                          \
      Kokkos::Profiling::popRegion();                                            \
    }                                                                            \
  };

KOKKOSBLAS1_DNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     true)
KOKKOSBLAS1_DNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     false)

KOKKOSBLAS1_SNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     true)
KOKKOSBLAS1_SNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     false)

KOKKOSBLAS1_ZNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     true)
KOKKOSBLAS1_ZNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     false)

KOKKOSBLAS1_CNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     true)
KOKKOSBLAS1_CNRM1_TPL_SPEC_DECL_BLAS(Kokkos::LayoutLeft, Kokkos::HostSpace,
                                     false)

}  // namespace Impl
}  // namespace KokkosBlas

#endif

// cuBLAS
#ifdef KOKKOSKERNELS_ENABLE_TPL_CUBLAS
#include <KokkosBlas_tpl_spec.hpp>

namespace KokkosBlas {
namespace Impl {

#define KOKKOSBLAS1_DNRM1_TPL_SPEC_DECL_CUBLAS(LAYOUT, MEMSPACE,               \
                                               ETI_SPEC_AVAIL)                 \
  template <class ExecSpace>                                                   \
  struct Nrm1<                                                                 \
      Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                          \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                  \
      Kokkos::View<const double*, LAYOUT, Kokkos::Device<ExecSpace, MEMSPACE>, \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                  \
      1, true, ETI_SPEC_AVAIL> {                                               \
    typedef Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                    \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >             \
        RV;                                                                    \
    typedef Kokkos::View<const double*, LAYOUT,                                \
                         Kokkos::Device<ExecSpace, MEMSPACE>,                  \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >             \
        XV;                                                                    \
    typedef typename XV::size_type size_type;                                  \
                                                                               \
    static void nrm1(RV& R, const XV& X) {                                     \
      Kokkos::Profiling::pushRegion("KokkosBlas::nrm1[TPL_CUBLAS,double]");    \
      const size_type numElems = X.extent(0);                                  \
      if (numElems < static_cast<size_type>(INT_MAX)) {                        \
        nrm1_print_specialization<RV, XV>();                                   \
        const int N       = static_cast<int>(numElems);                        \
        constexpr int one = 1;                                                 \
        KokkosBlas::Impl::CudaBlasSingleton& s =                               \
            KokkosBlas::Impl::CudaBlasSingleton::singleton();                  \
        cublasDasum(s.handle, N, X.data(), one, R.data());                     \
      } else {                                                                 \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);                    \
      }                                                                        \
      Kokkos::Profiling::popRegion();                                          \
    }                                                                          \
  };

#define KOKKOSBLAS1_SNRM1_TPL_SPEC_DECL_CUBLAS(LAYOUT, MEMSPACE,              \
                                               ETI_SPEC_AVAIL)                \
  template <class ExecSpace>                                                  \
  struct Nrm1<                                                                \
      Kokkos::View<float, LAYOUT, Kokkos::HostSpace,                          \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                 \
      Kokkos::View<const float*, LAYOUT, Kokkos::Device<ExecSpace, MEMSPACE>, \
                   Kokkos::MemoryTraits<Kokkos::Unmanaged> >,                 \
      1, true, ETI_SPEC_AVAIL> {                                              \
    typedef Kokkos::View<float, LAYOUT, Kokkos::HostSpace,                    \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >            \
        RV;                                                                   \
    typedef Kokkos::View<const float*, LAYOUT,                                \
                         Kokkos::Device<ExecSpace, MEMSPACE>,                 \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >            \
        XV;                                                                   \
    typedef typename XV::size_type size_type;                                 \
                                                                              \
    static void nrm1(RV& R, const XV& X) {                                    \
      Kokkos::Profiling::pushRegion("KokkosBlas::nrm1[TPL_CUBLAS,float]");    \
      const size_type numElems = X.extent(0);                                 \
      if (numElems < static_cast<size_type>(INT_MAX)) {                       \
        nrm1_print_specialization<RV, XV>();                                  \
        const int N       = static_cast<int>(numElems);                       \
        constexpr int one = 1;                                                \
        KokkosBlas::Impl::CudaBlasSingleton& s =                              \
            KokkosBlas::Impl::CudaBlasSingleton::singleton();                 \
        cublasSasum(s.handle, N, X.data(), one, R.data());                    \
      } else {                                                                \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);                   \
      }                                                                       \
      Kokkos::Profiling::popRegion();                                         \
    }                                                                         \
  };

#define KOKKOSBLAS1_ZNRM1_TPL_SPEC_DECL_CUBLAS(LAYOUT, MEMSPACE,              \
                                               ETI_SPEC_AVAIL)                \
  template <class ExecSpace>                                                  \
  struct Nrm1<Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                 \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,         \
              Kokkos::View<const Kokkos::complex<double>*, LAYOUT,            \
                           Kokkos::Device<ExecSpace, MEMSPACE>,               \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,         \
              1, true, ETI_SPEC_AVAIL> {                                      \
    typedef Kokkos::View<double, LAYOUT, Kokkos::HostSpace,                   \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >            \
        RV;                                                                   \
    typedef Kokkos::View<const Kokkos::complex<double>*, LAYOUT,              \
                         Kokkos::Device<ExecSpace, MEMSPACE>,                 \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >            \
        XV;                                                                   \
    typedef typename XV::size_type size_type;                                 \
                                                                              \
    static void nrm1(RV& R, const XV& X) {                                    \
      Kokkos::Profiling::pushRegion(                                          \
          "KokkosBlas::nrm1[TPL_CUBLAS,complex<double>]");                    \
      const size_type numElems = X.extent(0);                                 \
      if (numElems < static_cast<size_type>(INT_MAX)) {                       \
        nrm1_print_specialization<RV, XV>();                                  \
        const int N       = static_cast<int>(numElems);                       \
        constexpr int one = 1;                                                \
        KokkosBlas::Impl::CudaBlasSingleton& s =                              \
            KokkosBlas::Impl::CudaBlasSingleton::singleton();                 \
        cublasDzasum(s.handle, N,                                             \
                     reinterpret_cast<const cuDoubleComplex*>(X.data()), one, \
                     R.data());                                               \
      } else {                                                                \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);                   \
      }                                                                       \
      Kokkos::Profiling::popRegion();                                         \
    }                                                                         \
  };

#define KOKKOSBLAS1_CNRM1_TPL_SPEC_DECL_CUBLAS(LAYOUT, MEMSPACE,        \
                                               ETI_SPEC_AVAIL)          \
  template <class ExecSpace>                                            \
  struct Nrm1<Kokkos::View<float, LAYOUT, Kokkos::HostSpace,            \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,   \
              Kokkos::View<const Kokkos::complex<float>*, LAYOUT,       \
                           Kokkos::Device<ExecSpace, MEMSPACE>,         \
                           Kokkos::MemoryTraits<Kokkos::Unmanaged> >,   \
              1, true, ETI_SPEC_AVAIL> {                                \
    typedef Kokkos::View<float, LAYOUT, Kokkos::HostSpace,              \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >      \
        RV;                                                             \
    typedef Kokkos::View<const Kokkos::complex<float>*, LAYOUT,         \
                         Kokkos::Device<ExecSpace, MEMSPACE>,           \
                         Kokkos::MemoryTraits<Kokkos::Unmanaged> >      \
        XV;                                                             \
    typedef typename XV::size_type size_type;                           \
                                                                        \
    static void nrm1(RV& R, const XV& X) {                              \
      Kokkos::Profiling::pushRegion(                                    \
          "KokkosBlas::nrm1[TPL_CUBLAS,complex<float>]");               \
      const size_type numElems = X.extent(0);                           \
      if (numElems < static_cast<size_type>(INT_MAX)) {                 \
        nrm1_print_specialization<RV, XV>();                            \
        const int N       = static_cast<int>(numElems);                 \
        constexpr int one = 1;                                          \
        KokkosBlas::Impl::CudaBlasSingleton& s =                        \
            KokkosBlas::Impl::CudaBlasSingleton::singleton();           \
        cublasScasum(s.handle, N,                                       \
                     reinterpret_cast<const cuComplex*>(X.data()), one, \
                     R.data());                                         \
      } else {                                                          \
        Nrm1<RV, XV, 1, false, ETI_SPEC_AVAIL>::nrm1(R, X);             \
      }                                                                 \
      Kokkos::Profiling::popRegion();                                   \
    }                                                                   \
  };

KOKKOSBLAS1_DNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       true)
KOKKOSBLAS1_DNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       false)

KOKKOSBLAS1_SNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       true)
KOKKOSBLAS1_SNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       false)

KOKKOSBLAS1_ZNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       true)
KOKKOSBLAS1_ZNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       false)

KOKKOSBLAS1_CNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       true)
KOKKOSBLAS1_CNRM1_TPL_SPEC_DECL_CUBLAS(Kokkos::LayoutLeft, Kokkos::CudaSpace,
                                       false)

}  // namespace Impl
}  // namespace KokkosBlas

#endif

#endif
