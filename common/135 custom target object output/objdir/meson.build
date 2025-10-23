# Generate an object file manually.
object = custom_target(
    'object',
    input: 'source.c',
    output: outputname,
    command: [comp, cc, cc_id, '@INPUT@', '@OUTPUT@'],
)
