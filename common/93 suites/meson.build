project('multiple test suites', 'c')

subproject('sub')

add_test_setup('regular', is_default: true, exclude_suites: ['super-special', 'suite4'])
add_test_setup('fancy', exclude_suites: ['suite3', 'suite5'])

exe1 = executable('exe1', 'exe1.c')
exe2 = executable('exe2', 'exe2.c')
exe3 = executable('exe3', 'exe2.c')
exe4 = executable('exe4', 'exe2.c')
exe5 = executable('exe5', 'exe2.c')
exe6 = executable('exe6', 'exe2.c')

test('exe1', exe1) # not in any suite
test('exe2', exe2, suite: ['suite2', ['super-special']])
test('exe3', exe3, suite: ['suite3'])
test('exe4', exe4, suite: ['suite4'])
test('exe5', exe5, suite: ['suite5'])
test('exe6', exe6) # not in any suite
