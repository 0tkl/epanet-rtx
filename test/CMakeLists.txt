find_package(Boost REQUIRED unit_test_framework)

add_executable( epanetrtx-test
#   MyClientTest.cpp
#   test_influx.cpp
	test_main.cpp
	test_units.cpp
	test_record.cpp )

set_target_properties(epanetrtx-test PROPERTIES CXX_STANDARD 17)

target_include_directories(epanetrtx-test PUBLIC
    ../src
    ${CMAKE_CURRENT_SOURCE_DIR}
    Boost::unit_test_framework
)

target_link_libraries(epanetrtx-test
    epanetrtx
    oatpp::oatpp-test
    Boost::unit_test_framework
)

add_test( NAME epanetrtx-test COMMAND epanetrtx-test )
