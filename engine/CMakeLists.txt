add_library(koikoiengine STATIC 
	"Game.cpp"
	"Card.cpp"
	"CardStack.cpp"
	"Board.cpp"
)

target_include_directories(koikoiengine PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)