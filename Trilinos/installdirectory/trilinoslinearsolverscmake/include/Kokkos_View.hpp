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
// Questions? Contact Christian R. Trott (crtrott@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef KOKKOS_VIEW_HPP
#define KOKKOS_VIEW_HPP

#include <type_traits>
#include <string>
#include <algorithm>
#include <initializer_list>

#include <Kokkos_Core_fwd.hpp>
#include <Kokkos_HostSpace.hpp>
#include <Kokkos_MemoryTraits.hpp>
#include <Kokkos_ExecPolicy.hpp>

#include <impl/Kokkos_Tools.hpp>

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {
namespace Impl {

template <class DataType>
struct ViewArrayAnalysis;

template <class DataType, class ArrayLayout,
          typename ValueType =
              typename ViewArrayAnalysis<DataType>::non_const_value_type>
struct ViewDataAnalysis;

template <class, class...>
class ViewMapping {
 public:
  enum : bool { is_assignable_data_type = false };
  enum : bool { is_assignable = false };
};

template <typename IntType>
KOKKOS_INLINE_FUNCTION std::size_t count_valid_integers(
    const IntType i0, const IntType i1, const IntType i2, const IntType i3,
    const IntType i4, const IntType i5, const IntType i6, const IntType i7) {
  static_assert(std::is_integral<IntType>::value,
                "count_valid_integers() must have integer arguments.");

  return (i0 != KOKKOS_INVALID_INDEX) + (i1 != KOKKOS_INVALID_INDEX) +
         (i2 != KOKKOS_INVALID_INDEX) + (i3 != KOKKOS_INVALID_INDEX) +
         (i4 != KOKKOS_INVALID_INDEX) + (i5 != KOKKOS_INVALID_INDEX) +
         (i6 != KOKKOS_INVALID_INDEX) + (i7 != KOKKOS_INVALID_INDEX);
}

KOKKOS_INLINE_FUNCTION
void runtime_check_rank_device(const size_t dyn_rank, const bool is_void_spec,
                               const size_t i0, const size_t i1,
                               const size_t i2, const size_t i3,
                               const size_t i4, const size_t i5,
                               const size_t i6, const size_t i7) {
  if (is_void_spec) {
    const size_t num_passed_args =
        count_valid_integers(i0, i1, i2, i3, i4, i5, i6, i7);

    if (num_passed_args != dyn_rank && is_void_spec) {
      Kokkos::abort(
          "Number of arguments passed to Kokkos::View() constructor must match "
          "the dynamic rank of the view.");
    }
  }
}

inline void runtime_check_rank_host(const size_t dyn_rank,
                                    const bool is_void_spec, const size_t i0,
                                    const size_t i1, const size_t i2,
                                    const size_t i3, const size_t i4,
                                    const size_t i5, const size_t i6,
                                    const size_t i7, const std::string& label) {
  if (is_void_spec) {
    const size_t num_passed_args =
        count_valid_integers(i0, i1, i2, i3, i4, i5, i6, i7);

    if (num_passed_args != dyn_rank) {
      const std::string message =
          "Constructor for Kokkos View '" + label +
          "' has mismatched number of arguments. Number of arguments = " +
          std::to_string(num_passed_args) +
          " but dynamic rank = " + std::to_string(dyn_rank) + " \n";
      Kokkos::abort(message.c_str());
    }
  }
}

} /* namespace Impl */
} /* namespace Kokkos */

