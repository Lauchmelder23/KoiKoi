add_executable(koikoi 
	"main.cpp"
	"Application.cpp" 
	"Window.cpp"
 )

target_include_directories(koikoi PRIVATE
	spdlog
	glfw
)

target_link_libraries(koikoi PRIVATE
	spdlog
	glfw
)