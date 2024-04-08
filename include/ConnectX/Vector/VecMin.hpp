#ifndef _CONNECT_X_VECTOR_VECMIN_HPP_
#define _CONNECT_X_VECTOR_VECMIN_HPP_

#include "VecEx.hpp"

namespace ConnectX::VectorExpression {
  // Employ CRTP to upcast at compile time
  template <typename U, typename V>
  class VecMin : public VecEx<VecMin<U,V>> {
  public:
    using TU = std::conditional_t<U::Leaf, U const&, U>;
    using TV = std::conditional_t<V::Leaf, V const&, V>;

    VecMin(VecEx<U> const& u, VecEx<V> const& v)
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
      return std::min(m_u[index], m_v[index]);
    }

  private:
    TU m_u;
    TV m_v;
  };
}

namespace ConnectX {
  template <typename U, typename V>
  auto Min(ConnectX::VectorExpression::VecEx<U> const& lhs, ConnectX::VectorExpression::VecEx<V> const& rhs) {
    return ConnectX::VectorExpression::VecMin<U,V>(lhs, rhs);
  }
}

#endif // #ifndef _CONNECT_X_VECTOR_VECMIN_HPP_