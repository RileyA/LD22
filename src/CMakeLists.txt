set(SOURCE_FILES
	main.cpp
	SDLMgr.cpp
	)

set(HEADER_FILES
	Common.h
	SDLMgr.h
	)

add_executable(LD22 ${SOURCE_FILES} ${HEADER_FILES} )
set_target_properties(LD22 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries (LD22 ${SDL_LIB} )
