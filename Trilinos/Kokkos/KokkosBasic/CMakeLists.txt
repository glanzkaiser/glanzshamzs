INCLUDE_DIRECTORIES ( ./ ${Trilinos_INCLUDE_DIRS} ${Trilinos_TPL_INCLUDE_DIRS})

LINK_DIRECTORIES (${Trilinos_LIBRARY_DIRS} ${Trilinos_TPL_LIBRARY_DIRS})

MACRO(EUROTUG_ADD_TEST TEST_NAME)
  ADD_EXECUTABLE(EuroTUG_${TEST_NAME} ${TEST_NAME}.cpp)
  TARGET_LINK_LIBRARIES(EuroTUG_${TEST_NAME}
                        ${Trilinos_LIBRARIES}
                        ${Trilinos_TPL_LIBRARIES}) 
  ADD_TEST(tEuroTUG_${TEST_NAME} EuroTUG_${TEST_NAME})
ENDMACRO()

EUROTUG_ADD_TEST(hello_world)
EUROTUG_ADD_TEST(hello_world_lambda)
EUROTUG_ADD_TEST(simple_reduce)
EUROTUG_ADD_TEST(simple_reduce_lambda)
EUROTUG_ADD_TEST(simple_view)
EUROTUG_ADD_TEST(simple_view_lambda)
EUROTUG_ADD_TEST(simple_atomics)
EUROTUG_ADD_TEST(simple_memoryspaces)
