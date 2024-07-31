project(
    'environment',
    meson_version: '>=1.4.0',
)

testenv = find_program(files('testenv.py'))

env = environment()
env.unset('foo')
test('not set', testenv, args: ['foo'], env: env)

env1 = environment('foo=bar', method: 'append', separator: ':')
env1.append('foo', 'baz', separator: ':')
test('append', testenv, args: ['foo', 'bar:baz'], env: env1)

env2 = environment(['foo=baz'], method: 'prepend', separator: ':')
env2.prepend('foo', 'bar', separator: ':')
test('prepend', testenv, args: ['foo', 'bar:baz'], env: env2)

env3 = environment({'foo': 'foobar'}, method: 'set', separator: ':')
env3.set('foo', 'qux')
test('reset', testenv, args: ['foo', 'qux'], env: env3)
