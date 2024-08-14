project('nasm only')

if host_machine.system() == 'darwin'
    # verify that /usr/bin/nasm stub on darwin actually works
    #   $ /usr/bin/nasm
    #   nasm: error: unable to find utility "nasm", not a developer tool or in PATH
    nasm = find_program('nasm', required: false)
    if not nasm.found() or run_command(nasm, '--version').returncode() == 72
        error('MESON_SKIP_TEST: nasm not found')
    endif
endif

if not add_languages('nasm', required: false)
    error('MESON_SKIP_TEST: nasm not found')
endif

if meson.backend().startswith('vs')
    error('MESON_SKIP_TEST: VS backend does not recognise NASM yet')
endif

sources = files('dummy.asm')

dummy = library(
    'dummy',
    sources,
    vs_module_defs: 'dummy.def',
)
