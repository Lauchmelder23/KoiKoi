add_executable(koikoi 
	"main.cpp"
	"Application.cpp" 
	"Window.cpp"
 "Card.cpp")

set( RC_DEPENDS "" )

set(output ${CMAKE_BINARY_DIR}/CMakeFiles/koikoi.dir/autogen/resources.h)
set(dir ${CMAKE_SOURCE_DIR}/res)

# Create empty output file
file(WRITE ${output} "")
# Collect input files
file(GLOB bins ${dir}/*)
# Iterate through input files
foreach(bin ${bins})
    # Get short filename
    string(REGEX MATCH "([^/]+)$" filename ${bin})
    # Replace filename spaces & extension separator for C compatibility
    string(REGEX REPLACE "\\.| |-" "_" filename ${filename})
    # Read hex data from file
    file(READ ${bin} filedata HEX)
    # Convert hex data for C compatibility
    string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1," filedata ${filedata})
    # Append data to output file
    file(APPEND ${output} "const unsigned char ${filename}[] = {${filedata}};\nconst unsigned ${filename}_size = sizeof(${filename});\n")
endforeach()
set( RC_DEPENDS ${RC_DEPENDS} ${output} PARENT_SCOPE )

add_custom_target( rc ALL DEPENDS ${RC_DEPENDS} )

add_dependencies(koikoi rc)

target_include_directories(koikoi PUBLIC
	${CMAKE_SOURCE_DIR}/vendor/headeronly
	${CMAKE_BINARY_DIR}/CMakeFiles/koikoi.dir/autogen
	spdlog
	glfw
	lol
)

target_link_libraries(koikoi
	spdlog
	glfw
	lol
)