// Class to provide a uniform type
namespace Kokkos {
namespace Impl {
template <class ViewType, int Traits = 0>
struct ViewUniformType;
}
}  // namespace Kokkos

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {

/** \class ViewTraits
 *  \brief Traits class for accessing attributes of a View.
 *
 * This is an implementation detail of View.  It is only of interest
 * to developers implementing a new specialization of View.
 *
 * Template argument options:
 *   - View< DataType >
 *   - View< DataType , Space >
 *   - View< DataType , Space , MemoryTraits >
 *   - View< DataType , ArrayLayout >
 *   - View< DataType , ArrayLayout , Space >
 *   - View< DataType , ArrayLayout , MemoryTraits >
 *   - View< DataType , ArrayLayout , Space , MemoryTraits >
 *   - View< DataType , MemoryTraits >
 */

template <class DataType, class... Properties>
struct ViewTraits;

template <>
struct ViewTraits<void> {
  using execution_space = void;
  using memory_space    = void;
  using HostMirrorSpace = void;
  using array_layout    = void;
  using memory_traits   = void;
  using specialize      = void;
};

template <class... Prop>
struct ViewTraits<void, void, Prop...> {
  // Ignore an extraneous 'void'
  using execution_space = typename ViewTraits<void, Prop...>::execution_space;
  using memory_space    = typename ViewTraits<void, Prop...>::memory_space;
  using HostMirrorSpace = typename ViewTraits<void, Prop...>::HostMirrorSpace;
  using array_layout    = typename ViewTraits<void, Prop...>::array_layout;
  using memory_traits   = typename ViewTraits<void, Prop...>::memory_traits;
  using specialize      = typename ViewTraits<void, Prop...>::specialize;
};

template <class ArrayLayout, class... Prop>
struct ViewTraits<
    typename std::enable_if<Kokkos::is_array_layout<ArrayLayout>::value>::type,
    ArrayLayout, Prop...> {
  // Specify layout, keep subsequent space and memory traits arguments

  using execution_space = typename ViewTraits<void, Prop...>::execution_space;
  using memory_space    = typename ViewTraits<void, Prop...>::memory_space;
  using HostMirrorSpace = typename ViewTraits<void, Prop...>::HostMirrorSpace;
  using array_layout    = ArrayLayout;
  using memory_traits   = typename ViewTraits<void, Prop...>::memory_traits;
  using specialize      = typename ViewTraits<void, Prop...>::specialize;
};

template <class Space, class... Prop>
struct ViewTraits<typename std::enable_if<Kokkos::is_space<Space>::value>::type,
                  Space, Prop...> {
  // Specify Space, memory traits should be the only subsequent argument.

  static_assert(
      std::is_same<typename ViewTraits<void, Prop...>::execution_space,
                   void>::value &&
          std::is_same<typename ViewTraits<void, Prop...>::memory_space,
                       void>::value &&
          std::is_same<typename ViewTraits<void, Prop...>::HostMirrorSpace,
                       void>::value &&
          std::is_same<typename ViewTraits<void, Prop...>::array_layout,
                       void>::value,
      "Only one View Execution or Memory Space template argument");

  using execution_space = typename Space::execution_space;
  using memory_space    = typename Space::memory_space;
  using HostMirrorSpace =
      typename Kokkos::Impl::HostMirror<Space>::Space::memory_space;
  using array_layout  = typename execution_space::array_layout;
  using memory_traits = typename ViewTraits<void, Prop...>::memory_traits;
  using specialize    = typename ViewTraits<void, Prop...>::specialize;
};

template <class MemoryTraits, class... Prop>
struct ViewTraits<typename std::enable_if<
                      Kokkos::is_memory_traits<MemoryTraits>::value>::type,
                  MemoryTraits, Prop...> {
  // Specify memory trait, should not be any subsequent arguments

  static_assert(
      std::is_same<typename ViewTraits<void, Prop...>::execution_space,
                   void>::value &&
          std::is_same<typename ViewTraits<void, Prop...>::memory_space,
                       void>::value &&
          std::is_same<typename ViewTraits<void, Prop...>::array_layout,
                       void>::value &&
          std::is_same<typename ViewTraits<void, Prop...>::memory_traits,
                       void>::value,
      "MemoryTrait is the final optional template argument for a View");

  using execution_space = void;
  using memory_space    = void;
  using HostMirrorSpace = void;
  using array_layout    = void;
  using memory_traits   = MemoryTraits;
  using specialize      = void;
};

template <class DataType, class... Properties>
struct ViewTraits {
 private:
  // Unpack the properties arguments
  using prop = ViewTraits<void, Properties...>;

  using ExecutionSpace = typename std::conditional<
      !std::is_same<typename prop::execution_space, void>::value,
      typename prop::execution_space, Kokkos::DefaultExecutionSpace>::type;

  using MemorySpace = typename std::conditional<
      !std::is_same<typename prop::memory_space, void>::value,
      typename prop::memory_space, typename ExecutionSpace::memory_space>::type;

  using ArrayLayout = typename std::conditional<
      !std::is_same<typename prop::array_layout, void>::value,
      typename prop::array_layout, typename ExecutionSpace::array_layout>::type;

  using HostMirrorSpace = typename std::conditional<
      !std::is_same<typename prop::HostMirrorSpace, void>::value,
      typename prop::HostMirrorSpace,
      typename Kokkos::Impl::HostMirror<ExecutionSpace>::Space>::type;

  using MemoryTraits = typename std::conditional<
      !std::is_same<typename prop::memory_traits, void>::value,
      typename prop::memory_traits, typename Kokkos::MemoryManaged>::type;

  // Analyze data type's properties,
  // May be specialized based upon the layout and value type
  using data_analysis = Kokkos::Impl::ViewDataAnalysis<DataType, ArrayLayout>;

 public:
  //------------------------------------
  // Data type traits:

  using data_type           = typename data_analysis::type;
  using const_data_type     = typename data_analysis::const_type;
  using non_const_data_type = typename data_analysis::non_const_type;

  //------------------------------------
  // Compatible array of trivial type traits:

  using scalar_array_type = typename data_analysis::scalar_array_type;
  using const_scalar_array_type =
      typename data_analysis::const_scalar_array_type;
  using non_const_scalar_array_type =
      typename data_analysis::non_const_scalar_array_type;

  //------------------------------------
  // Value type traits:

  using value_type           = typename data_analysis::value_type;
  using const_value_type     = typename data_analysis::const_value_type;
  using non_const_value_type = typename data_analysis::non_const_value_type;

  //------------------------------------
  // Mapping traits:

  using array_layout = ArrayLayout;
  using dimension    = typename data_analysis::dimension;

  using specialize = typename std::conditional<
      std::is_same<typename data_analysis::specialize, void>::value,
      typename prop::specialize, typename data_analysis::specialize>::
      type; /* mapping specialization tag */

  enum { rank = dimension::rank };
  enum { rank_dynamic = dimension::rank_dynamic };

  //------------------------------------
  // Execution space, memory space, memory access traits, and host mirror space.

  using execution_space   = ExecutionSpace;
  using memory_space      = MemorySpace;
  using device_type       = Kokkos::Device<ExecutionSpace, MemorySpace>;
  using memory_traits     = MemoryTraits;
  using host_mirror_space = HostMirrorSpace;

  using size_type = typename MemorySpace::size_type;

  enum { is_hostspace = std::is_same<MemorySpace, HostSpace>::value };
  enum { is_managed = MemoryTraits::is_unmanaged == 0 };
  enum { is_random_access = MemoryTraits::is_random_access == 1 };

  //------------------------------------
};

/** \class View
 *  \brief View to an array of data.
 *
 * A View represents an array of one or more dimensions.
 * For details, please refer to Kokkos' tutorial materials.
 *
 * \section Kokkos_View_TemplateParameters Template parameters
 *
 * This class has both required and optional template parameters.  The
 * \c DataType parameter must always be provided, and must always be
 * first. The parameters \c Arg1Type, \c Arg2Type, and \c Arg3Type are
 * placeholders for different template parameters.  The default value
 * of the fifth template parameter \c Specialize suffices for most use
 * cases.  When explaining the template parameters, we won't refer to
 * \c Arg1Type, \c Arg2Type, and \c Arg3Type; instead, we will refer
 * to the valid categories of template parameters, in whatever order
 * they may occur.
 *
 * Valid ways in which template arguments may be specified:
 *   - View< DataType >
 *   - View< DataType , Layout >
 *   - View< DataType , Layout , Space >
 *   - View< DataType , Layout , Space , MemoryTraits >
 *   - View< DataType , Space >
 *   - View< DataType , Space , MemoryTraits >
 *   - View< DataType , MemoryTraits >
 *
 * \tparam DataType (required) This indicates both the type of each
 *   entry of the array, and the combination of compile-time and
 *   run-time array dimension(s).  For example, <tt>double*</tt>
 *   indicates a one-dimensional array of \c double with run-time
 *   dimension, and <tt>int*[3]</tt> a two-dimensional array of \c int
 *   with run-time first dimension and compile-time second dimension
 *   (of 3).  In general, the run-time dimensions (if any) must go
 *   first, followed by zero or more compile-time dimensions.  For
 *   more examples, please refer to the tutorial materials.
 *
 * \tparam Space (required) The memory space.
 *
 * \tparam Layout (optional) The array's layout in memory.  For
 *   example, LayoutLeft indicates a column-major (Fortran style)
 *   layout, and LayoutRight a row-major (C style) layout.  If not
 *   specified, this defaults to the preferred layout for the
 *   <tt>Space</tt>.
 *
 * \tparam MemoryTraits (optional) Assertion of the user's intended
 *   access behavior.  For example, RandomAccess indicates read-only
 *   access with limited spatial locality, and Unmanaged lets users
 *   wrap externally allocated memory in a View without automatic
 *   deallocation.
 *
 * \section Kokkos_View_MT MemoryTraits discussion
 *
 * \subsection Kokkos_View_MT_Interp MemoryTraits interpretation depends on
 * Space
 *
 * Some \c MemoryTraits options may have different interpretations for
 * different \c Space types.  For example, with the Cuda device,
 * \c RandomAccess tells Kokkos to fetch the data through the texture
 * cache, whereas the non-GPU devices have no such hardware construct.
 *
 * \subsection Kokkos_View_MT_PrefUse Preferred use of MemoryTraits
 *
 * Users should defer applying the optional \c MemoryTraits parameter
 * until the point at which they actually plan to rely on it in a
 * computational kernel.  This minimizes the number of template
 * parameters exposed in their code, which reduces the cost of
 * compilation.  Users may always assign a View without specified
 * \c MemoryTraits to a compatible View with that specification.
 * For example:
 * \code
 * // Pass in the simplest types of View possible.
 * void
 * doSomething (View<double*, Cuda> out,
 *              View<const double*, Cuda> in)
 * {
 *   // Assign the "generic" View in to a RandomAccess View in_rr.
 *   // Note that RandomAccess View objects must have const data.
 *   View<const double*, Cuda, RandomAccess> in_rr = in;
 *   // ... do something with in_rr and out ...
 * }
 * \endcode
 */

}  // namespace Kokkos

