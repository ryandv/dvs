#!/bin/bash

cmake .
make && CTEST_OUTPUT_ON_FAILURE=1 make test
