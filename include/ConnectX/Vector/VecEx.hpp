#ifndef _CONNECT_X_VECTOR_VECEX_HPP_
#define _CONNECT_X_VECTOR_VECEX_HPP_

namespace ConnectX::VectorExpression {
  // Employ CRTP to upcast at compile time
  template <typename T>
  class VecEx {
  public:
    static constexpr bool Leaf = false;
    static constexpr bool Cycle = false;

    auto Size() const {
      return static_cast<T const&>(*this).Size();
    }

    auto operator[](std::size_t index) const {
      return static_cast<T const&>(*this).operator[](index);
    }
  };
}

#endif // #ifndef _CONNECT_X_VECTOR_VECEX_HPP_