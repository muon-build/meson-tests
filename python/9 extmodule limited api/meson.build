project(
    'Python limited api',
    'c',
    default_options: ['buildtype=release', 'werror=true'],
)

py_mod = import('python')
py = py_mod.find_installation()

ext_mod_limited = py.extension_module(
    'limited',
    'limited.c',
    limited_api: '3.7',
    install: true,
)

ext_mod = py.extension_module(
    'not_limited',
    'not_limited.c',
    install: true,
)

test(
    'load-test',
    py,
    args: [files('test_limited.py')],
    env: {'PYTHONPATH': meson.current_build_dir()},
    workdir: meson.current_source_dir(),
)
