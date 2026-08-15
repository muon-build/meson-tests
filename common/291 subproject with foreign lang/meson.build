project('depfallback', 'cpp')

subp = subproject('pcre2')

lib = static_library('intlib', 'intlib.cpp', link_with: subp.get_variable('pcre2_lib'))

executable('p2test', 'p2test.cpp', link_with: lib)

# This should warn, if it doesn't we've leaked a subproject language into our
# super project
# different than meson: this has always been a hard error, so add_languages here to make this work
add_languages('c')
c = meson.get_compiler('c')
