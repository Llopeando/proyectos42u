#!/bin/sh
find . -type f -name "*.sh" | sed 's|.*\/\([^\.]*\)\(\..*\)$|\1|g'