namespace Kokkos {

template <class T1, class T2>
struct is_always_assignable_impl;

template <class... ViewTDst, class... ViewTSrc>
struct is_always_assignable_impl<Kokkos::View<ViewTDst...>,
                                 Kokkos::View<ViewTSrc...>> {
  using mapping_type = Kokkos::Impl::ViewMapping<
      typename Kokkos::View<ViewTDst...>::traits,
      typename Kokkos::View<ViewTSrc...>::traits,
      typename Kokkos::View<ViewTDst...>::traits::specialize>;

  constexpr static bool value =
      mapping_type::is_assignable &&
      static_cast<int>(Kokkos::View<ViewTDst...>::rank_dynamic) >=
          static_cast<int>(Kokkos::View<ViewTSrc...>::rank_dynamic);
};

template <class View1, class View2>
using is_always_assignable = is_always_assignable_impl<
    typename std::remove_reference<View1>::type,
    typename std::remove_const<
        typename std::remove_reference<View2>::type>::type>;

#ifdef KOKKOS_ENABLE_CXX17
template <class T1, class T2>
inline constexpr bool is_always_assignable_v =
    is_always_assignable<T1, T2>::value;
#endif

template <class... ViewTDst, class... ViewTSrc>
constexpr bool is_assignable(const Kokkos::View<ViewTDst...>& dst,
                             const Kokkos::View<ViewTSrc...>& src) {
  using DstTraits = typename Kokkos::View<ViewTDst...>::traits;
  using SrcTraits = typename Kokkos::View<ViewTSrc...>::traits;
  using mapping_type =
      Kokkos::Impl::ViewMapping<DstTraits, SrcTraits,
                                typename DstTraits::specialize>;

#ifdef KOKKOS_ENABLE_CXX17
  return is_always_assignable_v<Kokkos::View<ViewTDst...>,
                                Kokkos::View<ViewTSrc...>> ||
#else
  return is_always_assignable<Kokkos::View<ViewTDst...>,
                              Kokkos::View<ViewTSrc...>>::value ||
#endif
         (mapping_type::is_assignable &&
          ((DstTraits::dimension::rank_dynamic >= 1) ||
           (dst.static_extent(0) == src.extent(0))) &&
          ((DstTraits::dimension::rank_dynamic >= 2) ||
           (dst.static_extent(1) == src.extent(1))) &&
          ((DstTraits::dimension::rank_dynamic >= 3) ||
           (dst.static_extent(2) == src.extent(2))) &&
          ((DstTraits::dimension::rank_dynamic >= 4) ||
           (dst.static_extent(3) == src.extent(3))) &&
          ((DstTraits::dimension::rank_dynamic >= 5) ||
           (dst.static_extent(4) == src.extent(4))) &&
          ((DstTraits::dimension::rank_dynamic >= 6) ||
           (dst.static_extent(5) == src.extent(5))) &&
          ((DstTraits::dimension::rank_dynamic >= 7) ||
           (dst.static_extent(6) == src.extent(6))) &&
          ((DstTraits::dimension::rank_dynamic >= 8) ||
           (dst.static_extent(7) == src.extent(7))));
}

} /* namespace Kokkos */

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#include <impl/Kokkos_ViewMapping.hpp>
#include <impl/Kokkos_ViewArray.hpp>

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {

namespace {

constexpr Kokkos::Impl::ALL_t ALL = Kokkos::Impl::ALL_t();

constexpr Kokkos::Impl::WithoutInitializing_t WithoutInitializing =
    Kokkos::Impl::WithoutInitializing_t();

constexpr Kokkos::Impl::AllowPadding_t AllowPadding =
    Kokkos::Impl::AllowPadding_t();

}  // namespace

/** \brief  Create View allocation parameter bundle from argument list.
 *
 *  Valid argument list members are:
 *    1) label as a "string" or std::string
 *    2) memory space instance of the View::memory_space type
 *    3) execution space instance compatible with the View::memory_space
 *    4) Kokkos::WithoutInitializing to bypass initialization
 *    4) Kokkos::AllowPadding to allow allocation to pad dimensions for memory
 * alignment
 */
template <class... Args>
inline Impl::ViewCtorProp<typename Impl::ViewCtorProp<void, Args>::type...>
view_alloc(Args const&... args) {
  using return_type =
      Impl::ViewCtorProp<typename Impl::ViewCtorProp<void, Args>::type...>;

  static_assert(!return_type::has_pointer,
                "Cannot give pointer-to-memory for view allocation");

  return return_type(args...);
}

template <class... Args>
KOKKOS_INLINE_FUNCTION
    Impl::ViewCtorProp<typename Impl::ViewCtorProp<void, Args>::type...>
    view_wrap(Args const&... args) {
  using return_type =
      Impl::ViewCtorProp<typename Impl::ViewCtorProp<void, Args>::type...>;

  static_assert(!return_type::has_memory_space &&
                    !return_type::has_execution_space &&
                    !return_type::has_label && return_type::has_pointer,
                "Must only give pointer-to-memory for view wrapping");

  return return_type(args...);
}

} /* namespace Kokkos */

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {

template <class DataType, class... Properties>
class View;

template <class>
struct is_view : public std::false_type {};

template <class D, class... P>
struct is_view<View<D, P...>> : public std::true_type {};

template <class D, class... P>
struct is_view<const View<D, P...>> : public std::true_type {};

template <class DataType, class... Properties>
class View : public ViewTraits<DataType, Properties...> {
 private:
  template <class, class...>
  friend class View;
  template <class, class...>
  friend class Kokkos::Impl::ViewMapping;

  using view_tracker_type = Kokkos::Impl::ViewTracker<View>;

 public:
  using traits = ViewTraits<DataType, Properties...>;

 private:
  using map_type =
      Kokkos::Impl::ViewMapping<traits, typename traits::specialize>;
  template <typename V>
  friend struct Kokkos::Impl::ViewTracker;

  view_tracker_type m_track;
  map_type m_map;

 public:
  //----------------------------------------
  /** \brief  Compatible view of array of scalar types */
  using array_type =
      View<typename traits::scalar_array_type, typename traits::array_layout,
           typename traits::device_type, typename traits::memory_traits>;

  /** \brief  Compatible view of const data type */
  using const_type =
      View<typename traits::const_data_type, typename traits::array_layout,
           typename traits::device_type, typename traits::memory_traits>;

  /** \brief  Compatible view of non-const data type */
  using non_const_type =
      View<typename traits::non_const_data_type, typename traits::array_layout,
           typename traits::device_type, typename traits::memory_traits>;

  /** \brief  Compatible HostMirror view */
  using HostMirror =
      View<typename traits::non_const_data_type, typename traits::array_layout,
           Device<DefaultHostExecutionSpace,
                  typename traits::host_mirror_space::memory_space>>;

  /** \brief  Compatible HostMirror view */
  using host_mirror_type =
      View<typename traits::non_const_data_type, typename traits::array_layout,
           typename traits::host_mirror_space>;

  /** \brief Unified types */
  using uniform_type = typename Impl::ViewUniformType<View, 0>::type;
  using uniform_const_type =
      typename Impl::ViewUniformType<View, 0>::const_type;
  using uniform_runtime_type =
      typename Impl::ViewUniformType<View, 0>::runtime_type;
  using uniform_runtime_const_type =
      typename Impl::ViewUniformType<View, 0>::runtime_const_type;
  using uniform_nomemspace_type =
      typename Impl::ViewUniformType<View, 0>::nomemspace_type;
  using uniform_const_nomemspace_type =
      typename Impl::ViewUniformType<View, 0>::const_nomemspace_type;
  using uniform_runtime_nomemspace_type =
      typename Impl::ViewUniformType<View, 0>::runtime_nomemspace_type;
  using uniform_runtime_const_nomemspace_type =
      typename Impl::ViewUniformType<View, 0>::runtime_const_nomemspace_type;

  //----------------------------------------
  // Domain rank and extents

  enum { Rank = map_type::Rank };

  /** \brief rank() to be implemented
   */
  // KOKKOS_INLINE_FUNCTION
  // static
  // constexpr unsigned rank() { return map_type::Rank; }

  template <typename iType>
  KOKKOS_INLINE_FUNCTION constexpr
      typename std::enable_if<std::is_integral<iType>::value, size_t>::type
      extent(const iType& r) const noexcept {
    return m_map.extent(r);
  }

  static KOKKOS_INLINE_FUNCTION constexpr size_t static_extent(
      const unsigned r) noexcept {
    return map_type::static_extent(r);
  }

  template <typename iType>
  KOKKOS_INLINE_FUNCTION constexpr
      typename std::enable_if<std::is_integral<iType>::value, int>::type
      extent_int(const iType& r) const noexcept {
    return static_cast<int>(m_map.extent(r));
  }

  KOKKOS_INLINE_FUNCTION constexpr typename traits::array_layout layout()
      const {
    return m_map.layout();
  }

  //----------------------------------------
  /*  Deprecate all 'dimension' functions in favor of
   *  ISO/C++ vocabulary 'extent'.
   */

  KOKKOS_INLINE_FUNCTION constexpr size_t size() const {
    return m_map.dimension_0() * m_map.dimension_1() * m_map.dimension_2() *
           m_map.dimension_3() * m_map.dimension_4() * m_map.dimension_5() *
           m_map.dimension_6() * m_map.dimension_7();
  }

  KOKKOS_INLINE_FUNCTION constexpr size_t stride_0() const {
    return m_map.stride_0();
  }
  KOKKOS_INLINE_FUNCTION constexpr size_t stride_1() const {
    return m_map.stride_1();
  }
  KOKKOS_INLINE_FUNCTION constexpr size_t stride_2() const {
    return m_map.stride_2();
  }
  KOKKOS_INLINE_FUNCTION constexpr size_t stride_3() const {
    return m_map.stride_3();
  }
  KOKKOS_INLINE_FUNCTION constexpr size_t stride_4() const {
    return m_map.stride_4();
  }
  KOKKOS_INLINE_FUNCTION constexpr size_t stride_5() const {
    return m_map.stride_5();
  }
  KOKKOS_INLINE_FUNCTION constexpr size_t stride_6() const {
    return m_map.stride_6();
  }
  KOKKOS_INLINE_FUNCTION constexpr size_t stride_7() const {
    return m_map.stride_7();
  }

  template <typename iType>
  KOKKOS_INLINE_FUNCTION constexpr
      typename std::enable_if<std::is_integral<iType>::value, size_t>::type
      stride(iType r) const {
    return (
        r == 0
            ? m_map.stride_0()
            : (r == 1
                   ? m_map.stride_1()
                   : (r == 2
                          ? m_map.stride_2()
                          : (r == 3
                                 ? m_map.stride_3()
                                 : (r == 4
                                        ? m_map.stride_4()
                                        : (r == 5
                                               ? m_map.stride_5()
                                               : (r == 6
                                                      ? m_map.stride_6()
                                                      : m_map.stride_7())))))));
  }

  template <typename iType>
  KOKKOS_INLINE_FUNCTION void stride(iType* const s) const {
    m_map.stride(s);
  }

  //----------------------------------------
  // Range span is the span which contains all members.

  using reference_type = typename map_type::reference_type;
  using pointer_type   = typename map_type::pointer_type;

  enum {
    reference_type_is_lvalue_reference =
        std::is_lvalue_reference<reference_type>::value
  };

  KOKKOS_INLINE_FUNCTION constexpr size_t span() const { return m_map.span(); }
  KOKKOS_INLINE_FUNCTION bool span_is_contiguous() const {
    return m_map.span_is_contiguous();
  }
  KOKKOS_INLINE_FUNCTION constexpr bool is_allocated() const {
    return m_map.data() != nullptr;
  }
  KOKKOS_INLINE_FUNCTION constexpr pointer_type data() const {
    return m_map.data();
  }

  //----------------------------------------
  // Allow specializations to query their specialized map

  KOKKOS_INLINE_FUNCTION
  const Kokkos::Impl::ViewMapping<traits, typename traits::specialize>&
  impl_map() const {
    return m_map;
  }
  KOKKOS_INLINE_FUNCTION
  const Kokkos::Impl::SharedAllocationTracker& impl_track() const {
    return m_track.m_tracker;
  }
  //----------------------------------------

 private:
  static constexpr bool is_layout_left =
      std::is_same<typename traits::array_layout, Kokkos::LayoutLeft>::value;

  static constexpr bool is_layout_right =
      std::is_same<typename traits::array_layout, Kokkos::LayoutRight>::value;

  static constexpr bool is_layout_stride =
      std::is_same<typename traits::array_layout, Kokkos::LayoutStride>::value;

  static constexpr bool is_default_map =
      std::is_same<typename traits::specialize, void>::value &&
      (is_layout_left || is_layout_right || is_layout_stride);

#if defined(KOKKOS_ENABLE_DEBUG_BOUNDS_CHECK)

#define KOKKOS_IMPL_SINK(ARG) ARG

#define KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(ARG)                             \
  Kokkos::Impl::runtime_check_memory_access_violation<                    \
      typename traits::memory_space>(                                     \
      "Kokkos::View ERROR: attempt to access inaccessible memory space"); \
  Kokkos::Impl::view_verify_operator_bounds<typename traits::memory_space> ARG;

#else

#define KOKKOS_IMPL_SINK(ARG)

#define KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(ARG)          \
  Kokkos::Impl::runtime_check_memory_access_violation< \
      typename traits::memory_space>(                  \
      "Kokkos::View ERROR: attempt to access inaccessible memory space");

#endif

 public:
  //------------------------------
  // Rank 0 operator()

  KOKKOS_FORCEINLINE_FUNCTION
  reference_type operator()() const { return m_map.reference(); }
  //------------------------------
  // Rank 1 operator()

  template <typename I0>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0>::value &&
                               (1 == Rank) && !is_default_map),
                              reference_type>::type
      operator()(const I0& i0) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0))
    return m_map.reference(i0);
  }

  template <typename I0>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0>::value &&
                               (1 == Rank) && is_default_map &&
                               !is_layout_stride),
                              reference_type>::type
      operator()(const I0& i0) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0))
    return m_map.m_impl_handle[i0];
  }

  template <typename I0>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0>::value &&
                               (1 == Rank) && is_default_map &&
                               is_layout_stride),
                              reference_type>::type
      operator()(const I0& i0) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0))
    return m_map.m_impl_handle[m_map.m_impl_offset.m_stride.S0 * i0];
  }
  //------------------------------
  // Rank 1 operator[]

  template <typename I0>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0>::value &&
                               (1 == Rank) && !is_default_map),
                              reference_type>::type
      operator[](const I0& i0) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0))
    return m_map.reference(i0);
  }

  template <typename I0>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0>::value &&
                               (1 == Rank) && is_default_map &&
                               !is_layout_stride),
                              reference_type>::type
      operator[](const I0& i0) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0))
    return m_map.m_impl_handle[i0];
  }

  template <typename I0>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0>::value &&
                               (1 == Rank) && is_default_map &&
                               is_layout_stride),
                              reference_type>::type
      operator[](const I0& i0) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0))
    return m_map.m_impl_handle[m_map.m_impl_offset.m_stride.S0 * i0];
  }

  //------------------------------
  // Rank 2

  template <typename I0, typename I1>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1>::value &&
                               (2 == Rank) && !is_default_map),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1))
    return m_map.reference(i0, i1);
  }

  template <typename I0, typename I1>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1>::value &&
                               (2 == Rank) && is_default_map &&
                               is_layout_left && (traits::rank_dynamic == 0)),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1))
    return m_map.m_impl_handle[i0 + m_map.m_impl_offset.m_dim.N0 * i1];
  }

  template <typename I0, typename I1>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1>::value &&
                               (2 == Rank) && is_default_map &&
                               is_layout_left && (traits::rank_dynamic != 0)),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1))
    return m_map.m_impl_handle[i0 + m_map.m_impl_offset.m_stride * i1];
  }

  template <typename I0, typename I1>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1>::value &&
                               (2 == Rank) && is_default_map &&
                               is_layout_right && (traits::rank_dynamic == 0)),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1))
    return m_map.m_impl_handle[i1 + m_map.m_impl_offset.m_dim.N1 * i0];
  }

  template <typename I0, typename I1>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1>::value &&
                               (2 == Rank) && is_default_map &&
                               is_layout_right && (traits::rank_dynamic != 0)),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1))
    return m_map.m_impl_handle[i1 + m_map.m_impl_offset.m_stride * i0];
  }

  template <typename I0, typename I1>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1>::value &&
                               (2 == Rank) && is_default_map &&
                               is_layout_stride),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1))
    return m_map.m_impl_handle[i0 * m_map.m_impl_offset.m_stride.S0 +
                               i1 * m_map.m_impl_offset.m_stride.S1];
  }

  //------------------------------
  // Rank 3

  template <typename I0, typename I1, typename I2>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1, I2>::value &&
                               (3 == Rank) && is_default_map),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1, const I2& i2) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2)];
  }

  template <typename I0, typename I1, typename I2>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, I1, I2>::value &&
                               (3 == Rank) && !is_default_map),
                              reference_type>::type
      operator()(const I0& i0, const I1& i1, const I2& i2) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2))
    return m_map.reference(i0, i1, i2);
  }

  //------------------------------
  // Rank 4

  template <typename I0, typename I1, typename I2, typename I3>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3>::value && (4 == Rank) &&
       is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2, i3))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3)];
  }

  template <typename I0, typename I1, typename I2, typename I3>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3>::value && (4 == Rank) &&
       !is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2, i3))
    return m_map.reference(i0, i1, i2, i3);
  }

  //------------------------------
  // Rank 5

  template <typename I0, typename I1, typename I2, typename I3, typename I4>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4>::value && (5 == Rank) &&
       is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2, i3, i4))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4>::value && (5 == Rank) &&
       !is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2, i3, i4))
    return m_map.reference(i0, i1, i2, i3, i4);
  }

  //------------------------------
  // Rank 6

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5>::value &&
       (6 == Rank) && is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4, const I5& i5) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2, i3, i4, i5))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4, i5)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5>::value &&
       (6 == Rank) && !is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4, const I5& i5) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY((m_track, m_map, i0, i1, i2, i3, i4, i5))
    return m_map.reference(i0, i1, i2, i3, i4, i5);
  }

  //------------------------------
  // Rank 7

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6>::value &&
       (7 == Rank) && is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4, const I5& i5, const I6& i6) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        (m_track, m_map, i0, i1, i2, i3, i4, i5, i6))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4, i5, i6)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6>::value &&
       (7 == Rank) && !is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4, const I5& i5, const I6& i6) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        (m_track, m_map, i0, i1, i2, i3, i4, i5, i6))
    return m_map.reference(i0, i1, i2, i3, i4, i5, i6);
  }

  //------------------------------
  // Rank 8

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6, typename I7>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6, I7>::value &&
       (8 == Rank) && is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4, const I5& i5, const I6& i6, const I7& i7) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        (m_track, m_map, i0, i1, i2, i3, i4, i5, i6, i7))
    return m_map
        .m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4, i5, i6, i7)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6, typename I7>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6, I7>::value &&
       (8 == Rank) && !is_default_map),
      reference_type>::type
  operator()(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
             const I4& i4, const I5& i5, const I6& i6, const I7& i7) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        (m_track, m_map, i0, i1, i2, i3, i4, i5, i6, i7))
    return m_map.reference(i0, i1, i2, i3, i4, i5, i6, i7);
  }

  template <class... Args>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<Args...>::value &&
                               (0 == Rank)),
                              reference_type>::type
      access(Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, args...)))
    return m_map.reference();
  }

  template <typename I0, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, Args...>::value &&
                               (1 == Rank) && !is_default_map),
                              reference_type>::type
      access(const I0& i0, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, args...)))
    return m_map.reference(i0);
  }

  template <typename I0, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, Args...>::value &&
                               (1 == Rank) && is_default_map &&
                               !is_layout_stride),
                              reference_type>::type
      access(const I0& i0, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, args...)))
    return m_map.m_impl_handle[i0];
  }

  template <typename I0, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION
      typename std::enable_if<(Kokkos::Impl::are_integral<I0, Args...>::value &&
                               (1 == Rank) && is_default_map &&
                               is_layout_stride),
                              reference_type>::type
      access(const I0& i0, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, args...)))
    return m_map.m_impl_handle[m_map.m_impl_offset.m_stride.S0 * i0];
  }

  template <typename I0, typename I1, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, Args...>::value && (2 == Rank) &&
       !is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, args...)))
    return m_map.reference(i0, i1);
  }

  template <typename I0, typename I1, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, Args...>::value && (2 == Rank) &&
       is_default_map && is_layout_left && (traits::rank_dynamic == 0)),
      reference_type>::type
  access(const I0& i0, const I1& i1, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, args...)))
    return m_map.m_impl_handle[i0 + m_map.m_impl_offset.m_dim.N0 * i1];
  }

  template <typename I0, typename I1, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, Args...>::value && (2 == Rank) &&
       is_default_map && is_layout_left && (traits::rank_dynamic != 0)),
      reference_type>::type
  access(const I0& i0, const I1& i1, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, args...)))
    return m_map.m_impl_handle[i0 + m_map.m_impl_offset.m_stride * i1];
  }

  template <typename I0, typename I1, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, Args...>::value && (2 == Rank) &&
       is_default_map && is_layout_right && (traits::rank_dynamic == 0)),
      reference_type>::type
  access(const I0& i0, const I1& i1, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, args...)))
    return m_map.m_impl_handle[i1 + m_map.m_impl_offset.m_dim.N1 * i0];
  }

  template <typename I0, typename I1, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, Args...>::value && (2 == Rank) &&
       is_default_map && is_layout_right && (traits::rank_dynamic != 0)),
      reference_type>::type
  access(const I0& i0, const I1& i1, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, args...)))
    return m_map.m_impl_handle[i1 + m_map.m_impl_offset.m_stride * i0];
  }

  template <typename I0, typename I1, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, Args...>::value && (2 == Rank) &&
       is_default_map && is_layout_stride),
      reference_type>::type
  access(const I0& i0, const I1& i1, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, args...)))
    return m_map.m_impl_handle[i0 * m_map.m_impl_offset.m_stride.S0 +
                               i1 * m_map.m_impl_offset.m_stride.S1];
  }

  //------------------------------
  // Rank 3

  template <typename I0, typename I1, typename I2, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, Args...>::value && (3 == Rank) &&
       is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, args...)))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2)];
  }

  template <typename I0, typename I1, typename I2, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, Args...>::value && (3 == Rank) &&
       !is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, args...)))
    return m_map.reference(i0, i1, i2);
  }

  //------------------------------
  // Rank 4

  template <typename I0, typename I1, typename I2, typename I3, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, Args...>::value &&
       (4 == Rank) && is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, args...)))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3)];
  }

  template <typename I0, typename I1, typename I2, typename I3, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, Args...>::value &&
       (4 == Rank) && !is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, args...)))
    return m_map.reference(i0, i1, i2, i3);
  }

  //------------------------------
  // Rank 5

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, Args...>::value &&
       (5 == Rank) && is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, i4, args...)))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, Args...>::value &&
       (5 == Rank) && !is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, i4, args...)))
    return m_map.reference(i0, i1, i2, i3, i4);
  }

  //------------------------------
  // Rank 6

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, Args...>::value &&
       (6 == Rank) && is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         const I5& i5, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, i4, i5, args...)))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4, i5)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, Args...>::value &&
       (6 == Rank) && !is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         const I5& i5, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, i4, i5, args...)))
    return m_map.reference(i0, i1, i2, i3, i4, i5);
  }

  //------------------------------
  // Rank 7

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6, Args...>::value &&
       (7 == Rank) && is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         const I5& i5, const I6& i6, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, i4, i5, i6, args...)))
    return m_map.m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4, i5, i6)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6, Args...>::value &&
       (7 == Rank) && !is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         const I5& i5, const I6& i6, Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(
        KOKKOS_IMPL_SINK((m_track, m_map, i0, i1, i2, i3, i4, i5, i6, args...)))
    return m_map.reference(i0, i1, i2, i3, i4, i5, i6);
  }

  //------------------------------
  // Rank 8

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6, typename I7, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6, I7,
                                  Args...>::value &&
       (8 == Rank) && is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         const I5& i5, const I6& i6, const I7& i7,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(KOKKOS_IMPL_SINK(
        (m_track, m_map, i0, i1, i2, i3, i4, i5, i6, i7, args...)))
    return m_map
        .m_impl_handle[m_map.m_impl_offset(i0, i1, i2, i3, i4, i5, i6, i7)];
  }

  template <typename I0, typename I1, typename I2, typename I3, typename I4,
            typename I5, typename I6, typename I7, class... Args>
  KOKKOS_FORCEINLINE_FUNCTION typename std::enable_if<
      (Kokkos::Impl::are_integral<I0, I1, I2, I3, I4, I5, I6, I7,
                                  Args...>::value &&
       (8 == Rank) && !is_default_map),
      reference_type>::type
  access(const I0& i0, const I1& i1, const I2& i2, const I3& i3, const I4& i4,
         const I5& i5, const I6& i6, const I7& i7,
         Args... KOKKOS_IMPL_SINK(args)) const {
    KOKKOS_IMPL_VIEW_OPERATOR_VERIFY(KOKKOS_IMPL_SINK(
        (m_track, m_map, i0, i1, i2, i3, i4, i5, i6, i7, args...)))
    return m_map.reference(i0, i1, i2, i3, i4, i5, i6, i7);
  }

