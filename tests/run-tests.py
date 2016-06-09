#!/usr/bin/env python
# run the tests a number of times, trying to find race conditions that only happen rarely
import os

def run_or_die( cmd, msg ):
    if os.system( cmd ) != 0:
        raise Exception( msg )

# main
iterations = 100
cmd = './tests'

for iteration in range( iterations ):
    msg = 'tests failed in iteration {0}'.format( iteration )
    run_or_die( cmd, msg )

