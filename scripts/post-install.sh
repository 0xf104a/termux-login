#!/data/data/com.termux/files/usr/bin/env bash

set -e
#comment
BASEDIR=$(dirname "$0")
cd $BASEDIR
cp data/login $PREFIX/bin/login
cp data/motd $PREFIX/etc/motd
if  [ ! $# -gt 0 ] || [ !  $1 = "--update" ] ; then

  echo Now lets create first user
  echo -n "Username:"
  read user
  adduser $user
fi
