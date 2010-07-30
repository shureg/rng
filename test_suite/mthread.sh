#!/usr/bin/env bash

rm -rf output
mkdir -p output

./mthread $1 $2 $3
