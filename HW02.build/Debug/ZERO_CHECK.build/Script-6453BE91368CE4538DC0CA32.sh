#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/irisjeong/Documents/GitHub/hw02-iris-jeong
  make -f /Users/irisjeong/Documents/GitHub/hw02-iris-jeong/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/irisjeong/Documents/GitHub/hw02-iris-jeong
  make -f /Users/irisjeong/Documents/GitHub/hw02-iris-jeong/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/irisjeong/Documents/GitHub/hw02-iris-jeong
  make -f /Users/irisjeong/Documents/GitHub/hw02-iris-jeong/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/irisjeong/Documents/GitHub/hw02-iris-jeong
  make -f /Users/irisjeong/Documents/GitHub/hw02-iris-jeong/CMakeScripts/ReRunCMake.make
fi

