add_executable(tests tests.cpp sdu_controllers_t.cpp)
target_link_libraries(tests PUBLIC sdu_controllers Catch2::Catch2)

add_executable(rnea_test rnea_test.cpp)
target_link_libraries(rnea_test PUBLIC sdu_controllers Catch2::Catch2)

add_executable(ur5e_inv_dyn_comparison ur5e_inv_dyn_comparison.cpp)
target_link_libraries(ur5e_inv_dyn_comparison PUBLIC sdu_controllers Catch2::Catch2)

# allow user to run tests with `make test` or `ctest`
catch_discover_tests(tests)