#undef KOKKOS_IMPL_VIEW_OPERATOR_VERIFY

  //----------------------------------------
  // Standard destructor, constructors, and assignment operators

  KOKKOS_DEFAULTED_FUNCTION
  ~View() = default;

  KOKKOS_DEFAULTED_FUNCTION
  View() = default;

  KOKKOS_DEFAULTED_FUNCTION
  View(const View&) = default;

  KOKKOS_DEFAULTED_FUNCTION
  View(View&&) = default;

  KOKKOS_DEFAULTED_FUNCTION
  View& operator=(const View&) = default;

  KOKKOS_DEFAULTED_FUNCTION
  View& operator=(View&&) = default;

  //----------------------------------------
  // Compatible view copy constructor and assignment
  // may assign unmanaged from managed.

  template <class RT, class... RP>
  KOKKOS_INLINE_FUNCTION View(
      const View<RT, RP...>& rhs,
      typename std::enable_if<Kokkos::Impl::ViewMapping<
          traits, typename View<RT, RP...>::traits,
          typename traits::specialize>::is_assignable_data_type>::type* =
          nullptr)
      : m_track(rhs), m_map() {
    using SrcTraits = typename View<RT, RP...>::traits;
    using Mapping   = Kokkos::Impl::ViewMapping<traits, SrcTraits,
                                              typename traits::specialize>;
    static_assert(Mapping::is_assignable,
                  "Incompatible View copy construction");
    Mapping::assign(m_map, rhs.m_map, rhs.m_track.m_tracker);
  }

  template <class RT, class... RP>
  KOKKOS_INLINE_FUNCTION typename std::enable_if<
      Kokkos::Impl::ViewMapping<
          traits, typename View<RT, RP...>::traits,
          typename traits::specialize>::is_assignable_data_type,
      View>::type&
  operator=(const View<RT, RP...>& rhs) {
    using SrcTraits = typename View<RT, RP...>::traits;
    using Mapping   = Kokkos::Impl::ViewMapping<traits, SrcTraits,
                                              typename traits::specialize>;
    static_assert(Mapping::is_assignable, "Incompatible View copy assignment");
    Mapping::assign(m_map, rhs.m_map, rhs.m_track.m_tracker);
    m_track.assign(rhs);
    return *this;
  }

  //----------------------------------------
  // Compatible subview constructor
  // may assign unmanaged from managed.

  template <class RT, class... RP, class Arg0, class... Args>
  KOKKOS_INLINE_FUNCTION View(const View<RT, RP...>& src_view, const Arg0 arg0,
                              Args... args)
      : m_track(src_view), m_map() {
    using SrcType = View<RT, RP...>;

    using Mapping = Kokkos::Impl::ViewMapping<void, typename SrcType::traits,
                                              Arg0, Args...>;

    using DstType = typename Mapping::type;

    static_assert(
        Kokkos::Impl::ViewMapping<traits, typename DstType::traits,
                                  typename traits::specialize>::is_assignable,
        "Subview construction requires compatible view and subview arguments");

    Mapping::assign(m_map, src_view.m_map, arg0, args...);
  }

  //----------------------------------------
  // Allocation tracking properties

  KOKKOS_INLINE_FUNCTION
  int use_count() const { return m_track.m_tracker.use_count(); }

  inline const std::string label() const {
    return m_track.m_tracker
        .template get_label<typename traits::memory_space>();
  }

  //----------------------------------------
  // Allocation according to allocation properties and array layout

  template <class... P>
  explicit inline View(
      const Impl::ViewCtorProp<P...>& arg_prop,
      typename std::enable_if<!Impl::ViewCtorProp<P...>::has_pointer,
                              typename traits::array_layout>::type const&
          arg_layout)
      : m_track(), m_map() {
    // Append layout and spaces if not input
    using alloc_prop_input = Impl::ViewCtorProp<P...>;

    // use 'std::integral_constant<unsigned,I>' for non-types
    // to avoid duplicate class error.
    using alloc_prop = Impl::ViewCtorProp<
        P...,
        typename std::conditional<alloc_prop_input::has_label,
                                  std::integral_constant<unsigned int, 0>,
                                  typename std::string>::type,
        typename std::conditional<
            alloc_prop_input::has_memory_space,
            std::integral_constant<unsigned int, 1>,
            typename traits::device_type::memory_space>::type,
        typename std::conditional<
            alloc_prop_input::has_execution_space,
            std::integral_constant<unsigned int, 2>,
            typename traits::device_type::execution_space>::type>;

    static_assert(traits::is_managed,
                  "View allocation constructor requires managed memory");

    if (alloc_prop::initialize &&
        !alloc_prop::execution_space::impl_is_initialized()) {
      // If initializing view data then
      // the execution space must be initialized.
      Kokkos::Impl::throw_runtime_exception(
          "Constructing View and initializing data with uninitialized "
          "execution space");
    }

    // Copy the input allocation properties with possibly defaulted properties
    alloc_prop prop_copy(arg_prop);

//------------------------------------------------------------
#if defined(KOKKOS_ENABLE_CUDA)
    // If allocating in CudaUVMSpace must fence before and after
    // the allocation to protect against possible concurrent access
    // on the CPU and the GPU.
    // Fence using the trait's execution space (which will be Kokkos::Cuda)
    // to avoid incomplete type errors from using Kokkos::Cuda directly.
    if (std::is_same<Kokkos::CudaUVMSpace,
                     typename traits::device_type::memory_space>::value) {
      typename traits::device_type::memory_space::execution_space().fence(
          "Kokkos::View<...>::View: fence before allocating UVM");
    }
#endif
    //------------------------------------------------------------

    Kokkos::Impl::SharedAllocationRecord<>* record =
        m_map.allocate_shared(prop_copy, arg_layout);

//------------------------------------------------------------
#if defined(KOKKOS_ENABLE_CUDA)
    if (std::is_same<Kokkos::CudaUVMSpace,
                     typename traits::device_type::memory_space>::value) {
      typename traits::device_type::memory_space::execution_space().fence(
          "Kokkos::View<...>::View: fence after allocating UVM");
    }
#endif
    //------------------------------------------------------------

    // Setup and initialization complete, start tracking
    m_track.m_tracker.assign_allocated_record_to_uninitialized(record);
  }

  KOKKOS_INLINE_FUNCTION
  void assign_data(pointer_type arg_data) {
    m_track.m_tracker.clear();
    m_map.assign_data(arg_data);
  }

  // Wrap memory according to properties and array layout
  template <class... P>
  explicit KOKKOS_INLINE_FUNCTION View(
      const Impl::ViewCtorProp<P...>& arg_prop,
      typename std::enable_if<Impl::ViewCtorProp<P...>::has_pointer,
                              typename traits::array_layout>::type const&
          arg_layout)
      : m_track()  // No memory tracking
        ,
        m_map(arg_prop, arg_layout) {
    static_assert(
        std::is_same<pointer_type,
                     typename Impl::ViewCtorProp<P...>::pointer_type>::value,
        "Constructing View to wrap user memory must supply matching pointer "
        "type");
  }

  // Simple dimension-only layout
  template <class... P>
  explicit inline View(
      const Impl::ViewCtorProp<P...>& arg_prop,
      typename std::enable_if<!Impl::ViewCtorProp<P...>::has_pointer,
                              size_t>::type const arg_N0 =
          KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N1 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N2 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N3 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N4 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N5 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N6 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N7 = KOKKOS_IMPL_CTOR_DEFAULT_ARG)
      : View(arg_prop,
             typename traits::array_layout(arg_N0, arg_N1, arg_N2, arg_N3,
                                           arg_N4, arg_N5, arg_N6, arg_N7)) {
    KOKKOS_IF_ON_HOST(
        (Impl::runtime_check_rank_host(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7, label());))
    KOKKOS_IF_ON_DEVICE(
        (Impl::runtime_check_rank_device(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7);))
  }

  template <class... P>
  explicit KOKKOS_INLINE_FUNCTION View(
      const Impl::ViewCtorProp<P...>& arg_prop,
      typename std::enable_if<Impl::ViewCtorProp<P...>::has_pointer,
                              size_t>::type const arg_N0 =
          KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N1 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N2 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N3 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N4 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N5 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N6 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N7 = KOKKOS_IMPL_CTOR_DEFAULT_ARG)
      : View(arg_prop,
             typename traits::array_layout(arg_N0, arg_N1, arg_N2, arg_N3,
                                           arg_N4, arg_N5, arg_N6, arg_N7)) {
    KOKKOS_IF_ON_HOST(
        (Impl::runtime_check_rank_host(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7, label());))
    KOKKOS_IF_ON_DEVICE(
        (Impl::runtime_check_rank_device(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7);))
  }

  // Allocate with label and layout
  template <typename Label>
  explicit inline View(
      const Label& arg_label,
      typename std::enable_if<Kokkos::Impl::is_view_label<Label>::value,
                              typename traits::array_layout>::type const&
          arg_layout)
      : View(Impl::ViewCtorProp<std::string>(arg_label), arg_layout) {}

  // Allocate label and layout, must disambiguate from subview constructor.
  template <typename Label>
  explicit inline View(
      const Label& arg_label,
      typename std::enable_if<Kokkos::Impl::is_view_label<Label>::value,
                              const size_t>::type arg_N0 =
          KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N1 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N2 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N3 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N4 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N5 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N6 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N7 = KOKKOS_IMPL_CTOR_DEFAULT_ARG)
      : View(Impl::ViewCtorProp<std::string>(arg_label),
             typename traits::array_layout(arg_N0, arg_N1, arg_N2, arg_N3,
                                           arg_N4, arg_N5, arg_N6, arg_N7)) {
    static_assert(traits::array_layout::is_extent_constructible,
                  "Layout is not extent constructible. A layout object should "
                  "be passed too.\n");

    KOKKOS_IF_ON_HOST(
        (Impl::runtime_check_rank_host(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7, label());))
    KOKKOS_IF_ON_DEVICE(
        (Impl::runtime_check_rank_device(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7);))
  }

  // Construct view from ViewTracker and map
  // This should be the preferred method because future extensions may need to
  // use the ViewTracker class.
  template <class Traits>
  KOKKOS_INLINE_FUNCTION View(
      const view_tracker_type& track,
      const Kokkos::Impl::ViewMapping<Traits, typename Traits::specialize>& map)
      : m_track(track), m_map() {
    using Mapping =
        Kokkos::Impl::ViewMapping<traits, Traits, typename traits::specialize>;
    static_assert(Mapping::is_assignable,
                  "Incompatible View copy construction");
    Mapping::assign(m_map, map, track.m_tracker);
  }

  // Construct View from internal shared allocation tracker object and map
  // This is here for backwards compatibility for classes that derive from
  // Kokkos::View
  template <class Traits>
  KOKKOS_INLINE_FUNCTION View(
      const typename view_tracker_type::track_type& track,
      const Kokkos::Impl::ViewMapping<Traits, typename Traits::specialize>& map)
      : m_track(track), m_map() {
    using Mapping =
        Kokkos::Impl::ViewMapping<traits, Traits, typename traits::specialize>;
    static_assert(Mapping::is_assignable,
                  "Incompatible View copy construction");
    Mapping::assign(m_map, map, track);
  }

  //----------------------------------------
  // Memory span required to wrap these dimensions.
  static constexpr size_t required_allocation_size(
      const size_t arg_N0 = 0, const size_t arg_N1 = 0, const size_t arg_N2 = 0,
      const size_t arg_N3 = 0, const size_t arg_N4 = 0, const size_t arg_N5 = 0,
      const size_t arg_N6 = 0, const size_t arg_N7 = 0) {
    return map_type::memory_span(typename traits::array_layout(
        arg_N0, arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7));
  }

  explicit KOKKOS_INLINE_FUNCTION View(
      pointer_type arg_ptr, const size_t arg_N0 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N1 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N2 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N3 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N4 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N5 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N6 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N7 = KOKKOS_IMPL_CTOR_DEFAULT_ARG)
      : View(Impl::ViewCtorProp<pointer_type>(arg_ptr),
             typename traits::array_layout(arg_N0, arg_N1, arg_N2, arg_N3,
                                           arg_N4, arg_N5, arg_N6, arg_N7)) {
    KOKKOS_IF_ON_HOST(
        (Impl::runtime_check_rank_host(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7, label());))
    KOKKOS_IF_ON_DEVICE(
        (Impl::runtime_check_rank_device(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7);))
  }

  explicit KOKKOS_INLINE_FUNCTION View(
      pointer_type arg_ptr, const typename traits::array_layout& arg_layout)
      : View(Impl::ViewCtorProp<pointer_type>(arg_ptr), arg_layout) {}

  //----------------------------------------
  // Shared scratch memory constructor

  static inline size_t shmem_size(const size_t arg_N0 = KOKKOS_INVALID_INDEX,
                                  const size_t arg_N1 = KOKKOS_INVALID_INDEX,
                                  const size_t arg_N2 = KOKKOS_INVALID_INDEX,
                                  const size_t arg_N3 = KOKKOS_INVALID_INDEX,
                                  const size_t arg_N4 = KOKKOS_INVALID_INDEX,
                                  const size_t arg_N5 = KOKKOS_INVALID_INDEX,
                                  const size_t arg_N6 = KOKKOS_INVALID_INDEX,
                                  const size_t arg_N7 = KOKKOS_INVALID_INDEX) {
    if (is_layout_stride) {
      Kokkos::abort(
          "Kokkos::View::shmem_size(extents...) doesn't work with "
          "LayoutStride. Pass a LayoutStride object instead");
    }
    const size_t num_passed_args = Impl::count_valid_integers(
        arg_N0, arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7);

    if (std::is_same<typename traits::specialize, void>::value &&
        num_passed_args != traits::rank_dynamic) {
      Kokkos::abort(
          "Kokkos::View::shmem_size() rank_dynamic != number of arguments.\n");
    }

    return View::shmem_size(typename traits::array_layout(
        arg_N0, arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7));
  }

  static inline size_t shmem_size(
      typename traits::array_layout const& arg_layout) {
    return map_type::memory_span(arg_layout) +
           sizeof(typename traits::value_type);
  }

  explicit KOKKOS_INLINE_FUNCTION View(
      const typename traits::execution_space::scratch_memory_space& arg_space,
      const typename traits::array_layout& arg_layout)
      : View(Impl::ViewCtorProp<pointer_type>(
                 reinterpret_cast<pointer_type>(arg_space.get_shmem_aligned(
                     map_type::memory_span(arg_layout),
                     sizeof(typename traits::value_type)))),
             arg_layout) {}

  explicit KOKKOS_INLINE_FUNCTION View(
      const typename traits::execution_space::scratch_memory_space& arg_space,
      const size_t arg_N0 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N1 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N2 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N3 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N4 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N5 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N6 = KOKKOS_IMPL_CTOR_DEFAULT_ARG,
      const size_t arg_N7 = KOKKOS_IMPL_CTOR_DEFAULT_ARG)
      : View(Impl::ViewCtorProp<pointer_type>(
                 reinterpret_cast<pointer_type>(arg_space.get_shmem_aligned(
                     map_type::memory_span(typename traits::array_layout(
                         arg_N0, arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6,
                         arg_N7)),
                     sizeof(typename traits::value_type)))),
             typename traits::array_layout(arg_N0, arg_N1, arg_N2, arg_N3,
                                           arg_N4, arg_N5, arg_N6, arg_N7)) {
    KOKKOS_IF_ON_HOST(
        (Impl::runtime_check_rank_host(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7, label());))
    KOKKOS_IF_ON_DEVICE(
        (Impl::runtime_check_rank_device(
             traits::rank_dynamic,
             std::is_same<typename traits::specialize, void>::value, arg_N0,
             arg_N1, arg_N2, arg_N3, arg_N4, arg_N5, arg_N6, arg_N7);))
  }
};

