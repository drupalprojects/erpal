#!/bin/sh

TAG="$1"
CLEAN_URL="$2"
DUMP_URL="$3"

if [ -z "$TAG" -o -z "${CLEAN_URL}" -o -z "${DUMP_URL}" ]
then
	echo "Error, need TAG, CLEAN_URL and DUMP_URL arguments..."
	exit 1
fi


SNAPSHOTS_BRANCH=snapshots
PATHS_TO_ADD="docs sql"

prepare() 
{
	if ! git show-ref "refs/heads/$SNAPSHOTS_BRANCH" --quiet --verify
	then
		echo "Creating snapshots branch '$SNAPSHOTS_BRANCH'..."
		git branch "$SNAPSHOTS_BRANCH"
	fi

	git checkout "${SNAPSHOTS_BRANCH}"
}

reset() 
{
	git reset --hard
	git clean -d -f
}

die()
{
	echo "Error: $@"
	reset
	exit 1
}

add_paths() 
{
	local path

	for path in $@
	do
		test -e "$path" && git add "$path"
	done
}

prepare

git merge --no-ff master

wget --spider "${CLEAN_URL}" || die "Cannot clean"
wget --spider "${DUMP_URL}" || die "Cannot create database dump"

add_paths ${PATHS_TO_ADD}

git commit -a -m "Preparing for Tag ${TAG}"
git tag -a "${TAG}" -m "Tagging ${TAG}"

git push --tags origin "${SNAPSHOTS_BRANCH}"
