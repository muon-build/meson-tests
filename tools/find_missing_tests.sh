#!/bin/sh

set -eu

muon setup -Dprint-tests=true build \
	| grep '^note ' \
	| sed 's/^note //g' \
	| sort > build/defined_in_meson.build.txt

find . -type f -maxdepth 3 -mindepth 3 -name 'meson.build' \
	| sed 's|\./\(.*\)/meson.build|\1|g' \
	| sort > build/exist_in_repo.txt

git diff --no-index build/defined_in_meson.build.txt build/exist_in_repo.txt