/** \brief Temporary free function rank()
 *         until rank() is implemented
 *         in the View
 */
template <typename D, class... P>
KOKKOS_INLINE_FUNCTION constexpr unsigned rank(const View<D, P...>& V) {
  return V.Rank;
}  // Temporary until added to view

namespace Impl {

template <typename ValueType, unsigned int Rank>
struct RankDataType {
  using type = typename RankDataType<ValueType, Rank - 1>::type*;
};

template <typename ValueType>
struct RankDataType<ValueType, 0> {
  using type = ValueType;
};

template <unsigned N, typename... Args>
std::enable_if_t<N == View<Args...>::Rank, View<Args...>> as_view_of_rank_n(
    View<Args...> v) {
  return v;
}

// Placeholder implementation to compile generic code for DynRankView; should
// never be called
template <unsigned N, typename T, typename... Args>
std::enable_if_t<
    N != View<T, Args...>::Rank,
    View<typename RankDataType<typename View<T, Args...>::value_type, N>::type,
         Args...>>
as_view_of_rank_n(View<T, Args...>) {
  Kokkos::Impl::throw_runtime_exception(
      "Trying to get at a View of the wrong rank");
  return {};
}

template <typename Function, typename... Args>
void apply_to_view_of_static_rank(Function&& f, View<Args...> a) {
  f(a);
}

}  // namespace Impl
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

