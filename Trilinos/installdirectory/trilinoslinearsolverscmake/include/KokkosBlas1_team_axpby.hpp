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

#ifndef KOKKOSBLAS1_TEAM_AXPBY_HPP_
#define KOKKOSBLAS1_TEAM_AXPBY_HPP_

#include <KokkosBlas1_team_axpby_spec.hpp>

namespace KokkosBlas {
namespace Experimental {

template <class TeamType, class XVector, class YVector>
void KOKKOS_INLINE_FUNCTION
axpby(const TeamType& team, const typename XVector::non_const_value_type& a,
      const XVector& x, const typename YVector::non_const_value_type& b,
      const YVector& y) {
  return Impl::TeamAXPBY<TeamType, XVector, YVector>::team_axpby(team, a, x, b,
                                                                 y);
}

template <class TeamType, class XVector, class YVector>
void KOKKOS_INLINE_FUNCTION
axpy(const TeamType& team, const typename XVector::non_const_value_type& a,
     const XVector& x, const YVector& y) {
  KokkosBlas::Experimental::axpby<TeamType, XVector, YVector>(
      team, a, x,
      Kokkos::Details::ArithTraits<
          typename YVector::non_const_value_type>::one(),
      y);
}

}  // namespace Experimental
}  // namespace KokkosBlas

#endif
