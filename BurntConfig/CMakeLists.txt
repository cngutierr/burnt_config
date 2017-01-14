project(BurntConfig)

set(HEADER_FILES
        BurntConfig.h
        )

set(SOURCE_FILES
        BurntConfig.cpp
        )

add_library(BurntConfig STATIC ${SOURCE_FILES} ${HEADER_FILES})