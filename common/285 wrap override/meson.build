project('wrap override')

subproject('sub')

# sub has subsub.wrap that provides subsub-1.0 dependency. Even if sub itself
# does not use it, that dependency should now be available.
#
# different than meson: provides are scoped per-project, so this dependency
# provide won't leak outside of `sub`.
dep = dependency('subsub-1.0', required: false)
assert(not dep.found())
