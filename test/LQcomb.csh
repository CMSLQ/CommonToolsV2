#!/bin/tcsh

# Put LQcomb.C and LQcomb.csh (make it executable) in the same directory and submit an lxbatch job
# bsub -q 1nd -o `pwd`/LQcomb.log LQcomb.csh

cd /afs/cern.ch/user/f/ferencek/scratch0/LQ/CMSSW_3_8_6/test/Leptoquarks/CommonToolsV2/test/

eval `scramv1 runtime -csh`

root -l -q LQcomb.C+\(\)

exit 0