template <class V, class... Args>
using Subview =
    typename Kokkos::Impl::ViewMapping<void /* deduce subview type from source
                                               view traits */
                                       ,
                                       typename V::traits, Args...>::type;

template <class D, class... P, class... Args>
KOKKOS_INLINE_FUNCTION
    typename Kokkos::Impl::ViewMapping<void /* deduce subview type from source
                                               view traits */
                                       ,
                                       ViewTraits<D, P...>, Args...>::type
    subview(const View<D, P...>& src, Args... args) {
  static_assert(View<D, P...>::Rank == sizeof...(Args),
                "subview requires one argument for each source View rank");

  return typename Kokkos::Impl::ViewMapping<
      void /* deduce subview type from source view traits */
      ,
      ViewTraits<D, P...>, Args...>::type(src, args...);
}

template <class MemoryTraits, class D, class... P, class... Args>
KOKKOS_INLINE_FUNCTION typename Kokkos::Impl::ViewMapping<
    void /* deduce subview type from source view traits */
    ,
    ViewTraits<D, P...>, Args...>::template apply<MemoryTraits>::type
subview(const View<D, P...>& src, Args... args) {
  static_assert(View<D, P...>::Rank == sizeof...(Args),
                "subview requires one argument for each source View rank");

  return typename Kokkos::Impl::ViewMapping<
      void /* deduce subview type from source view traits */
      ,
      ViewTraits<D, P...>,
      Args...>::template apply<MemoryTraits>::type(src, args...);
}

} /* namespace Kokkos */

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {

template <class LT, class... LP, class RT, class... RP>
KOKKOS_INLINE_FUNCTION bool operator==(const View<LT, LP...>& lhs,
                                       const View<RT, RP...>& rhs) {
  // Same data, layout, dimensions
  using lhs_traits = ViewTraits<LT, LP...>;
  using rhs_traits = ViewTraits<RT, RP...>;

  return std::is_same<typename lhs_traits::const_value_type,
                      typename rhs_traits::const_value_type>::value &&
         std::is_same<typename lhs_traits::array_layout,
                      typename rhs_traits::array_layout>::value &&
         std::is_same<typename lhs_traits::memory_space,
                      typename rhs_traits::memory_space>::value &&
         unsigned(lhs_traits::rank) == unsigned(rhs_traits::rank) &&
         lhs.data() == rhs.data() && lhs.span() == rhs.span() &&
         lhs.extent(0) == rhs.extent(0) && lhs.extent(1) == rhs.extent(1) &&
         lhs.extent(2) == rhs.extent(2) && lhs.extent(3) == rhs.extent(3) &&
         lhs.extent(4) == rhs.extent(4) && lhs.extent(5) == rhs.extent(5) &&
         lhs.extent(6) == rhs.extent(6) && lhs.extent(7) == rhs.extent(7);
}

template <class LT, class... LP, class RT, class... RP>
KOKKOS_INLINE_FUNCTION bool operator!=(const View<LT, LP...>& lhs,
                                       const View<RT, RP...>& rhs) {
  return !(operator==(lhs, rhs));
}

} /* namespace Kokkos */

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {
namespace Impl {

inline void shared_allocation_tracking_disable() {
  Kokkos::Impl::SharedAllocationRecord<void, void>::tracking_disable();
}

inline void shared_allocation_tracking_enable() {
  Kokkos::Impl::SharedAllocationRecord<void, void>::tracking_enable();
}

} /* namespace Impl */
} /* namespace Kokkos */

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

