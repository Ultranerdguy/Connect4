#ifndef _CONNECT_X_VECTOR_VECDIV_HPP_
#define _CONNECT_X_VECTOR_VECDIV_HPP_

#include "VecEx.hpp"
#include "VecNegate.hpp"

namespace ConnectX::VectorExpression {
  // Employ CRTP to upcast at compile time
  template <typename U, typename V>
  class VecDiv : public VecEx<VecDiv<U,V>> {
  public:
    using TU = std::conditional_t<U::Leaf, U const&, U>;
    using TV = std::conditional_t<V::Leaf, V const&, V>;

    VecDiv(VecEx<U> const& u, VecEx<V> const& v)
      : m_u(static_cast<U const&>(u))
      , m_v(static_cast<V const&>(v))
    {
      if (!U::Cycle && !V::Cycle && m_u.Size() != m_v.Size()) {
        throw; // assert
      }
    }

    static constexpr bool Leaf = false;
    static constexpr bool Cycle = U::Cycle && V::Cycle;

    auto Size() const {
      if constexpr (Cycle) return std::max(m_u.Size(), m_v.Size());
      if constexpr (V::Cycle) return m_u.Size();
      return m_v.Size();
    }

    auto operator[](std::size_t index) const {
      return m_u[index] / m_v[index];
    }

  private:
    TU m_u;
    TV m_v;
  };
}

template <typename U, typename V>
auto operator/(ConnectX::VectorExpression::VecEx<U> const& lhs, ConnectX::VectorExpression::VecEx<V> const& rhs) {
  return ConnectX::VectorExpression::VecDiv<U,V>(lhs, rhs);
}

template <ConnectX::VectorExpression::Concept::Scalar U, typename V>
auto operator/(U const& lhs, ConnectX::VectorExpression::VecEx<V> const& rhs) {
  using Scalar = ConnectX::VectorExpression::VecScalar<U>;
  return Scalar(lhs) / rhs;
}

template <typename U, ConnectX::VectorExpression::Concept::Scalar V>
auto operator/(ConnectX::VectorExpression::VecEx<U> const& lhs, V const& rhs) {
  using Scalar = ConnectX::VectorExpression::VecScalar<V>;
  return lhs / Scalar(rhs);
}

#endif // #ifndef _CONNECT_X_VECTOR_VECDIV_HPP_