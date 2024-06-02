DEMO_SOURCES = files (
    'main.cpp',
    'MenuScene.cpp',
    'MenuScene.h',
    'PlayScene.cpp',
    'PlayScene.h',
    'Player.cpp',
    'Player.h',
    'GameOver.cpp',
    'GameOver.h',
    'PausMenu.cpp',
    'PausMenu.h'
)

if get_option ('buildtype') == 'debug'
    build_args += [
        '-DMULLEMAUS_DATA_DIR="' + meson.source_root() + '/data/"',
        '-DMULLEMAUS_VERSION=' + meson.project_version(),
        '-DDEBUG'
    ]
endif

Demo = executable (
    'Demo',
    DEMO_SOURCES,
    dependencies: PROJECT_DEP,
    cpp_args: build_args,
    link_with: [ Mullemaus ]
    )
