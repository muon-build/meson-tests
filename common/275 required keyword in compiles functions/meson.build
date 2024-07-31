project('required keyword in compiles functions', 'c')

cc = meson.get_compiler('c')
opt = get_option('opt')

valid = files('valid.c')
invalid = files('invalid.c')

cc.compiles(valid, name: 'valid', required: true)
cc.links(valid, name: 'valid', required: true)
if meson.can_run_host_binaries()
    cc.run(valid, name: 'valid', required: true)
endif

assert(not cc.compiles(valid, name: 'valid', required: opt))
assert(not cc.links(valid, name: 'valid', required: opt))
if meson.can_run_host_binaries()
    res = cc.run(valid, name: 'valid', required: opt)
    assert(res.compiled())
    assert(res.returncode() == 0)
    assert(res.stdout() == '')
    assert(res.stderr() == '')
endif

if meson.can_run_host_binaries()
endif