namespace Kokkos {
namespace Impl {

template <class Specialize, typename A, typename B>
struct CommonViewValueType;

template <typename A, typename B>
struct CommonViewValueType<void, A, B> {
  using value_type = typename std::common_type<A, B>::type;
};

template <class Specialize, class ValueType>
struct CommonViewAllocProp;

template <class ValueType>
struct CommonViewAllocProp<void, ValueType> {
  using value_type        = ValueType;
  using scalar_array_type = ValueType;

  template <class... Views>
  KOKKOS_INLINE_FUNCTION CommonViewAllocProp(const Views&...) {}
};

template <class... Views>
struct DeduceCommonViewAllocProp;

// Base case must provide types for:
// 1. specialize  2. value_type  3. is_view  4. prop_type
template <class FirstView>
struct DeduceCommonViewAllocProp<FirstView> {
  using specialize = typename FirstView::traits::specialize;

  using value_type = typename FirstView::traits::value_type;

  enum : bool { is_view = is_view<FirstView>::value };

  using prop_type = CommonViewAllocProp<specialize, value_type>;
};

template <class FirstView, class... NextViews>
struct DeduceCommonViewAllocProp<FirstView, NextViews...> {
  using NextTraits = DeduceCommonViewAllocProp<NextViews...>;

  using first_specialize = typename FirstView::traits::specialize;
  using first_value_type = typename FirstView::traits::value_type;

