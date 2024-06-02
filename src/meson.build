MM_SOURCES = files (
    'Game.cpp',
    'GraphicalBaseObject.cpp',
    'Log.cpp',
    'TextureManager.cpp',
    'InputManager.cpp',
    'SceneManager.cpp',
)

MM_HEADERS = files (
    'include/BaseObject.h',
    'include/Game.h',
    'include/GraphicalBaseObject.h',
    'include/Log.h',
    'include/ObjectParams.h',
    'include/TextureManager.h',
    'include/Vector2D.h',
    'include/InputManager.h',
    'include/SceneManager.h'
)




build_args = [
]


if get_option ('buildtype') == 'debug'
    build_args += [
        '-DMULLEMAUS_DATA_DIR="' + meson.source_root() + '/data/"',
        '-DMULLEMAUS_VERSION=' + meson.project_version(),
        '-DDEBUG'
    ]
else
    build_args += [
        '-DMULLEMAUS_DATA_DIR=\"' + meson.source_root() + '/data/\"', #fixme: daten dir auf installationsverzeichnis setzen
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
