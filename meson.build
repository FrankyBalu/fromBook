project(
  'Mullemaus',
  'cpp',
  default_options : ['warning_level=3', 'cpp_std=c++20', 'buildtype=debug', 'b_colorout=always', 'werror=False'],
  version : '0.0.1'
)


RAYLIB = dependency('raylib', method : 'pkg-config')
TinyXML2 = dependency('tinyxml2', method : 'pkg-config')
ZLIB = dependency('zlib', method : 'pkg-config')
LUA = dependency('lua', method : 'pkg-config')
SPDLOG = dependency('spdlog')
FMT = dependency('fmt')
PROJECT_DEP = [RAYLIB,FMT,TinyXML2,ZLIB,LUA,SPDLOG]


summary('raylib', RAYLIB.found(), section: 'Required')
summary('tinyxml2', TinyXML2.found(), section: 'Required')
summary('zlib', ZLIB.found(), section: 'Required')
summary('spdlog', SPDLOG.found(), section: 'Required')
summary('fmt', FMT.found(), section: 'Required')
summary('lua', LUA.found(), section: 'Required')


summary('Debugging', get_option('debug'), section: 'Build')
summary('Optimization', get_option('optimization'), section: 'Build')


subdir ('src')
subdir ('demo_platform')


