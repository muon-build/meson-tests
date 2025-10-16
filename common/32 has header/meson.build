project('has header', 'c', 'cpp')

host_system = host_machine.system()

non_existent_header = 'ouagadougou.h'

# Copy it into the builddir to ensure that it isn't found even if it's there
configure_file(
    input: non_existent_header,
    output: non_existent_header,
    configuration: configuration_data(),
)

# different than meson: muon never uses __has_include in the comp.has_header
# check.  undefining it breaks some libc's e.g. llvm's libc++ uses it
# unconditionally:
# https://github.com/llvm/llvm-project/blob/1d5bd289062748c89bb9f3f88d0f804972185e93/libcxx/include/__configuration/platform.h#L48
fallbacks = ['']

foreach fallback : fallbacks
    foreach comp : [meson.get_compiler('c'), meson.get_compiler('cpp')]
        assert(comp.has_header('stdio.h', prefix: fallback), 'Stdio missing.')

        # stdio.h doesn't actually need stdlib.h, but just test that setting the
        # prefix does not result in an error.
        assert(
            comp.has_header('stdio.h', prefix: '#include <stdlib.h>' + fallback),
            'Stdio missing.',
        )

        # XInput.h should not require type definitions from windows.h, but it does
        # require macro definitions. Specifically, it requires an arch setting for
        # VS2015 at least.
        # We only do this check on MSVC because MinGW often defines its own wrappers
        # that pre-include windows.h
        if comp.get_id() == 'msvc'
            assert(
                comp.has_header('XInput.h', prefix: '#include <windows.h>' + fallback),
                'XInput.h should not be missing on Windows',
            )
            assert(
                comp.has_header('XInput.h', prefix: '#define _X86_' + fallback),
                'XInput.h should not need windows.h',
            )
        endif

        # Test that the following GCC bug doesn't happen:
        # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=80005
        # https://github.com/mesonbuild/meson/issues/1458
        if host_system == 'linux'
            assert(
                comp.has_header('linux/if.h', prefix: fallback),
                'Could not find <linux/if.h>',
            )
        endif

        # This header exists in the source and the builddir, but we still must not
        # find it since we are looking in the system directories.
        assert(
            not comp.has_header(non_existent_header, prefix: fallback),
            'Found nonexistent header.',
        )
    endforeach
endforeach
