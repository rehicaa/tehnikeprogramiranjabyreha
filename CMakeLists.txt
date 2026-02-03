cmake_minimum_required(VERSION 3.20)
project(TehnikeProgramiranja)

set(CMAKE_CXX_STANDARD 17)

# 1. Pronalazi sve main.cpp fajlove unutar ZSR foldera i njegovih podfoldera
file(GLOB_RECURSE SOURCE_FILES "ZSR/*/main.cpp")

# 2. Prolazimo kroz svaki pronađeni fajl
foreach(file ${SOURCE_FILES})
    # Dobijamo ime foldera u kojem se fajl nalazi (npr. "01" ili "15")
    get_filename_component(folder_path ${file} DIRECTORY)
    get_filename_component(folder_name ${folder_path} NAME)

    # Kreiramo ime programa na osnovu foldera (npr. zsr_01)
    set(target_name "zsr_${folder_name}")

    # Dodajemo program u projekt
    add_executable(${target_name} ${file}
            ZSR/16/main.cpp)

    # Ispis u konzolu čisto da vidiš šta je dodano (opcionalno)
    message(STATUS "Dodat target: ${target_name} iz fajla ${file}")
endforeach()