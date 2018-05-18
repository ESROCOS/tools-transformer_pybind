# Find necessary packages
find_package( PythonLibs 2.7 REQUIRED )
include_directories( ${PYTHON_INCLUDE_DIRS} )

find_package( Boost COMPONENTS python REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

#TRANSFORMER STUFF
add_library (transformer_py SHARED transformer_py.cc )
target_link_libraries( transformer_py ${Boost_LIBRARIES} )
set_target_properties( transformer_py PROPERTIES PREFIX "" )

install(FILES ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/transformer_py.so
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/python)
