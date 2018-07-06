#!/bin/bash

cmake .
make && ctest -V
