project('testcase clause')

# To make sure unreachable code is not executed.
unreachable = true

# Verify assertion exception gets catched and dropped.
assert(unreachable)

# The inner testcase raises an exception because it did not receive the expected
# error message. The outer testcase catches the inner testcase exception and
# drop it.
assert(unreachable)

# The inner testcase raises an exception because it did not receive an
# exception. The outer testcase catches the inner testcase exception and
# drop it.
assert(reached)
assert(unreachable)

message('all good')
