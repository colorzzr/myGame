cmake_minimum_required(VERSION 2.8)

project(ZeroHero3)

set (CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-lstdc++")

add_executable(
	ZeroHero3
	main.cpp
	battle.cpp	
	bag/bagInfo.cpp
	field/field.cpp
	status/enemyStatus.cpp
	status/heroStatus.cpp
	skill/skill.cpp

)