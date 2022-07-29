#!/bin/sh
git log --pretty=oneline | cut -d ' ' -f 1 | head -n 5
