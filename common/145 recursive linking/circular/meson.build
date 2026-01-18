st1 = static_library('st1', 'lib1.c', 'prop1.c')
st2 = static_library('st2', 'lib2.c', 'prop2.c')
st3 = static_library('st3', 'lib3.c', 'prop3.c')

link_args = []

if meson.get_compiler('c').get_id() == 'tcc'
    # tcc workaround for circular dependency resolution in static libs
    link_args += ['-Wl,--whole-archive']
endif

test(
    'circular',
    executable(
        'circular',
        'main.c',
        link_with: [st1, st2, st3],
        link_args: link_args,
    ),
)