  enum : bool { first_is_view = is_view<FirstView>::value };

  using next_specialize = typename NextTraits::specialize;
  using next_value_type = typename NextTraits::value_type;

  enum : bool { next_is_view = NextTraits::is_view };

  // common types

  // determine specialize type
  // if first and next specialize differ, but are not the same specialize, error
  // out
  static_assert(!(!std::is_same<first_specialize, next_specialize>::value &&
                  !std::is_same<first_specialize, void>::value &&
                  !std::is_same<void, next_specialize>::value),
                "Kokkos DeduceCommonViewAllocProp ERROR: Only one non-void "
                "specialize trait allowed");

  // otherwise choose non-void specialize if either/both are non-void
  using specialize = typename std::conditional<
      std::is_same<first_specialize, next_specialize>::value, first_specialize,
      typename std::conditional<(std::is_same<first_specialize, void>::value &&
                                 !std::is_same<next_specialize, void>::value),
                                next_specialize, first_specialize>::type>::type;

  using value_type = typename CommonViewValueType<specialize, first_value_type,
                                                  next_value_type>::value_type;

  enum : bool { is_view = (first_is_view && next_is_view) };

  using prop_type = CommonViewAllocProp<specialize, value_type>;
};

}  // end namespace Impl

template <class... Views>
using DeducedCommonPropsType =
    typename Impl::DeduceCommonViewAllocProp<Views...>::prop_type;

// User function
template <class... Views>
KOKKOS_INLINE_FUNCTION DeducedCommonPropsType<Views...> common_view_alloc_prop(
    Views const&... views) {
  return DeducedCommonPropsType<Views...>(views...);
}

}  // namespace Kokkos

#ifdef KOKKOS_ENABLE_DEPRECATED_CODE_3
namespace Kokkos {
namespace Impl {

template <class T>
using is_view KOKKOS_DEPRECATED_WITH_COMMENT("Use Kokkos::is_view instead!") =
    Kokkos::is_view<T>;

} /* namespace Impl */
} /* namespace Kokkos */
#endif

#include <impl/Kokkos_ViewUniformType.hpp>
#include <impl/Kokkos_Atomic_View.hpp>

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

#endif /* #ifndef KOKKOS_VIEW_HPP */
