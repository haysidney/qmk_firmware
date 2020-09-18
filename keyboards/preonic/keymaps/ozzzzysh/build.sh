#!/bin/sh
#qmk compile -kb preonic/rev3 -km ozzzzysh -j8 --output-sync

cd ../../../..
make preonic/rev3:ozzzzysh -j8 --output-sync
