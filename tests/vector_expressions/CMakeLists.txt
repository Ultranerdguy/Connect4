set(testTargets 
  VecExEqualTester.cpp
  VecExInequalTester.cpp
  VecExNotTester.cpp
  VecExNotEqualTester.cpp
  VecExSumTester.cpp
  VecExNegateTester.cpp
  VecExSubtractTester.cpp
  VecExMulTester.cpp
  VecExDivTester.cpp
  VecExScalarTester.cpp
  VecExChainedOperationTester.cpp
  VecExMinMaxTester.cpp
)

set(testSources
)

create_test_sourcelist(Tests 
  vecex.cpp
  ${testTargets}
)

add_executable(VectorExpressions ${Tests} ${testSources})
target_link_libraries(VectorExpressions connectX_lib)

foreach (test ${testTargets})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND VectorExpressions ${TName})
endforeach ()