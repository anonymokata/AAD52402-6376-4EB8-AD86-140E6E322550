FIND_PACKAGE(Check REQUIRED)

SET(LIBS ${LIBS}
	${CHECK_LIBRARIES}
    romanNumeral
)

INCLUDE_DIRECTORIES(
	${CHECK_INCLUDE_DIRS}
	../src
)

ADD_EXECUTABLE(romanNumeralTests
    checkRomanNumeral.c
)

TARGET_LINK_LIBRARIES(romanNumeralTests ${LIBS})

ADD_UNIT_TEST(romanNumeralTests)
