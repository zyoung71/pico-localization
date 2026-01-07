if (NOT TARGET pico-localization)

    add_library(pico-localization STATIC
        src/localization/Localizer.cpp
    )

    add_subdirectory(lib/pico-storage-device)

    target_include_directories(pico-localization PUBLIC
        include
    )

    target_link_libraries(pico-localization
        pico-storage-device
    )

endif()