#!/bin/bash
git pull --recurse-submodules
git submodule update --init --recursive
git submodule update --remote --recursive