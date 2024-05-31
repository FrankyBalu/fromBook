MM_SOURCES = files (
    'Game.cpp',
    'GraphicalObject.cpp',
    'Log.cpp',
    'TextureManager.cpp',
    #nur zum testen
    'Player.cpp',
    'include/Player.h',
    'Enemy.cpp',
    'include/Enemy.h'
)

MM_HEADERS = files (
    'include/BaseObject.h',
    'include/Game.h',
    'include/GraphicalObject.h',
    'include/Log.h',
    'include/ObjectParams.h',
    'include/TextureManager.h'
)

ERIK_SOURCES = files (
    'main.cpp',

)


build_args = [
]


if get_option ('buildtype') == 'debug'
    build_args += [
        '-DMULLEMAUS_DATA_DIR=../data/',
        '-DMULLEMAUS_VERSION=' + meson.project_version(),
        '-DDEBUG'
    ]
else
    build_args += [
        '-DMULLEMAUS_DATA_DIR=../data/',
        '-DMULLEMAUS_VERSION=' + meson.project_version(),
    ]
endif

Mullemaus = shared_library (
    'mullemaus',
    MM_SOURCES,
    MM_HEADERS,
    install : true,
    cpp_args: build_args,
    dependencies: PROJECT_DEP
    )

Erik = executable (
    'Erik',
    ERIK_SOURCES,
    dependencies: PROJECT_DEP,
    link_with: [ Mullemaus ]
    )
