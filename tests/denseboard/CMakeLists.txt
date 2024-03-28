set(testTargets 
  StartEndTester.cpp
  SetGetTester.cpp
  SetAllTester.cpp
  GetDenseRangeTester.cpp
)
set(testSources
)

create_test_sourcelist(Tests 
  denseboard.cpp
  ${testTargets}
)

add_executable(DenseBoard ${Tests} ${testSources})
target_link_libraries(DenseBoard connectX_lib)

foreach (test ${testTargets})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND DenseBoard ${TName})
endforeach ()